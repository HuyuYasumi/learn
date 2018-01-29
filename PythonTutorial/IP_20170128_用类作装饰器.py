from functools import wraps

class logit(object):
    def __init__(self, logfile = 'out.log'):
        self.logfile = logfile

    def __call__(self, func):
        @wraps(func)
        def wrapped_function(*args, **kwargs):
            log_string = func.__name__ + ' was called'
            print(log_string + '\n' + self.logfile + ' was writed')
            self.notify()
            return func(*args, **kwargs)
        return wrapped_function

    def notify(self):
        pass

class email_logit(logit):
    def __init__(self, logfile='out.log', email='admmin@myproject.com', *args, **kwargs):
        self.email = email
        self.logfile = logfile

    def notify(self):
        print(self.email + ' was open')

@logit()
def myfunc():
    pass

@email_logit(logfile = 'log2.log', email = 'your@me.com')
def myfunc2():
    pass

myfunc()
myfunc2()
