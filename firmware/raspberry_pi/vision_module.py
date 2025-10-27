import cv2
import time

def dummy_detector(frame):
    # simple motion/contour detector placeholder
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    blur = cv2.GaussianBlur(gray, (5,5), 0)
    _, th = cv2.threshold(blur, 60, 255, cv2.THRESH_BINARY)
    contours, _ = cv2.findContours(th, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    detections = []
    for c in contours:
        area = cv2.contourArea(c)
        if area > 500:
            x,y,w,h = cv2.boundingRect(c)
            detections.append({'bbox': (x,y,w,h), 'area': area})
    return detections

class VisionModule:
    def __init__(self, src=0):
        self.src = src
        self.cap = cv2.VideoCapture(self.src)
    def run(self):
        while True:
            ret, frame = self.cap.read()
            if not ret:
                time.sleep(0.1); continue
            dets = dummy_detector(frame)
            yield dets

if __name__ == '__main__':
    v = VisionModule()
    for d in v.run():
        print(d)
