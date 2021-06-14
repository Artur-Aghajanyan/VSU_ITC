from abc import ABC, abstractmethod

class Animals(ABC):
    def __init__(self, weight, name, maleFemale):
        self._weight = str(weight) + " (Kg)"
        self._name = name
        self._maleFemale = maleFemale
    @abstractmethod
    def voice(ABC):
        pass

class Terrestrial(Animals):
    def __init__(self, name, weight, maleFemale):
        self._typeAnimals = "Terrestrial"
        super().__init__(weight, name, maleFemale)
    def voice(ABC):
        print("Gaf gaf")

    def printTerrestrialAnimals(self):
        print("***********\n")
        print("Type animal - ", self._typeAnimals)
        print("Name - ", self._name)
        print("Weight - ", self._weight)
        print("Male or Female - ", self._maleFemale)
        print("Animal Voice: ")
        self.voice()
        print("***********\n")

class Water(Animals):
    def __init__(self, name, weight, maleFemale):
        self._typeAnimals = "Water"
        super().__init__(weight, name, maleFemale)
    def voice(ABC):
        print("Not voice!!")

    def printWaterAnimals(self):
        print("***********\n")
        print("Type animal - ", self._typeAnimals)
        print("Name - ", self._name)
        print("Weight - ", self._weight)
        print("Male or Female - ", self._maleFemale)
        print("Animal Voice: ")
        self.voice()
        print("***********\n")

dog = Terrestrial("Dog", 3, "male")
dog.printTerrestrialAnimals()

dog = Water("Fish", 3, "male")
dog.printWaterAnimals()

