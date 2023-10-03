import base64
import time
from confluent_kafka import Producer
from PIL import Image

# 初始化 Producer
p = Producer({'bootstrap.servers': 'YOUR_BOOTSTRAP_SERVERS'})

# 設定 topic
topic = 'YOUR_TOPIC'

def delivery_report(err, msg):
    if err is not None:
        print(f'Message delivery failed: {err}')
    else:
        print(f'Message delivered to {msg.topic()} [{msg.partition()}]')

for i in range(30):
    # 讀取 png 圖片並轉換為 base64
    with open(f'image_{i}.png', 'rb') as f:
        img = base64.b64encode(f.read()).decode()

    # 產生訊息
    p.produce(topic, value=img, callback=delivery_report)
    
    # 等待所有訊息被送出
    p.flush()

    # 每秒送出 30 張圖片
    time.sleep(1/30)
