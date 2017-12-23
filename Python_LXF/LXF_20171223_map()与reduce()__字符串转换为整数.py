from functools import reduce

def str2int(l):
    def fn(x, y):
        return x * 10 + y

    def switch(s):
        digits = {'0':0, '1':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9}
        return digits[s]

    return reduce(fn, map(switch, l))

print(str2int('953146'))


