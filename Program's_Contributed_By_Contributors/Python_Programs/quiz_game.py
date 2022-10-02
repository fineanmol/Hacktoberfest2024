import requests

class Question:
    def __init__(self,text,ans):
        self.text = text
        self.answer = ans

class QuestionBrain:
    def __init__(self,l):
        self.n=0
        self.qlist = l
        self.score = 0

    def nextQuestion(self):
        que = self.qlist[self.n]
        self.n+=1
        a = input(f"Q.{self.n}: {que.text} (True/False) ? :")
        self.check(a,que.answer)

    def still_have_question(self):
        return self.n < len(self.qlist)

    def check(self,ans,crt):
        if ans.lower()==crt.lower():
            self.score +=1
            print("You are Right")
        else:
            print("You are Wrong")
        print(f"Your score : {self.score}/{self.n}")

    def finish(self):
        print(f"You have completed the quiz..\nYour final score : {self.score}/{self.n}")

class Data:
    def __init__(self):
        self.question_data=[]
        self.amount=10
        self.category=9
        self.difficulty='easy'
        self.category_name = [
            {'name':"General Knowledge","id":"9"},
            {'name':"Books","id":"10"},
            {'name':"Films","id":"11"},
            {'name':"Musics","id":"12"},
            {'name':"Musical & Theatre","id":"13"},
            {'name':"Television","id":"14"},
            {'name':"Video Games","id":"15"},
            {'name':"Board Games","id":"16"},
            {'name':"Science & Nature","id":"16"},
            {'name':"Computer","id":"18"},
            {'name':"Maths","id":"19"},
            {'name':"Mythology","id":"20"},
            {'name':"Sports","id":"21"},
            {'name':"Geology","id":"22"},
            {'name':"History","id":"23"},
            {'name':"Politics","id":"24"},
            {'name':"Art","id":"25"},
            {'name':"Celebrity","id":"26"},
            {'name':"Animal","id":"27"},
            {'name':"Vehical","id":"28"},
            {'name':"Comics","id":"29"},
            {'name':"Gadgets","id":"30"}
            ]

    def showCategory(self):
        for i in self.category_name:
            print(f"{i['name']}--{int(i['id'])-9}",end="       ")
        print()

    def create(self):
        self.amount = int(input("Number of Questions (less than 50):"))%51
        self.showCategory()
        self.category = ((int(input("Choose a Category:"))%22) + 9)
        t= True
        while t:
            self.difficulty = input("Choose a difficulty level (easy/medium/hard): ").lower()
            if self.difficulty =="easy" or self.difficulty =="medium" or self.difficulty == "hard":
                break
            else: print("Choose a correct_difficulty level..")
        self.create_data()
    
    def printdata(self):
        print(self.difficulty, self.amount, self.category)

    def create_data(self):
        # self.printdata()
        url = f'https://opentdb.com/api.php?amount={self.amount}&category={self.category}&difficulty={self.difficulty}&type=boolean'
        # print(url)
        res =requests.get(url).json()
        for i in res['results']:
            d = {"text":i['question'],"answer":i['correct_answer']}
            self.question_data.append(d)

        if len(self.question_data)==0:
            url = f'https://opentdb.com/api.php?amount={self.amount}&type=boolean'
            res =requests.get(url).json()
            for i in res['results']:
                d = {"text":i['question'],"answer":i['correct_answer']}
                self.question_data.append(d)
            print(f"\n\nUnable to find as per your request, {res['results'][0]['category']} is the category we choose for you")
        else:print("\n\n")

qbank = []

data = Data()
data.create()

for i in data.question_data:
    # print(i)
    q = Question(i['text'], i['answer'],)
    qbank.append(q)

quiz = QuestionBrain(qbank)

print('\n\n\n')
while quiz.still_have_question():
    quiz.nextQuestion()

quiz.finish()
