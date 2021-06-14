from class1 import MyClass1


class MyClass2(MyClass1):
    def __init__(self, var1, var2, var3):
        super().__init__(var1, var2, var3)


obj1 = MyClass2(1, 2, 3)

