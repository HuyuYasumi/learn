def a_new_decorator(a_func):
    def wrapTheFunction():
        print('I am doing some boring work before executing a_func()')
        a_func()
        print('I am doing some boring work after executing a_func()')

    return wrapTheFunction

def a_func_requiring_decoration():
    print ('I am the function which needs some decoration to remove my foul smell')

a_func_requiring_decoration = a_new_decorator(a_func_requiring_decoration)
a_func_requiring_decoration()
print(a_func_requiring_decoration.__name__)

print('\nor\n')

@a_new_decorator    #装饰器只能在定义函数时使用
def a_func_requiring_decoration():
    print ('I am the function which needs some decoration to remove my foul smell')
a_func_requiring_decoration()
print(a_func_requiring_decoration.__name__)
