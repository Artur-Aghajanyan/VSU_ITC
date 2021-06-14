class MyClass1:
    public_var = 0
    _protected_var = 0
    __private_var = 0

    def __init__(self, var1, var2, var3):
        self.public_var = var1
        self._protected_var = var2
        self.__private_var = var3

    @staticmethod
    def static_method(x, y):
        return x + y

    @classmethod
    def class_method(cls, var1, var2, var3):
        public_var = var1
        _protected_var = var2
        __private_var = var3

    #Objext specific method
    def object_method(self, var1, var2, var3):
        self.public_var = var1
        self._protected_var = var2
        self.__private_var = var3

    def print_vars(self):
        print(self.public_var, self._protected_var, self.__private_var)

    def func1(self):
        print("Func1 from Class1")

    def func2(self):
        print("Func2 from Class1")


class MyClass2:
    def __init__(self):
        pass

    def func1(self):
        print("Func1 from Class2")

    def func2(self):
        print("Func2 from Class2")


obj1 = MyClass1(1, 2, 3)
obj2 = MyClass2()
MyClass1.static_method(5, 12)
obj1.print_vars()
obj1.class_method(4, 5, 6)
obj1.print_vars()
obj1.object_method(7, 8, 9)
obj1.print_vars()

#polymorfizm
for obj in (obj1, obj2):
    obj.func1()
    obj.func1()
    
