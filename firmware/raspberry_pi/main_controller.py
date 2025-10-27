#!/usr/bin/env python3
import argparse
import time
import threading
import serial

from vision_module import VisionModule

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--port', default='/dev/ttyUSB0')
    parser.add_argument('--baud', default=115200, type=int)
    args = parser.parse_args()

    vision = VisionModule()
    ser = serial.Serial(args.port, args.baud, timeout=1)

    def vision_loop():
        for detection in vision.run():
            print('DETECT', detection)
            # send simple commands to Arduino: "left,right\n"
            # placeholder: map detection to motor commands
            ser.write(b"100,100\n")

    t = threading.Thread(target=vision_loop, daemon=True)
    t.start()
    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        print('Shutting down')
