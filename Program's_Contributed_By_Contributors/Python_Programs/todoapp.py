import json
import tkinter as tk
from tkinter import simpledialog, messagebox, Listbox, Scrollbar, Frame

# Define a class to represent a task
class Task:
    def __init__(self, title, description, category, completed=False):
        self.title = title
        self.description = description
        self.category = category
        self.completed = completed  # Add this argument to handle loaded tasks

    def mark_completed(self):
        self.completed = True

    def unmark_completed(self):
        self.completed = False

# Load tasks from 'tasks.json' file
def load_tasks():
    try:
        with open('tasks.json', 'r') as f:
            return [Task(**data) for data in json.load(f)]
    except FileNotFoundError:
        return []
    except json.JSONDecodeError:
        print("Warning: tasks.json is corrupted or empty. Starting with an empty task list.")
        return []

# Save tasks to 'tasks.json' file
def save_tasks(tasks):
    with open('tasks.json', 'w') as f:
        json.dump([task.__dict__ for task in tasks], f)

# Application class for GUI
class TodoApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Personal To-Do List")
        self.root.geometry("400x500")
        self.root.configure(bg="#1a1a1a")
        self.tasks = load_tasks()

        # Frame for the Listbox
        self.frame = Frame(self.root, bg="#1a1a1a")
        self.frame.pack(pady=10)

        # Scrollbar for the Listbox
        self.scrollbar = Scrollbar(self.frame, bg="#005577")
        self.scrollbar.pack(side=tk.RIGHT, fill=tk.Y)

        self.task_list = Listbox(self.frame, width=50, height=10, bg="#2a2a2a", fg="#00ffcc",
                                 yscrollcommand=self.scrollbar.set, selectbackground="#005577", selectforeground="#ffffff",
                                 font=("Courier New", 10))
        self.task_list.pack()
        self.scrollbar.config(command=self.task_list.yview)

        # Button Frame
        self.button_frame = Frame(self.root, bg="#1a1a1a")
        self.button_frame.pack(pady=10)

        # Buttons with styles
        self.add_button = tk.Button(self.button_frame, text="Add Task", command=self.add_task, bg="#005577", fg="#ffffff",
                                    font=("Courier New", 10), padx=10, pady=5, relief=tk.GROOVE)
        self.add_button.pack(side=tk.TOP, pady=5)

        self.complete_button = tk.Button(self.button_frame, text="Mark Completed", command=self.mark_completed,
                                          bg="#005577", fg="#ffffff", font=("Courier New", 10), padx=10, pady=5,
                                          relief=tk.GROOVE)
        self.complete_button.pack(side=tk.TOP, pady=5)

        self.unmark_button = tk.Button(self.button_frame, text="Unmark Task", command=self.unmark_completed,
                                       bg="#ffa500", fg="#ffffff", font=("Courier New", 10), padx=10, pady=5,
                                       relief=tk.GROOVE)
        self.unmark_button.pack(side=tk.TOP, pady=5)

        self.edit_button = tk.Button(self.button_frame, text="Edit Task", command=self.edit_task,
                                     bg="#005577", fg="#ffffff", font=("Courier New", 10), padx=10, pady=5,
                                     relief=tk.GROOVE)
        self.edit_button.pack(side=tk.TOP, pady=5)

        self.delete_button = tk.Button(self.button_frame, text="Delete Task", command=self.delete_task,
                                       bg="#ff5733", fg="#ffffff", font=("Courier New", 10), padx=10, pady=5,
                                       relief=tk.GROOVE)
        self.delete_button.pack(side=tk.TOP, pady=5)

        # Load initial tasks into Listbox
        self.display_tasks()

    def display_tasks(self):
        """Display all tasks in the Listbox."""
        self.task_list.delete(0, tk.END)  # Clear existing tasks
        for task in self.tasks:
            status = "✔️" if task.completed else "❌"
            self.task_list.insert(tk.END, f"{task.title} - {task.description} [{task.category}] ({status})")

    def add_task(self):
        """Add a new task."""
        title = simpledialog.askstring("Task Title", "Enter task title:")
        if title:
            description = simpledialog.askstring("Task Description", "Enter task description:")
            category = simpledialog.askstring("Task Category", "Enter task category:")
            new_task = Task(title, description, category)
            self.tasks.append(new_task)
            self.display_tasks()

    def mark_completed(self):
        """Mark a selected task as completed."""
        try:
            selected_index = self.task_list.curselection()[0]
            self.tasks[selected_index].mark_completed()
            self.display_tasks()
        except IndexError:
            messagebox.showwarning("Warning", "Please select a task to mark as completed.")

    def unmark_completed(self):
        """Unmark a selected task (mark as incomplete)."""
        try:
            selected_index = self.task_list.curselection()[0]
            self.tasks[selected_index].unmark_completed()
            self.display_tasks()
        except IndexError:
            messagebox.showwarning("Warning", "Please select a task to unmark.")

    def edit_task(self):
        """Edit a selected task."""
        try:
            selected_index = self.task_list.curselection()[0]
            task = self.tasks[selected_index]

            title = simpledialog.askstring("Task Title", "Enter new task title:", initialvalue=task.title)
            description = simpledialog.askstring("Task Description", "Enter new task description:", initialvalue=task.description)
            category = simpledialog.askstring("Task Category", "Enter new task category:", initialvalue=task.category)

            if title: task.title = title
            if description: task.description = description
            if category: task.category = category

            self.display_tasks()
        except IndexError:
            messagebox.showwarning("Warning", "Please select a task to edit.")

    def delete_task(self):
        """Delete a selected task."""
        try:
            selected_index = self.task_list.curselection()[0]
            self.tasks.pop(selected_index)
            self.display_tasks()
        except IndexError:
            messagebox.showwarning("Warning", "Please select a task to delete.")

    def on_closing(self):
        """Handle the closing event to save tasks."""
        save_tasks(self.tasks)
        self.root.destroy()

# Main application logic
if __name__ == "__main__":
    root = tk.Tk()
    app = TodoApp(root)
    root.protocol("WM_DELETE_WINDOW", app.on_closing)  # Save tasks on close
    root.mainloop()
