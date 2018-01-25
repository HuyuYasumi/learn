from functools import reduce

fn = lambda x, y: x * 10 + y
def switch(s):
    digits = {'0':0, '1':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9}
    return digits[s]

#输入整数字符串返回整数
def str2int(l):
    return reduce(fn, map(switch, l))

print(str2int('953146'))

#输入字符串序列，首字母大写，其它小写
def normalize(name):
    return list(map(lambda x: x[0].upper() + x[1:].lower(), name))

print(normalize(['adam', 'LISA']))

#输入数字序列返回乘积
def prod(L):
    return reduce(lambda x, y: x * y, L)

print(prod([3, 5, 7]))


#输入小数字符串返回浮点数
def str2float(s):
    i = 0

    for i in range(0 , len(s)):
        if s[i] == '.':
            break

    return reduce(fn, map(switch, s[0:i])) + (reduce(lambda x, y: x / 10 + y, map(switch, s[-1:-(len(s)-i):-1]))) / 10

print(str2float('234.567555'))
