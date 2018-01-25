def count():
    fs = []
    for i in range(1, 4):
        def f():
            return i*i
        fs.append(f)
    return fs

#返回函数引用变量i，但它并非立刻执行。等3个函数都被加到元祖25fs时，它们所引用的变量i都已经变成3，因此3个结果都为9
f1, f2, f3 = count()
print(f1(), f2(), f3())


def count2():
    def f(j):
        def g():
            return j*j
        return g

    fs = []
    for i in range(1, 4):
        fs.append(f(i))
    return fs

#利用函数f的参数绑定循环变量当前的值，无论该循环变量后续如何改变，已绑定到函数参数的值不变
f4, f5, f6 = count2()
print(f4(), f5(), f6())
