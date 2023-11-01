import requests
from time import sleep
import html

def fetch_quiz_data(amount=4, quiz_type='boolean'):
    url = f"https://opentdb.com/api.php?amount={amount}&type={quiz_type}"
    response = requests.get(url)
    data_json = response.json()
    return data_json["results"]

def check_answer(question, answer, score):
    correct_answer = html.unescape(question['correct_answer']).lower()
    answer = answer.lower()
    
    if answer == correct_answer:
        print("Correct Answer! \nYour score is", score + 1)
        return True
    else:
        print("Wrong Answer! \nYour score is", score - 1)
        print(f"The correct answer is {html.unescape(question['correct_answer'])}")
        return False

def display_question(question, question_number, score):
    print("\n" * 10)
    print("=" * 50)
    print(f"\t\tQuestion number: {question_number}")
    print("=" * 50)
    print(f"\tDifficulty Level: {question['difficulty']}")
    print(f"\tCategory: {question['category']}")
    print("=" * 50)
    print()
    print("Question: ", html.unescape(question['question']))
    print()

def main():
    quiz_data = fetch_quiz_data()
    score = 0
    question_number = 0

    for question in quiz_data:
        question_number += 1

        display_question(question, question_number, score)

        answer = input("Enter Answer (To skip type 'skip'): ")
        print("\n" * 10)

        if answer == "skip":
            continue

        if check_answer(question, answer, score):
            score += 1
            print("Wait moving to the next question...")
            sleep(6)
        else:
            score -= 1
            print("Point deducted...")
            print("Wait moving to the next question...")
            sleep(6)

    print("\n" * 10)
    print("Your final score is", score, "!")
    print("Thanks for playing! 💜")

if __name__ == "__main__":
    main()
