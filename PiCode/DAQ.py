import serial
import sys

# Incomplete filepath to file where serial data is stored.
# The missing part is the port number at the end of the string.
portname_start = '/dev/ttyACM'

# Scan through serial ports 0-9 and attempt to openself.
for i in range (0,10):
    # Convert i to a string.
    portnum = str(i)

    # Append port number to end of portname_start.
    portname_full = ''.join([portname_start,portnum])

    # Attempt to open serial port i, increment if failure occurs.
    # If no serial port is found print error and exit.
    try:
        ser = serial.Serial(portname_full, 9600, timeout=1)
        break
    except:
        if (i ==9):
            print("No Serial Port Found")
            sys.exit(0)



