import time
import webbrowser

total_break = 3
break_count = 0

print("This program started on " +time.ctime())
while(break_count < total_break):
    time.sleep(1800)
    webbrowser.open(("https://www.youtube.com/watch?v=SRMeqvkTua8"))
    break_count = break_count + 1