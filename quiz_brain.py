class QuizBrain:
    def __init__(self, q_list):
        self.question_number = 0
        self.question_list = q_list
        self.score = 0

    def still_has_questions(self):
        return self.question_number < len(self.question_list)

    def next_question(self):
        score = 0
        question = self.question_list[self.question_number]
        self.question_number += 1
        user_answer = input(f"Q {self.question_number} : {question.text} (True/False)")
        self.check_answer(user_answer, question.answer)

    def check_answer(self, user_answer, correct_answer):


        question = 1
        if user_answer == correct_answer:
            self.score += 1
            print(f"You got it right!")
        else:
            print(f"It is Wrong.")
        print(f"Your score is {self.score}/{self.question_number}")
        question += 1