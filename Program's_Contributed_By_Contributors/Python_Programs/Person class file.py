class Person:
    def __init__(self, name):
        self.name = name

    def talk(self):
        print(f"Hi, I am {self.name}")


john = Person("John")
john.talk()

bob = Person("Bob")
bob.talk()