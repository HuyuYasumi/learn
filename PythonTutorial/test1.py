from functools import wraps

class logit(object):
    def __init__(self, logfile = 'out.log'):
        self.logfile = logfile

    def __call__(self, func):
        @wraps(func)
        def wrapped_function(*args, **kwargs):
            log_string = func.__name__ + ' was called'
            print(log_string)
            print(self.logfile, 'now was write')
            self.notify()
            return func(*args, **kwargs)
        return wrapped_function()

    def notify(self):
        pass

@logit()
def myfunc():
    pass

class email_logit(logit):
    def __init__(self, email='admmin@myproject.com', *args, **kwargs):
        self.email = email

    def notify(self):
        pass
