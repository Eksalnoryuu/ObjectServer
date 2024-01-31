import os
from kivy.app import App
from kivy.uix.label import Label
from kivy.uix.floatlayout import FloatLayout
from kivy.core.window import Window
import zmq
from enum import Enum

class Topic(Enum):
    ADD_NEW_FILE = 0
    REQUEST_FILE = 1

topicToStringMap = {
    Topic.ADD_NEW_FILE: "ADD_NEW_FILE",
    Topic.REQUEST_FILE: "REQUEST_FILE",
}

class ObjectClient:
    def __init__(self, address):
        self.context = zmq.Context()
        self.socket = self.context.socket(zmq.PUB)
        self.address = address

    def connect(self):
        self.socket.connect(self.address)

    def send_file(self, topic, file_name, message):
        print(file_name)
        self.socket.send_multipart([bytes(topic, 'utf-8'),bytes(file_name, 'utf-8'), bytes(message, 'utf-8')])

class FileDropApp(App):
    def build(self):
        self.root = FloatLayout()

        self.fileLabel = Label(text='Drop text files here!', pos_hint={'center_x': 0.5, 'center_y': 0.5})
        self.root.add_widget(self.fileLabel)

        Window.bind(on_dropfile=self.onFileDrop)

        self.object_client = ObjectClient("tcp://127.0.0.1:9090")
        self.object_client.connect()

        return self.root

    def onFileDrop(self, window, file_path):
        try:
            if file_path.lower().endswith(bytes('.obj', "utf-8")):
                with open(file_path, 'r') as file:
                    topic = topicToStringMap.get(Topic.ADD_NEW_FILE)
                    file_name = os.path.splitext(os.path.basename(file.name))[0]
                    file_content = file.read()
                file_name_str = file_name.decode('utf-8') if isinstance(file_name, bytes) else file_name
                self.object_client.send_file(str(topic), file_name_str, str(file_content))
            else:
                self.fileLabel.text = 'Only .obj files are supported!'
        except Exception as e:
            print(e)

if __name__ == "__main__":
    FileDropApp().run()
