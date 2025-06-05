def calculate_grade(score):
    if 0 <= score < 30:
        return "F"
    elif 30 <= score < 45:
        return "S"
    elif 45 <= score < 55:
        return "C"
    elif 55 <= score < 65:
        return "B"
    elif 65 <= score < 75:
        return "A"
    elif 75 <= score <= 100:
        return "A+"
    else:
        return "Invalid"

def main():
    num_subjects = 5
    total_score = 0

    for i in range(1, num_subjects + 1):
        try:
            score = float(input(f"Enter score for subject {i}: "))
            total_score += score
        except ValueError:
            print("Invalid input. Please enter a valid numeric score.")
            return

    average_score = total_score / num_subjects
    final_grade = calculate_grade(average_score)

    print(f"Average Score: {average_score}")
    print(f"Final Grade: {final_grade}")

    if final_grade == "A+" or final_grade == "A":
        print("Congratulations! You have performed exceptionally well.")
    elif final_grade == "F":
        print("You need to improve your performance to pass.")
    else:
        print("Keep up the good work!")

if __name__ == "__main":
    main()
