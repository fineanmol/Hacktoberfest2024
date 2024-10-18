# Perfect Number by using For_loop
Input_Number = 78
Sum = 0
for i in range(1, Input_Number):
    if(Input_Number % i == 0):
        Sum = Sum + i
if (Sum == Input_Number):
    print(&quot;Number is a Perfect Number.&quot;)
else:
    print(&quot;Number is not a Perfect Number.&quot;)
