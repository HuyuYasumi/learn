#-*-coding:utf-8-*-

def findMinAndMax(l):
    if len(l) == 0:
        return (None, None)
    else:
        minint = l[0]
        maxint = l[0]
        for y in range(1, len(l)):
            if maxint < l[y]:
                maxint = l[y]
            if minint > l[y]:
                minint = l[y]
        return (minint, maxint)

# 测试
if findMinAndMax([]) != (None, None):
    print('测试失败!#1')
elif findMinAndMax([7]) != (7, 7):
    print('测试失败!#2')
elif findMinAndMax([7, 1]) != (1, 7):
    print('测试失败!#3')
elif findMinAndMax([7, 1, 3, 9, 5]) != (1, 9):
    print('测试失败!#4')
elif findMinAndMax([4, 2, 7]) != (2, 7):
    print('测试失败!#5')
elif findMinAndMax([3]) != (3, 3):
    print('测试失败!#6')
else:
    print('测试成功!')
