from abc import ABC, abstractmethod

class Phone(ABC):
    __company = None
    __price = None
    __serialNumber = None
    __color = None
    
    @abstractmethod
    def __init__(self):
        pass


class Android(Phone):
    __model = None
    def __init__(self,company,model,price,serialNumber,color):
        self.__model = model
        self._Phone__company = company
        self._Phone__price = price
        self._Phone__serialNumber = serialNumber
        self._Phone__color = color

    def get_platform():
        return "Android"

    def getModel(self):
        return self.__model

    def getCompany(self):
        return self._Phone__company
    
    def __str__(self):
        return self.getCompany() + ' : ' + str(self.getModel()) +'  ::'+  str(self._Phone__serialNumber)+'  ::'+  str(self._Phone__color)+'  ::'+  str(self._Phone__price)    


class IOS(Phone):
    __model = None
    def __init__(self,company,model,price,serialNumber,color):
        self.__model = model
        self._Phone__company = company
        self._Phone__price = price
        self._Phone__serialNumber = serialNumber
        self._Phone__color = color

    def get_platform():
        return "IOS"

    def getModel(self):
        return self.__model

    def getCompany(self):
        return self._Phone__company
    
    def __str__(self):
        return self.getCompany() + ' : ' + str(self.getModel()) +'  ::'+  str(self._Phone__serialNumber)+'  ::'+  str(self._Phone__color)+'  ::'+  str(self._Phone__price)    


def addPhone(lst,platform,company, model, serialNumber,color,price):
    if platform == "Android":
        lst.append(Android(company, model, serialNumber,color,price))
        return lst
    elif platform == "IOS":
        lst.append(IOS(company, model, serialNumber,color,price))
        return lst  





lst = []

x = 'y'
while x == 'y':
    platform = input('Enter the platform of the Phone (Android or IOS): ')
    
    if not platform == "IOS" and not platform == "Android":
        print("Please write phone platform correctly (Android or IOS)")
        exit()

    company = input('Enter the company name of the Phone: ')
    model = input('Enter the model: ')
    serialNumber = input('Enter the model serial number: ')
    price = input('price: ')
    color = input('color: ')
    lst = addPhone(lst,platform, company, model, serialNumber,color,price)
    x = input('Another Phone? y/n: ')

n = 1
print("---The list of the phone that store have---")

for item in lst:
    print(n,'. ', item)
    n = n + 1