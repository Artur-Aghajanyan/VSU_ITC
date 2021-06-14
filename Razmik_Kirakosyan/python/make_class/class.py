class Animal:
	terrestrial_animal="horse"
	marine_animal="fish"
	age = 3
	name = ""
	def give_description(self, name, age):
		self.name="valodik"
       # self.age=5
	@classmethod
	def is_fly(cls, arg):                        
		if arg == cls.terrestrial_animal:
			print ("This animal is living in the land")
		if arg == cls.marine_animal:
			print ("This animal is living in the sea")



	#def (voice)  
obj=Animal()
obj.give_description("donald", 10)
print(obj.marine_animal)                               

class python(Animal):
	snake_name = "Python"

	def func(attr):
		print ("This is python")
python.func("anakonda")
 
