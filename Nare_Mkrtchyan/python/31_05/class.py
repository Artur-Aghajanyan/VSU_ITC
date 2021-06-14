from datetime import date

class Player:
    __count = 0

    def __init__(self, name, age, height, country):
        self._name = name
        self._age = age
        self._height = height
        self._country = country
        Player.__count += 1

    @classmethod
    def from_birth_year(cls, name, year, height, country):
        return cls(name, date.today().year - year, height, country)

    @classmethod
    def with_weight(cls, name, age, height, country, weight):
        return cls(name, age, height, country, weight)

    def get_name(self):
        return self._name
    def get_age(self):
        return self._age
    def get_height(self):
        return self._height
    def get_country(self):
        return self._country
    @staticmethod
    def get_pl_count():
        return Player.__count

class FootballPlayer(Player):
    def __init__(self, name, age, height, country, position):
        super().__init__(name, age, height, country)
        self._position = position

    def get_position(self):
        return self._position

class TennisPlayer(Player):
    def __init__(self, name, age, height, country, hand):
        super().__init__(name, age, height, country)
        self._hand = hand

    def get_hand(self):
        return self._hand

    def get_name(self):
        print("From TennisPlayer Class.")
        return self._name


pl1 = Player("a",12,184,"Arm")
pl2 = FootballPlayer("a",12,184,"Arm","forward")
pl3 = Player.from_birth_year("Andy", 1987, 191, "Scotland")
pl5 = TennisPlayer("Domi", 27, 185, "Austria","Right")
try:
    pl4 = Player.with_weight("Name", 20, 175, "Armenia", 55)
except TypeError:
    print("Tried using class method give more argument to init and got expected error: __init__() takes 5 positional arguments but 6 were given")
try:
    print(pl1.name)
except AttributeError:
    print("Tried to get protected attribute from class and got expected error: Player has no public attribute name.")

print("player1's name: ",pl1.get_name())
print("player2's age: ",pl2.get_age())
print("player2's position: ",pl2.get_position())
print("\n")
print(pl5.get_name())
print("class method: ",pl3.get_age())
print("Staticmethod: ",Player.get_pl_count())
