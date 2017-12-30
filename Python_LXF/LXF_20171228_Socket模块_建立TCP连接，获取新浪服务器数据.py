import socket

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    #AF_INET指定IPv4，AF_IENT6指定IPv6
    s.connect(('www.sina.com.cn', 80))
    #传入ip地址与端口
    s.send(b'GET / HTTP/1.1\r\nHost: www.sina.com.cn\r\nConnection: close\r\n\r\n')

    buffer = []
    while True:
        d = s.recv(1024)    #传入每次最多接受的字节数
        if d:
            buffer.append(d)
        else:
            break

data = b''.join(buffer)
header, html = data.split(b'\r\n\r\n', 1)
print(header.decode('utf-8'))
with open(r'F:\learn\Python_LXF\Python_temp\sian.html', 'wb') as f:
    f.write(html)
