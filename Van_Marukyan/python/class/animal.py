
class Animals:
    def __init__(self, name, weidht, height, maleFemale):
        self._weidht = str(weidht) + " (kg)"
        self._height = str(height) + " (metr)"
        self._name = name
        self._maleFemale = maleFemale

class Terrestrial(Animals):
    def __init__(self, name, weidht, height, maleFemale):
        self._typeAnimals = "Terrestrial"
        super().__init__(name, weidht, height, maleFemale)

    def printTerrestrialAnimals(self):
        print("\n")
        print("Type animal - ", self._typeAnimals)
        print("Name - ", self._name)
        print("Weidht - ", self._weidht)
        print("Height - ", self._height)
        print("Male or Female - ", self._maleFemale)

class Reptile(Animals):
    def __init__(self, name, weidht, height,  maleFemale):
        self._typeAnimals = "Reptile"
        super().__init__(name, weidht, height, maleFemale)

    def printReptileAnimals(self):
        print("\n")
        print("Type animal - ", self._typeAnimals)
        print("Name - ", self._name)
        print("Weidht - ", self._weidht)
        print("Height - ", self._height)
        print("Male or Female - ", self._maleFemale)
        print("\n")

animal = Terrestrial("Lion", 60, 1, "male")
animal.printTerrestrialAnimals()

reptile = Reptile("Kobra", 20, 4, "female")
reptile.printReptileAnimals()
