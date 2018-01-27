class SchoolMember:
    '''代表学校里的成员'''
    def __init__(self, name, age):
        self.name = name
        self.age = age
        print('(Initialized SchoolMember: {})'.format(self.name))

    # self.age='testing'

    def tell(self):
        print('Name:"{}" Age:"{}"'.format(self.name, self.age), end=' ')

class Teacher():
    '''代表一位老师'''
    def __init__(self, name, age, salary):
        SchoolMember.__init__(self, name, age)
        self.salary = salary
        print('(Initialized Teacher: {})'.format(self.name))

    def tell(self):
        SchoolMember.tell(self)
        print('Salary:"{:d}"'.format(self.salary))

class Student(SchoolMember):
    '''代表一位学生'''
    def __init__(self, name, age, marks):
        SchoolMember.__init__(self, name, age)
        # Teacher.__init__(self, name, age, marks)
        self.marks = marks
        print('(Initialized Student: {})'.format(self.name))

    def tell(self):
        SchoolMember.tell(self)
        print('Salary:"{:d}"'.format(self.marks))
        # Teacher.tell(self)

t = Teacher('Mrs.Shrividya', 40, 30000)
s = Student('Swaroop', 25, 75)

members = [t, s]
for member in members:
    member.tell()

# print(t.salary, t.name)
# print(s.name)

class Student2(object):
    def __init__(self, name, gender):
        self.__name = name
        self.__gender = gender

    def set_gender(self, gender):
        self.__gender = gender

    def get_gender(self):
        # print(self.__gender)
        return self.__gender

# 测试:
bart = Student2('Bart', 'male')
if bart.get_gender() != 'male':
    print('测试失败!')
else:
    bart.set_gender('female')
    if bart.get_gender() != 'female':
        print('测试失败!')
    else:
        print('测试成功!')
