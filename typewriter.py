#!/usr/bin/env python3
import serial
import time
import sys

def write_to_serial(port):
    try:
        ser = serial.Serial(port, 9600)
        time.sleep(2)
    except serial.SerialException:
        print(f"Error: Could not open serial port {port}.")
        return

    while True:
        try:
            line = sys.stdin.readline()
            if not line:
                break
            ser.write(line.encode())
            response = ser.readline()
        except KeyboardInterrupt:
            break

    ser.close()

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: ./script.py SERIAL_DEVICE")
        sys.exit(1)

    write_to_serial(sys.argv[1])
