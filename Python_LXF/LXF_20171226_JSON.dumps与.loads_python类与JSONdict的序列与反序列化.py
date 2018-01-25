# -*- coding: utf-8 -*-
import json

class Student(object):
    def __init__(self, name, age, score):
        self.name = name
        self.age = age
        self.score = score

def student2dict(stu):
    return {
            'name': stu.name,
            'age': stu.age,
            'score': stu.score,
    }

def dict2student(d):
    return Student(d['name'], d['age'], d['score'])

s = Student('小明', 19, 88)
d = json.dumps(s, default = student2dict, ensure_ascii = False)
#dumps提供的ensure_ascii参数可控制中文的写入方式
#default也可传入lambda obj: obj.__dict__
#因为通常class的实例都有一个__dict__属性，它就是一个dict，用来存储实例变量。也有少数例外，比如定义了__slots__的class。
print(d)
s2 = json.loads(d, object_hook = dict2student)
print(s2.name, s2.age, s2.score)
