import time

def log(func):
    def wrapper(*args, **kw):
        print('call {}:'.format(func.__name__))
        return func(*args, **kw)

    return wrapper

@log
def now():
    print(time.strftime('%Y%m%d'))

now()


def log2(text):
    def decorator(func):
        def wrapper(*args, **kw):
            print('{0} {1}:'.format(text, func.__name__))
            return func(*args, **kw)

        return wrapper

    return decorator

@log2('execute')
def now():
    print(time.strftime('%Y%m%d'))

now()
