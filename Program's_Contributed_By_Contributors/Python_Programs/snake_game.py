def snake() : 
    import turtle , random , time 
    count = 0 
    delay = 0.09
    score = 0
    win = turtle.Screen() 
    win.title("__Snake__")
    win.bgcolor("black")
    win.setup(width=800,height=600)
    win.tracer(0)
     
    snake = turtle.Turtle() 
    snake.speed(0)
    snake.shape("square")
    snake.color("white") 
    snake.shapesize(stretch_wid = 1 , stretch_len = 1)
    snake.penup() 
    snake.direction = "stop"
    
    snake_body = [] 
     
    food = turtle.Turtle() 
    food.speed(0) 
    food.shape("circle")
    food.color("red")
    food.penup()  
    food.goto(random.randint(-340,+340) ,random.randint(-280 , +280 ))
    
    pen = turtle.Turtle() 
    pen.speed(0)
    pen.color('white')
    pen.penup() 
    pen.hideturtle() 
    pen.goto(0,+280)
    pen.write("Score :   "  , align = "center" , font = ("Arial" , 14 , "bold" ))
    
    
    def move() : 
        if snake.direction =="up" : 
            snake.sety(snake.ycor() + 20)
        if snake.direction == "down" : 
            snake.sety(snake.ycor() - 20 )
        if snake.direction == "left" : 
            snake.setx(snake.xcor() - 20 )
        if snake.direction == "right" : 
            snake.setx(snake.xcor() + 20 )
    
 
    def  up() : 
        snake.direction = "up"
    def down() : 
        snake.direction = "down"
    def  right() : 
        snake.direction = "right"
    def  left() : 
        snake.direction = "left"
     

    win.listen()
    win.onkeypress(up, "w")
    win.onkeypress(down, "s")
    win.onkeypress(left, "a")
    win.onkeypress(right, "d")
       
    while True : 
        win.update()
      
        if snake.distance(food) <25:
           
            
            x = random.randint(-290, 290)
            y = random.randint(-290, 290)
            food.goto(x, y)
             
            score = score + 1 
            pen.clear() 
            pen.write("Score : {}  ".format(score), align = "center" , font = ("Arial" , 14 , "bold" ))
            
            body = turtle.Turtle()
            body.speed(0)
            body.shape("square")
            body.color("white")
            body.penup()
            snake_body.append(body)
       
        for index in range(len(snake_body)-1, 0 , -1):
            x = snake_body[index-1].xcor()
            y = snake_body[index-1].ycor()
            snake_body[index].goto(x, y)
    
        if len(snake_body) > 0:
            x = snake.xcor()
            y = snake.ycor()
            snake_body[0].goto(x,y)
       
        time.sleep(delay)  
            
        move() 

        if snake.xcor() > 390 : 
           snake.goto(snake.xcor() * (-1) , snake.ycor())
        elif snake.xcor() < -390 :  
           snake.goto(snake.xcor()*(-1) , snake.ycor())
        elif snake.ycor() > 290 : 
           snake.goto(snake.xcor(),snake.ycor()*(-1))
        elif snake.ycor() < - 290 : 
            snake.goto(snake.xcor() , snake.ycor() * (-1))
    
 
        for body in snake_body :
           if body.distance(snake) < 20 : 
              time.sleep(1)
              snake.goto(0,0) 
              snake.direction = "stop" 
              for body in snake_body : 
                  body.goto(1000,1000)  
              snake_body.clear()
              pen.clear() 
              pen.write("Score :   "  , align = "center" , font = ("Arial" , 14 , "bold" ))
              score = 0 
              
snake()         
    
        