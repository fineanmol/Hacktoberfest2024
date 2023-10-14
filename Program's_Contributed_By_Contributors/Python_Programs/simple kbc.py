print("Welcome to Kaun Banega Crorepati\n")
t = input("Please Enter Your Name :\n ")
print(
    "\nLet's Start with the hot seat round \nPlayer who will guess the correct answer within short period of time will be quilify to seat in hot seat and play the game\n")
print("\nNote : Please Enter the answer according to the serial number continuosly\n")
o = int(input(
    "\nArrange the planet name according to the distance from sum \n 1. Earth \n 2. Saturn  \n 3. Venus \n 4. Neptune\n"))
if o == 3124:
    print("Congratulation", t, "You are qualified")
    print("Welcome to the Hot Seat\n")

    print("Here is the format of KBC ")
    print(
        "Question  Prize    \n  10.     1,00,00,000 \n  09.       75,00,000   \n  08.       50,00,000 \n  07.       10,00,000 \n  06.        5,00,000 \n  05.        1,00,000 \n  04.          50,000      \n  03.          10,000      \n  02.           5,000       \n  01.           1,000 \n")

    Q = ['What country has the highest life expectancy?', 'Who was the Ancient Greek God of the Sun? ',
         'What year was the United Nations established? ', 'Which language has the more native speakers? ',
         'How many elements are in the periodic table? ', 'What company was originally called "Cadabra"? ',
         'Queen guitarist Brian May is also an expert in what scientific field? ',
         'What game studio makes the Red Dead Redemption series? ', 'Which planet in the Milky Way is the hottest? ',
         'What city is known as "The Eternal City"?']
    A = ['HongKong', 'Apollo', '1945', 'Spanish', '118', 'Amazon', 'Astrophysics', 'Rockstar Games', 'Venus', ' Rome']
    print("Lets Start with the First Question For RS 1,000\n Here comes the first question\n")
    print(Q[0])
    i = int(input("1. Nepal                  2. USA\n3. HongKong               4.Germany\n"))
    if i == 3:
        print("Congratulation ", t, " This is the right answer\n")
        print("You have won Rs 1,000\n")
        print("This is the second question for RS 5,000 here in your computer screen\n")
        print(Q[1])
        q = int(input("1. Selene                   2. Apollo\n3. Astraeus                 4.Zeus\n"))

        if q == 2:
            print("Congratulation , This is the right answer\n")
            print("You have won Rs 5,000\n")
            print("This is the third question for Rs 10,000 here in your computer screen\n")
            print(Q[2])
            w = int(input("1. 1999                   2. 1945\n3. 1955                   4. 1982\n"))
            if w == 2:
                print("Congratulation ", t, " This is the right answer\n")
                print("You have won Rs 10,000\n")
                print("This is the fourth question for Rs 50,000 here in your computer screen\n")
                print(Q[3])
                i = int(input("1. Nepali                  2. English\n3. Spanish                 4. Hindi\n"))
                if i == 3:
                    print("Congratulation ", t, " This is the right answer\n")
                    print("You have won Rs 50,000\n")
                    print("This is the fifth question for Rs 1,00,000 here in your computer screen\n")
                    print(Q[4])
                    i = int(input("1. 118                  2. 126\n3. 144                  4. 98\n"))
                    if i == 1:
                        print("Congratulation", t, "This is the right answer\n")
                        print("You have won Rs 1,00,000\n")
                        print("This is the sixth question for Rs 5,00,000 here in your computer screen\n")
                        print(Q[5])
                        i = int(
                            input("1. Microsoft                  2. Tesla\n3. Jio                        4. Amazon\n"))
                        if i == 4:
                            print("Congratulation", t, "This is the right answer\n")
                            print("You have won Rs 5,00,000\n")
                            print("This is the seventh question for Rs 10,00,000 here in your computer screen\n")
                            print(Q[6])
                            i = int(input(
                                "1. Mathematics                  2. Astrophysics\n3. Chemical Biology             4. Space science\n"))
                            if i == 2:
                                print("Congratulation", t, "This is the right answer\n")
                                print("You have won Rs 10,00,000\n")
                                print("This is the Eighth question for Rs 50,00,000 here in your computer screen\n")
                                print(Q[7])
                                i = int(input(
                                    "1. Rockstar Games                  2. Tencent Games\n3. Zero Games Studio               4. Gameloft\n"))
                                if i == 1:
                                    print("Congratulation", t, "This is the right answer\n")
                                    print("You have won Rs 50,00,000\n")
                                    print("This is the Ninth question for Rs 75,00,000 here in your computer screen\n")
                                    print(Q[8])
                                    i = int(input(
                                        "1. Earth                  2. Neptune\n3. Venus                  4. Mercury\n"))
                                    if i == 3:
                                        print("Congratulation", t, "This is the right answer\n")
                                        print("You have won Rs 75,00,000\n")
                                        print(
                                            "This is the Tenth and last question for Rs 1,00,00,000 here in your computer screen\n")
                                        print(Q[9])
                                        i = int(input(
                                            "1. Paris               2. Cape Town\n3. Kyoto               4. Rome\n"))
                                        if i == 4:
                                            print("Congratulation", t, "You have won 1 Crore Rupee\n")
                                            print("This is the check of 1 crore rupees\n")

                                        else:
                                            print("Ohh!!!!!!", t, "You have selected wrong answer")
                                            print("The right answer was :", A[9])
                                            print("\nCongratulation", t, "You have only won Rs 75,00,000 Rupee")
                                            print("This is the check of 75 lakhs rupees\n")

                                    else:
                                        print("Ohh!!!!!!", t, "You have selected wrong answer")
                                        print("The right answer was :", A[8])
                                        print("\nCongratulation", t, "You have only won Rs 50,00,000 Rupee")
                                        print("This is the check of 50 lakhs rupees\n")
                                else:
                                    print("Ohh!!!!!!", t, "You have selected wrong answer")
                                    print("The right answer was :", A[7])
                                    print("\nCongratulation", t, "You have only won Rs 10,00,000 Rupee")
                                    print("This is the check of 10 lakhs rupees\n")
                            else:
                                print("Ohh!!!!!!", t, "You have selected wrong answer")
                                print("The right answer was :", A[6])
                                print("\nCongratulation", t, "You have only won Rs 5,00,000 Rupee")
                                print("This is the check of 5 lakhs rupees\n")
                        else:
                            print("Ohh!!!!!!", t, "You have selected wrong answer")
                            print("The right answer was :", A[5])
                            print("\nCongratulation", t, "You have only won Rs 1,00,000 Rupee")
                            print("This is the check of 1 lakh rupees\n")
                    else:
                        print("Ohh!!!!!!", t, "You have selected wrong answer")
                        print("The right answer was :", A[4])
                        print("\nCongratulation", t, "You have only won Rs 50,000 Rupee")
                        print("This is the check of 50 thousand rupees\n")
                else:
                    print("Ohh!!!!!!", t, "You have selected wrong answer")
                    print("The right answer was :", A[3])
                    print("\nCongratulation", t, "You have only won Rs 10,000 Rupee")
                    print("This is the check of 10 thousand rupees\n")
            else:
                print("Ohh!!!!!!", t, "You have selected wrong answer")
                print("The right answer was :", A[2])
                print("\nCongratulation", t, "You have only won Rs 5,000 Rupee")
                print("This is the check of 5 thousand rupees\n")
        else:
            print("Ohh!!!!!!", t, "You have selected wrong answer")
            print("The right answer was :", A[1])
            print("\nCongratulation", t, "You have only won Rs 1,000 Rupee")
            print("This is the check of 1 thousand rupees\n")
    else:
        print("Ohh!!!!!!", t, "You have selected wrong answer")
        print("The right answer was :", A[0])
        print("Sorry",t,"You have won Rs 0\n")
else:
    print("Ohh!!!!!!", t, "You have selected wrong answer\n")
    print("The right answer was\n 3. Venus \n 1. Earth \n 2. Saturn \n 4. Neptune\n")

print("Thank You for your participation")
