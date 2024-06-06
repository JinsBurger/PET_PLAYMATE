#!/usr/bin/python3
import asyncio
import websockets
import threading
import cv2
import base64
import json
import numpy as np
import time

HOSTNAME = "0.0.0.0"
PORT = 8888

class VideoWorker(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)
        self.loop = asyncio.get_event_loop()
        self.cap = cv2.VideoCapture(0)
        self.cap.set(3, 640)
        self.cap.set(4, 480)
        self.SEND_DELAY = 0.1
        self.recv_img_queue = []
        self.websockets = []


    def run(self):
        while True:
            if len(self.websockets):
                ret, img = self.cap.read()
                if ret:
                    ret, img = cv2.imencode('.png', img)
                    if ret:
                        res = base64.b64encode(img).decode()
                        coro = self.websockets[-1].send(json.dumps({'image':res}))
                        future = asyncio.run_coroutine_threadsafe(coro,loop)
                        time.sleep(self.SEND_DELAY)



    async def handler(self, websocket, path):
        self.websockets.append(websocket)
        while True:
            try:
                data = await websocket.recv()
                #img = self.img_queue.pop(0)
                img = base64.b64decode(json.loads(data)["image"].split("base64,")[1])
                cc = cv2.imdecode(np.frombuffer(img, np.int8), cv2.IMREAD_COLOR)
                cv2.imshow('image', cc)
                cv2.waitKey(1)


            except websockets.exceptions.ConnectionClosed:
                print("Socket Closed")
                break

            except Exception as e:
                print(e)
                pass
        self.websockets.pop(self.websockets.index(websocket))


if __name__ == '__main__':
    worker = VideoWorker()
    server = websockets.serve(worker.handler, HOSTNAME, PORT)
    worker.start()
    loop = asyncio.get_event_loop()
    loop.run_until_complete(server)
    loop.run_forever()

    
