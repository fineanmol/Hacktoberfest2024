org 100h
.data    
    random db 10,13,"Press 1 to vote"
        db 10,13,"Press 2 to see the number of votes"
        db 10,13,"Press 3 to see the result"  
        db 10,13,"Enter your choice:$"
    ra db 10,13,"Press a to see the votes of Party A"  
        db 10,13,"Press b to see the votes of Party B"
        db 10,13,"Press c to see the votes of Party C"
        db 10,13,"Press d to see the votes of Party D" 
        db 10,13,"Enter your choice:$"
    choices db 10,13,"Press a for Party A"  
         db 10,13,"Press b for Party B"
         db 10,13,"Press c for Party C"
         db 10,13,"Press d for Party D$"    
    dis db 10,10,13,"Enter your choice:$"  
    congrats db 10,10,10,13,"                  !!!!!!!!!!!!CONGRATULATIONS!!!!!!!!!!!!!!!!                        $"
    repu db 10,10,13,"                            Party A is the Winner$"
    lib db 10,10,13,"                            Party B is the winner     $"
    green db 10,10,13,"                            Party C is the Winner$"
    demo db 10,10,13,"                           Party D is the winner$" 
    invalid db 10,10,13,"Invalid Choice!!!!$" 
        
    
.code  
assume cs:code,ds:data
start: 
mov bx,0000h 
mov cx,0000h    
more: 
    mov ax,@data
    mov ds,ax      
    mov ah,00
    mov al,02
    int 10h
    mov ah,09h
    mov dx,offset random
    int 21h
    mov ah,01h
    int 21h
    cmp al,31h
        je result
    cmp al,32h
        je vote 
    cmp al,33h
        je ri
    jmp inval
vote:  
    mov ah,00
    mov al,02
    int 10h
    mov ah,09h
    mov dx,offset ra
    int 21h
    mov ah,01h
    int 21h   
    cmp al, 61h
        je av
    cmp al, 62h
        je bv
    cmp al, 63h
        je cv
    cmp al, 64h
        je dv 
    jmp inval
av:
   #start=led_display.exe#
   mov ax,0000h
   mov al,bh
   out 199,ax
   jmp more   
bv: 
   #start=led_display.exe#  
   mov ax,0000h
   mov al,bl
   out 199,ax
   jmp more
cv:  
   #start=led_display.exe#
   mov ax,0000h
   mov al,ch
   out 199,ax
   jmp more
dv:  
   #start=led_display.exe#
   mov ax,0000h
   mov al,cl
   out 199,ax
   jmp more 
result: 
    mov ah,00
    mov al,02
    int 10h         
    mov ah, 09h
    mov dx, offset choices 
    int 21h
    mov ah,09h
    mov dx, offset dis
    int 21h
    mov ah,01h 
    int 21h 
    cmp al, 61h
        je a
    cmp al, 62h
        je b
    cmp al, 63h
        je c
    cmp al, 64h
        je d     
    jmp inval

a: inc bh 
   #start=led_display.exe#
   mov ax,0000h
   mov al,bh
   out 199,ax
   jmp more  
b: inc bl 
   #start=led_display.exe#  
   mov ax,0000h
   mov al,bl
   out 199,ax
   jmp more
c: inc ch 
   #start=led_display.exe#
   mov ax,0000h
   mov al,ch
   out 199,ax
   jmp more
d: inc cl 
   #start=led_display.exe#
   mov ax,0000h
   mov al,cl
   out 199,ax
   jmp more 
   
inval:
    mov ah,09h
    mov dx, offset invalid
    int 21h  
    jmp more
ri:     
    mov ah,00h
    mov al,02h
    int 10h
    mov ah,09h
    mov dx, offset congrats
    int 21h 
    cmp bh,bl
        jg a1 
    cmp bl,bh
        jg b1   
    cmp ch,bl
        jg c1        
    cmp cl, bh
        jg d1
               
    a1: cmp bh,bl
        jng b1
        cmp bh,ch
        jng b1
        cmp bh,cl
        jng b1
        jmp awin
    b1: cmp bl,ch
        jng c1
        cmp bl,cl
        jng c1
        jmp bwin
    c1: cmp ch,cl
        jng d1
        jmp cwin
    d1: jmp dwin   
awin: 
    mov ah,09h
    mov dx, offset repu
    int 21h
    jmp l
bwin:   
    mov ah,09h
    mov dx, offset demo
    int 21h
    jmp l
cwin: 
    mov ah,09h
    mov dx, offset green
    int 21h
    jmp l
dwin: 
    mov ah,09h
    mov dx, offset lib
    int 21h
    jmp l
l:        
mov ah, 0
int 16h 
ret 
