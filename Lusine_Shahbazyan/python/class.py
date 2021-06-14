class Person:
    __count = 0

    def __init__(self, name, age):
        self._name = name
        self._age = age
        Person.__count += 1

    @classmethod
    def classData(cls, name, age):
        return cls(name,age)

    def getName(self):
        return self._name
    def getAge(self):
        return self._age
    
    @staticmethod
    def getPersonCount():
        return Person.__count

class Programmer(Person):
    def __init__(self, name, age, profession, salary, company):
        super().__init__(name, age)
        self._company = company
        self._profession = profession
        self._salary = salary
        
    def getCompany(self):
        return self._company
    def getProfession(self):
        return self._profession
    def getSalary(self):
        return self._salary

class Teacher(Person):
    def __init__(self, name, age, profession, salary, school):
        super().__init__(name, age)
        self._school = school
        self._profession = profession
        self._salary = salary
        
    def getSchool(self):
        return self._school
    def getProfession(self):
        return self._profession
    def getSalary(self):
        return self._salary


person1 = Programmer("Davit", 25, "frontend developer", 500000,"Omnicode")
person2 = Teacher("Mary", 32, "mathematic", 200000, 20)
person3 = Person("Areg", 20)

print("person1's name: ", person1.getName())
print("person1's age: ", person1.getAge())
print("person1's profession: ", person1.getProfession())
print("person1's salary : ", person1.getSalary())
print("person1's company: ", person1.getCompany())
print("\n")
print("person2's name: ", person2.getName())
print("person2's age: ", person2.getAge())
print("person2's profession: ", person2.getProfession())
print("person2's salary : ", person2.getSalary())
print("person2's school: ", person2.getSchool())
print("\n")
print("class method: ",person3.getAge())
print("class method: ",person3.getName())
print("Staticmethod: ",Person.getPersonCount())



