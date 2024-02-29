import serial
import time
import time
import os 

os.chdir(os.path.dirname(os.path.abspath(__file__)))


def readBytesArray(serObj, arrayLen=43):
    data = []
    for i in range(arrayLen):
        msg = read14orMoreBitMsg(serObj)
        data.append(msg)
    # print(data)
    return data

def read14orMoreBitMsg(serObj):
    msg = 0
    b = int.from_bytes(serObj.read(1),'big')
    byteArray = [b]

    while ((b >> 7) & 1):
        b = int.from_bytes(serObj.read(1),'big')
        byteArray.append(b)

    for i, byte in enumerate(reversed(byteArray)):
        byte = byte & ~(1<<7)
        msg = msg | (byte << (i*7))
    if msg > 50000:
        msg = msg - 65536
    return msg



if __name__ == "__main__":
    # Get user inputs for log time, file name, and port
    time_to_log = input("Time to log: ")
    file_name = input("File name: ")
    port = "/dev/ttyACM0"

    # Build file name and print
    file_name = file_name + str(time_to_log) + "_" + str(int(time.time())) + ".csv"
    print(file_name)

    # Create serial port interface object
    ser = serial.Serial(port, 115200, timeout=1)
    
    # Get start time and end time
    print('starting logging')
    time_start = time.time()
    time_end = time_start + int(time_to_log)
    
    # Create new file and begin logging
    with open(file_name,"w") as f:
        ser.write(b'a')
        while True:
                try:
                    if (time.time() > time_end):
                        print('time is up, terminating')
                        break
                    
                    # Read messages and write them to a csv
                    dataArray = readBytesArray(ser, arrayLen=43)
                    dataStr = ', '.join(map(str, dataArray))
                    f.write(''.join([dataStr,'\n']))

                except KeyboardInterrupt:
                    print('ok, ok, terminating now...')
                    break
                
                except IndexError:
                    print("Index Error")
                    continue
    print("Done")