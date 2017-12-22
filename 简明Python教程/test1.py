import sys
age=17
name='Ore'
print('{} was {} years old.'.format(name, age), end=' ')
print('{0:_^11}'.format(name), 1)

running=True

def say(message, times=1):
    print(message*times)

# while running:
    # number=int(input('Enter an integer:'))
    # if age == number:
        # say('Congratulations, you guessed it.\n')
        # running=False
    # elif age < number:
        # say(number, message='No, it is a little highter than that.\n')
    # else :
        # say('No, it is a little lower than that.\n', number)
# else:
    # print('The while loop is over.')

# maxint=int(input('Enter an integer:'))
# for i in range(1, maxint):
    # print(i)
# else:
    # print('The for loop is over')

# print(dir(age))
# print(dir(name))
# print(dir(format))
# print(dir(say))
# print(dir(sys))

if sys.__name__ == '__main__':
    print('sys')
if __name__ == '__main__':
    print('this')

class Person:
    def __init__(self, name='Hello'):
        self.name=name
    def say_hi(self):
        print('Hellw, how are you?', self.name)
    def say_hello(self):
        print('Hi, how are you?', self.name)
    name='Hi'
    def say_mother(self):
        print(self.name, 'How are you')

p = Person()
p.say_hi()
p.say_hello()
print(p.name)
p.say_mother()
