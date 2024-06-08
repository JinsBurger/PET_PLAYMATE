import cv2
import time

#thres = 0.45 # Threshold to detect object

classNames = []
classFile = "./coco.names"
with open(classFile,"rt") as f:
    classNames = f.read().rstrip("\n").split("\n")

configPath = "./ssd_mobilenet_v3_large_coco_2020_01_14.pbtxt"
weightsPath = "./frozen_inference_graph.pb"

net = cv2.dnn_DetectionModel(weightsPath,configPath)
net.setInputSize(320,320)
net.setInputScale(1.0/ 127.5)
net.setInputMean((127.5, 127.5, 127.5))
net.setInputSwapRB(True)


def getObjects(img, thres, nms, draw=True, objects=[]):
    classIds, confs, bbox = net.detect(img,confThreshold=thres,nmsThreshold=nms)
    #print(classIds,bbox)
    if len(objects) == 0: objects = classNames
    objectInfo =[]
    if len(classIds) != 0:
        for classId, confidence,box in zip(classIds.flatten(),confs.flatten(),bbox):
            className = classNames[classId - 1]
            if className in objects:
                objectInfo.append([box,className])
                if (draw):
                    print(box)
                    print((box[0], box[1]))

    return img,objectInfo


if __name__ == "__main__":

    cap = cv2.VideoCapture(0)
    cap.set(3,640)
    cap.set(4,480)
    #cap.set(10,70)


    while True:
        success, img = cap.read()
        result, objectInfo = getObjects(img,0.45,0.25, objects=['dog'])
        #print(objectInfo)
        '''
        cv2.imshow("Output",img)
        cv2.waitKey(1)
        '''
        time.sleep(0.3)
