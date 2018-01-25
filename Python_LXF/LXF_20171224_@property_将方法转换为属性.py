class Screen():
    """我的理解是：@property接收的方法不该有self以外的参数且必须有返回值，因为即使有其他参数也无法使用；@XXX.setter接受的方法需要self以外的参数，且不该有返回值"""
    @property
    def width(self):
        return self.__width
    @width.setter
    def width(self, value):
        self.__width = value

    @property
    def height(self):
        return self.__height
    @height.setter
    def height(self, value):
        self.__height = value

    @property
    def resolution(self):
        return self.__width * self.__height

# 测试:
s = Screen()
s.width = 1024
s.height = 768
print('resolution =', s.resolution)
if s.resolution == 786432:
    print('测试通过!')
else:
    print('测试失败!')
