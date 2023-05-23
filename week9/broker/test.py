#!/usr/bin/env python3
import paho.mqtt.client as mqtt


def on_connect(client, userdata, flags, rc):
    print(f"Terkoneksi dengan klien {rc}")
    client.subscribe("test-topic")


def on_message(client, userdata, msg):
    print(f"Message received [{msg.topic}]: {msg.payload}")


client = mqtt.Client("mqtt-test")

client.on_connect = on_connect
client.on_message = on_message

# client.username_pw_set("test", "srikandi")
client.connect("127.0.0.1", 1883)
client.loop_forever()  # Start networking daemon
