import sys
import json
from PySide6.QtWidgets import QApplication, QMainWindow, QLabel, QVBoxLayout, QWidget, QLineEdit, QPushButton, QListView, QMessageBox
from PySide6.QtCore import QStringListModel, Qt

class TodoListApp(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Todo List App")
        self.setGeometry(100, 100, 400, 300)

        self.tasks = []
        self.load_tasks()  # Load tasks from a file

        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)

        self.layout = QVBoxLayout()
        self.central_widget.setLayout(self.layout)

        self.task_list = QListView()
        self.task_list.setEditTriggers(QListView.NoEditTriggers)
        self.task_list.setSelectionMode(QListView.SingleSelection)
        self.layout.addWidget(self.task_list)

        self.label = QLabel("Enter a task:")
        self.layout.addWidget(self.label)

        self.task_input = QLineEdit()
        self.layout.addWidget(self.task_input)

        self.add_button = QPushButton("Add")
        self.add_button.clicked.connect(self.add_task)
        self.layout.addWidget(self.add_button)

        self.remove_button = QPushButton("Remove")
        self.remove_button.clicked.connect(self.remove_task)
        self.layout.addWidget(self.remove_button)

        self.update_task_list()

    def add_task(self):
        task = self.task_input.text()
        if task:
            if task not in self.tasks:
                self.tasks.append(task)
                self.task_input.clear()
                self.update_task_list()
                self.save_tasks()  # Save tasks after adding
            else:
                QMessageBox.warning(self, "Duplicate Task", "Task already exists in the list.")
        else:
            QMessageBox.warning(self, "Input Error", "Task cannot be empty!")

    def remove_task(self):
        selected_index = self.task_list.currentIndex()
        if selected_index.isValid():
            task = self.tasks[selected_index.row()]
            self.tasks.remove(task)
            self.update_task_list()
            self.save_tasks()  # Save tasks after removing
        else:
            QMessageBox.warning(self, "Selection Error", "Please select a task to remove.")

    def update_task_list(self):
        self.task_list.setModel(QStringListModel(self.tasks))

    def save_tasks(self):
        with open("tasks.json", "w") as f:
            json.dump(self.tasks, f)

    def load_tasks(self):
        try:
            with open("tasks.json", "r") as f:
                self.tasks = json.load(f)
        except FileNotFoundError:
            self.tasks = []  # No tasks saved yet, initialize empty list

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = TodoListApp()
    window.show()
    sys.exit(app.exec())
