# other helping options
# poll
# 50 - 50
# phone a friend 

# random correct answer

from tkinter import *
import requests
import random

root = Tk()
root.title("ARE  YOU  GENIUS")
root.geometry("1300x500")

game_frame = Frame(root,bg="#4E4C45")
game_frame.place( relheight= 1 , relwidth = 1 )


url ="https://opentdb.com/api.php?amount=10&category=21&type=multiple"

response = requests.get(url)

data = response.json()


x = score = 0



def questions_creator (y) :

    global options , position_over , j , template_options , answer

    template_options = [data["results"][y]["correct_answer"],data["results"][y]["incorrect_answers"][0],data["results"][y]["incorrect_answers"][1],data["results"][y]["incorrect_answers"][2]]

    for index in range(4) :
        print("\n" + template_options[index])

    print("\n\n\n")

    options = [None]*4
    position_over = [None]*4
    j = 0

    def option_rand () :

        global j ,  position , options , answer

        position = random.randrange(4)

        for r in range(4) :

            if not(position_over[0] == None) and not(position_over[1] == None) and not(position_over[2] == None) and not(position_over[3] == None) :
                break

            if position == position_over[0] or position == position_over[1] or position == position_over[2] or position == position_over[3] :
                option_rand()

            else :
                position_over[j] = position
                options[j] = template_options[position]

                if position == 0 :
                    answer = j

                j += 1

    option_rand()

    for index in range(4) :
        print("\n" + options[index])

    print("\n\nANSER IS : " + options[answer] + "\n\n")

    display_q(globals()["x"])


def retry_game () :

    global response , data , game_frame

    globals()["x"] = globals()["score"] = 0

    response = requests.get(url)

    data = response.json()

    game_frame = Frame(root,bg="#4E4C45")
    game_frame.place( relheight= 1 , relwidth = 1 )

    questions_creator(0)


def claculation (ans) :

    if ans == answer :
        globals()["score"] += 10

    else :
        globals()["score"] -= 5

    if globals()["x"] < 9 :
        globals()["x"] += 1
        questions_creator(globals()["x"])

    else :

        text = "FINAL SCORE IS \n" + str(globals()["score"])

        game_over_frame = Label(game_frame,bg="#CDC1F1",text=text,font=("acme",20),justify=CENTER)
        game_over_frame.place(  relheight= 1 , relwidth = 1  )

        retry_b =  Button(game_frame,bg="#643BE5",activebackground="#967DE6",justify=CENTER,font=("acme",18),text="RETRY",command=retry_game)
        retry_b.place(relx=0.025 ,rely=0.7 ,relheight=0.15 ,relwidth=0.3 )


def display_q (y) :


    que_l = Label(game_frame,bg="#766E54",justify=CENTER,font=("acme",17),text=data["results"][y]["question"])
    que_l.place(relx=0.025 ,rely=0.05 ,relheight=0.25 ,relwidth=0.95 )

    #options = [data["results"][y]["incorrect_answers"][0],data["results"][y]["incorrect_answers"][1],data["results"][y]["correct_answer"],data["results"][y]["incorrect_answers"][2]]

    opt_1 = Button(game_frame,bg="#948F7E",activebackground="#A0C6B8",justify=CENTER,font=("acme",18),text=options[0],command=lambda:claculation(0))
    opt_1.place(relx=0.025 ,rely=0.39 ,relheight=0.25 ,relwidth=0.45 )

    opt_2 = Button(game_frame,bg="#948F7E",activebackground="#A0C6B8",justify=CENTER,font=("acme",18),text=options[1],command=lambda:claculation(1))
    opt_2.place(relx=0.525 ,rely=0.39 ,relheight=0.25 ,relwidth=0.45 )

    opt_3 = Button(game_frame,bg="#948F7E",activebackground="#A0C6B8",justify=CENTER,font=("acme",18),text=options[2],command=lambda:claculation(2))
    opt_3.place(relx=0.025 ,rely=0.7 ,relheight=0.25 ,relwidth=0.45 )

    opt_4 = Button(game_frame,bg="#948F7E",activebackground="#A0C6B8",justify=CENTER,font=("acme",18),text=options[3],command=lambda:claculation(3))
    opt_4.place(relx=0.525 ,rely=0.7 ,relheight=0.25 ,relwidth=0.45 )



questions_creator(globals()["x"])

root.mainloop()