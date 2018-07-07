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

# Input string to be set to Arduino Uno. Wait for same number of
# bytes sent to come back from serial input buffer. Read bytes
# from buffer and print to terminal.
while True:
    # Input string to send to Arduino Uno.
    inputString = bytes(input("Enter string to send to Arduino Uno: "), 'ascii')

    # If user inputs "EXIT", exit from while loop.
    if (inputString == "EXIT"):
        break

    # Send string to Arduino Uno over serial.
    ser.write(inputString)

    # Wait until the same number of bytes sent is recieved.
    while (ser.inWaiting() < len(inputString)):
        pass

    #Read string in serial input buffer.
    outputString = ser.read(len(inputString))

    # Print string recieved from arduino uno.
    print("String recieved from Arduino Uno: ", outputString)
