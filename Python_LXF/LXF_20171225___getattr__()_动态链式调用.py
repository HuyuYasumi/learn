class Chain():
    def __init__(self, path = ''):
        self._path = path
    def __getattr__(self, path):
        a = Chain('%s/%s' % (self._path, path))    #调试用
        print(a)
        return a
    def __str__(self):
        return self._path
    __repr__ = __str__

print(Chain().status.user.timeline.list)
