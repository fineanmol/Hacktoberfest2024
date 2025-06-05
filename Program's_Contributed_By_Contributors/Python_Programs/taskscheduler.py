import sched
import time

def my_task(task_name):
    print(f"Task '{task_name}' executed at:", time.strftime("%H:%M:%S"))

def schedule_task():
    task_scheduler = sched.scheduler(time.time, time.sleep)
    while True:
        try:
            task_name = input("Enter task name (or 'exit' to quit): ")
            if task_name.lower() == 'exit':
                break
            interval = float(input("Enter task interval (in seconds): "))
            task_scheduler.enter(interval, 1, my_task, (task_name,))
        except ValueError:
            print("Invalid input. Please enter a valid task interval (a number in seconds).")

    print("Task scheduler stopped.")

if __name__ == "__main__":
    schedule_task()
