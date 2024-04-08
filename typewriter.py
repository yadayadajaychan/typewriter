#!/usr/bin/env python3
import serial
import time
import sys

def open_serial(port):
    try:
        ser = serial.Serial(port, 9600, serial.EIGHTBITS, serial.PARITY_EVEN, serial.STOPBITS_TWO, 5)
        return ser
    except serial.SerialException:
        print(f"Error: Could not open serial port {port}.")
        return

def wait_until_ready(ser):
    while ser.readline() != b'READY\r\n':
        time.sleep(0.1)

def write_char(ser, ch):
    ser.write(ch.encode())
    return ser.readline()

def write_to_serial(port):
    # open serial port
    ser = open_serial(port)
    if not ser:
        return

    wait_until_ready(ser)

    while True:
        try:
            ch = sys.stdin.read(1)
            if not ch:
                break

            response = write_char(ser, ch)

            retries = 0
            while response != b'OK\r\n' and retries < 3:
                retries += 1
                print("NO RESPONSE FROM SERIAL PORT")
                print(f"RETRYING ({retries}/3)...")
                ser.close()
                ser = open_serial(port)
                if not ser:
                    return
                wait_until_ready(ser)
                response = write_char(ser, ch)

        except KeyboardInterrupt:
            break

    ser.close()

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: ./script.py SERIAL_DEVICE")
        sys.exit(1)

    write_to_serial(sys.argv[1])
