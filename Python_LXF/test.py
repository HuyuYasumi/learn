from functools import reduce

def str2num(s):
    return int(s)

def calc(exp):
    ss = exp.split('+')
    ns = map(str2num, ss)
    return reduce(lambda acc, x: acc + x, ns)

def main():
    r = calc('100 + 200 + 345')
    print('100 + 200 + 345 =', r)
    try:
        r = calc('99 + 88 + 7.6')
    except Exception as e:
        print(e)
    else:
        print('99 + 88 + 7.6 =', r)
    finally:
        print('finally...')

main()
