def createCounter():
    fs = [0]    # 初始化为一个元素0的列表
    def counter():
        fs[0] = fs[0]+1    # 使用下标递增该元素的值
        return fs[0]

    return counter

# 如果给函数不使用列表fs进行<fs=[0]操作，而是用整数变量i即进行<i=0>操作。那将会导致程序错误：
# def createCounter():
    # i = [0]    # 初始化为一个元素0的列表
    # def counter():
        # i = i+1    # 使用下标递增该元素的值
        # return i

    # return counter
#原因在于，python会因为你对i在函数counter内进行了赋值操作而把i作为函数counter的局部变量，而运行<i+1>时i未初始化。

# 测试:
counterA = createCounter()
print(counterA(), counterA(), counterA()) # 1 2 3
counterB = createCounter()
if [counterB(), counterB(), counterB()] == [1, 2, 3]:
    print('测试通过!')
else:
    print('测试失败!')

