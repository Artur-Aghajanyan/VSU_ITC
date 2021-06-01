class Add:
    def __init__(self, num1, num2):
        self._num1 = num1
        self._num2 = num2

    def add(self):
        a = self._num1 + self._num2
        return a

class Calculator(Add):

    def __init__(self, num1, num2):
        super().__init__(num1,num2)

    def addition(self):
        return self.add()

    def subtract(self):
        s = self._num1 - self._num2
        return s

    def multiply(self):
        m = self._num1 * self._num2
        return m

    def divide(self):
        try:
            d = self._num1 / self._num2
            return d
        except ZeroDivisionError:
            return "You can't divide by zero!"
calc2 = Calculator(4,5)


print(calc2.subtract())
print(calc2.multiply())
print(calc2.divide())
print(calc2.addition())
