#Qustion:
#编写一个程序，能在当前目录以及当前目录的所有子目录下查找文件名包含指定字符串的文件，并打印出相对路径。

import os

def ffile(mpath, mfile):
    for x in os.listdir(mpath):
        if os.path.isfile(os.path.join(mpath, x)):
            if mfile in x:
                print(os.path.join(mpath, x))
        else:
            ffile(os.path.join(mpath, x), mfile)

ffile('.', mfile = input('What you want to search? -->'))

