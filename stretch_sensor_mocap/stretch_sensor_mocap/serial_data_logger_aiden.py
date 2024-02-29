import serial
import time
import time
import os 

os.chdir(os.path.dirname(os.path.abspath(__file__)))

def read3BytesArray(serObj,arrayLen=25):
    numBytes = 2
    data = []
    for i in range(arrayLen):
        msg = serObj.read(numBytes)
        a = (msg[0] << 16) | (msg[1] << 8) | msg[2]
        if a > 50000:
            a = a - 65536
        data.append(a)
        
    return data


if __name__ == "__main__":
    time_to_log = input("Time to log: ")
    file_name = input("File name: ")
    port = "/dev/ttyACM0"
    # time_to_log = 60
    file_name = file_name + str(time_to_log) + "_" + str(int(time.time())) + ".csv"
    print(file_name)

    ser = serial.Serial(port, 115200, timeout=1)

    #for x in range(0, 5):
    #    ser_bytes = ser.readline()
    print('starting logging')
    time_start = time.time()
    time_end = time_start + int(time_to_log)

    with open(file_name,"w") as f:
        ser.write(b'a')
        while True:
            try:
                if (time.time() > time_end):
                    print('time is up, terminating')
                    break
                dataArray = read3BytesArray(ser, arrayLen=29)
                dataStr = ', '.join(map(str, dataArray))
                print(dataStr)
                f.write(''.join([dataStr,'\n']))

            except KeyboardInterrupt :
                print('ok, ok, terminating now...')
                break
            
            except IndexError:
                print("Index Error")
                continue

        print("Done")