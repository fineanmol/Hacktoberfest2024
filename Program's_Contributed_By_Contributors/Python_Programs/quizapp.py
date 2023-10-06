import requests
import json

def get_quiz_questions(amount=5, category=9, difficulty="medium"):
    url = f"https://opentdb.com/api.php?amount={amount}&category={category}&difficulty={difficulty}&type=multiple"
    response = requests.get(url)
    if response.status_code == 200:
        data = json.loads(response.text)
        return data['results']
    else:
        print("Failed to fetch quiz questions. Please check your internet connection.")
        return []

def quiz():
    print("Welcome to the Quiz!")

    num_questions = int(input("Enter the number of questions you want (1-10): "))
    if num_questions < 1 or num_questions > 10:
        print("Invalid number of questions. Please choose between 1 and 10.")
        return

    questions = get_quiz_questions(amount=num_questions)

    if not questions:
        return

    score = 0

    for i, question in enumerate(questions, 1):
        print(f"\nQuestion {i}: {question['question']}")
        options = question['incorrect_answers']
        options.append(question['correct_answer'])
        options.sort()

        for j, option in enumerate(options, 1):
            print(f"{j}. {option}")

        user_answer = input("Your answer (1-4): ")

        if user_answer.isdigit():
            user_answer = int(user_answer)
            if 1 <= user_answer <= 4:
                if options[user_answer - 1] == question['correct_answer']:
                    print("Correct!")
                    score += 1
                else:
                    print(f"Wrong! The correct answer is: {question['correct_answer']}")
            else:
                print("Invalid choice. Please enter a number between 1 and 4.")
        else:
            print("Invalid input. Please enter a number between 1 and 4.")

    print(f"\nQuiz completed! Your score is {score}/{num_questions}.")

if __name__ == "__main__":
    quiz()
