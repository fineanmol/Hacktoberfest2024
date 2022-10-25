#Parent Class
class User():
    def __init__(self,name, age, gender):
        self.name = name
        self.age = age
        self.gender = gender

    def show_user_details(self):
        print(f"Personal Details for {self.name} - \n")
        print(f'Name : {self.name}')
        print(f'Age : {self.age}')
        print(f'Gender : {self.gender}')


# John = User("John Rivera", 19, "Male")
# John.show_user_details()