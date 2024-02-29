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

# def readByte(serObj):
#     msg = 0
#     b = int.from_bytes(serObj.read(1),'big')
    

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
    port = "/dev/ttyACM0"


    # Create serial port interface object
    ser = serial.Serial(port, 115200, timeout=1)
    ser.write(b'a')

    while True:
            try:
                if ser.in_waiting > 0:
                    # Read messages and write them to a csv
                    dataArray = readBytesArray(ser, arrayLen=29)
                    # dataStr = ', '.join(map(str, dataArray))
                    print(dataArray)
            except KeyboardInterrupt:
                print('ok, ok, terminating now...')
                break
            
            except IndexError:
                print("Index Error")
                continue
    print("Done")