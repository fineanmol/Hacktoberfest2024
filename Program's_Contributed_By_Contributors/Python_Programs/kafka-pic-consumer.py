import base64
from confluent_kafka import Consumer, KafkaError
from PIL import Image
import io

# 初始化 Consumer
c = Consumer({
    'bootstrap.servers': 'YOUR_BOOTSTRAP_SERVERS',
    'group.id': 'YOUR_GROUP_ID',
    'auto.offset.reset': 'earliest'
})

# 設定 topic
c.subscribe(['YOUR_TOPIC'])

while True:
    msg = c.poll(1.0)

    if msg is None:
        continue
    if msg.error():
        if msg.error().code() == KafkaError._PARTITION_EOF:
            continue
        else:
            print(msg.error())
            break

    # 將 base64 轉換回圖片並顯示
    img = Image.open(io.BytesIO(base64.b64decode(msg.value().decode())))
    img.show()

c.close()
