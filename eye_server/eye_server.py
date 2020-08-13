#!/usr/bin/env python3

import socket
import serial

HOST = '0.0.0.0'  # Standard loopback interface address (localhost)
PORT = 4781        # Port to listen on (non-privileged ports are > 1023)

ser = serial.Serial('/dev/ttyACM0',115200)  # open serial port

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    while(True):
        s.listen()
        conn, addr = s.accept()
        with conn:
            print('Connected by', addr)
            while True:
                data = conn.recv(1024)
                if not data:
                    break
                print(data)
                ser.write(data)
