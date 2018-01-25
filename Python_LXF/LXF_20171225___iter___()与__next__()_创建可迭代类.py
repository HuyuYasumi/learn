class Fib():
    def __init__(self):
        self.a, self.b = 0, 1

    def __iter__(self):
        return self

    def __next__(self):
        self.a, self.b = self.b, self.a + self.b
        if self.a > 10000:
            raise StopIteration()
        return self.a

fib = Fib()
#首先，for调用fib.__iter__()寻找被返回的迭代对象（这里是fib自身），之后重复调用该对象的__next__方法
for n in fib:
    print(n)
