import serial


class ArduinoComm:
    def __init__(self, port):
        self.port = port
        self.comm = serial.Serial(self.port, 9000)
        self.comm.flushInput()

    def send(self, data):
        self.comm.write(data)
