#-*-coding:utf-8-*-

class Student():
    '''使用Student.getcount()获取当前学生数量'''
    count = 0
    def __init__(self, name):
        self.name = name
        Student.count += 1

    @classmethod
    def getcount(self):
        print(Student.count)
        return Student.count

Marry = Student('Marry')
Jack = Student('Jack')
Student.getcount()
