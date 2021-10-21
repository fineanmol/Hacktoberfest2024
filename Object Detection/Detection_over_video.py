import cv2 as cv
import numpy as np
import os
import sys

config_file = (r'D:\HACK\Hacktoberfest2021\Object Detection\Coco\ssd_mobilenet_v3_large_coco_2020_01_14.pbtxt')
frozen_model = (r'D:\HACK\Hacktoberfest2021\Object Detection\Coco\frozen_inference_graph.pb')
out = cv.VideoWriter('Result.mp4', cv.VideoWriter_fourcc(*'m', 'p', '4', 'v'), 20, (700, 500))


model = cv.dnn_DetectionModel(frozen_model, config_file)

classLabels = []
file_name = (r'D:\HACK\Hacktoberfest2021\Object Detection\Labels.txt')
with open(file_name, 'rt') as fpt:
    classLabels = fpt.read().rstrip('\n').split('\n')

# print(classLabels)

capture = cv.VideoCapture(0)
while True:
    isTrue, img = capture.read()
    width, height = 700, 500
    img = cv.resize(img, (width, height))

    model.setInputSize(320, 320)
    model.setInputScale(1.0 / 127.5)
    model.setInputMean((127.5, 127.5, 127.5))
    model.setInputSwapRB(True)

    ClassIndex, confidence, bbox = model.detect(img, confThreshold=0.5)
    if len(ClassIndex) != 0:
        for ClassInd, conf, boxes in zip(ClassIndex.flatten(), confidence.flatten(), bbox):
            if (ClassInd <= 80):
         
                cv.rectangle(img, boxes, (255, 0, 0), 2)
                cv.putText(img, classLabels[int(ClassInd - 1)], (boxes[0] + 10, boxes[1] + 40), cv.FONT_HERSHEY_PLAIN,
                           3, color=(255, 0, 0), thickness=3)

        out.write(img)
        cv.imshow('Video', img)
        
        if cv.waitKey(1) & 0xFF == 27:
            break
capture.release()
out.release()
capture.destroAllWindows
