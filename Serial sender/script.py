import serial
import time
import psutil
# arduino = serial.Serial('COM6', 9600)
# print('hI')
# time.sleep(2)
# print('hI')
# print(arduino.readline())
# print('hI')
# print("CPU usage to arduino")
# print('hI')

while 1:
      print('hI')
#     print(psutil.cpu_percent())
#     cpu_load=(str(psutil.cpu_percent()))
#     print(type(cpu_load))
#     #arduino.write(cpu_load.encode())
#     #print(arduino.read())
#     print('go to sleep')
      print ("Start : %s" % time.ctime())
      time.sleep( 1 )
      print ("End : %s" % time.ctime())
    # print('wake up')
    # print(psutil.virtual_memory())  # physical memory usage
    # print('memory % used:', psutil.virtual_memory()[2])
    # os.system('wmic cpu get loadpercentage')
        #print(datafromUser)
    # CPU_Pct=str(round(float(os.popen('''grep 'cpu ' /proc/stat | awk '{usage=($2+$4)*100/($2+$4+$5)} END {print usage }' ''').readline()),2))
    # print(CPU_Pct)

    # !/usr/bin/env python


#     # gives a single float value
#     psutil.cpu_percent()
#     # gives an object with many fields
#     psutil.virtual_memory()
#     # you can convert that object to a dictionary
#     a=dict(psutil.virtual_memory()._asdict())
#     print(psutil.cpu_percent())
# time.sleep(10)


#     arduino.write(datafromUser.encode())
#     print(arduino.read())
#     print(type(datafromUser))




# import serial
# import time
# import os
#
# arduino = serial.Serial('COM6', 9600)
# time.sleep(2)
# print(arduino.readline())
# print("CPU usage to arduino")
#
# while 1:



    # datafromUser = (input())
    #
    # if int(datafromUser) > 1:
    #     print(datafromUser)
    #     arduino.write(datafromUser.encode())
    #     print(arduino.read())
    #     print(type(datafromUser))
    # time.sleep(1)
