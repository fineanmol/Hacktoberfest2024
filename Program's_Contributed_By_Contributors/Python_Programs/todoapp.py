import sys
import os
from PySide6.QtWidgets import QApplication, QMainWindow, QLabel, QVBoxLayout, QWidget, QLineEdit, QPushButton, QListView, QMessageBox
from PySide6.QtCore import QStringListModel

class TodoListApp(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Todo List App")
        self.setGeometry(100, 100, 400, 300)

        # Load tasks from a file if available
        self.tasks = self.load_tasks()

        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)

        self.layout = QVBoxLayout()
        self.central_widget.setLayout(self.layout)

        # Task list view
        self.task_list = QListView()
        self.task_list.setEditTriggers(QListView.NoEditTriggers)
        self.task_list.setSelectionMode(QListView.SingleSelection)
        self.layout.addWidget(self.task_list)

        self.label = QLabel("Enter a task:")
        self.layout.addWidget(self.label)

        # Task input field
        self.task_input = QLineEdit()
        self.layout.addWidget(self.task_input)

        # Add button
        self.add_button = QPushButton("Add")
        self.add_button.clicked.connect(self.add_task)
        self.layout.addWidget(self.add_button)

        # Remove button
        self.remove_button = QPushButton("Remove")
        self.remove_button.clicked.connect(self.remove_task)
        self.layout.addWidget(self.remove_button)

        # Update the task list view
        self.update_task_list()

    def add_task(self):
        task = self.task_input.text().strip()
        if task:  # Input validation to ensure task is non-empty
            self.tasks.append(task)
            self.task_input.clear()
            self.update_task_list()
            self.save_tasks()  # Save tasks after adding

    def remove_task(self):
        selected_index = self.task_list.currentIndex()
        if selected_index.isValid():
            # Confirmation dialog for task removal
            reply = QMessageBox.question(self, 'Confirm Removal', 
                                         'Are you sure you want to remove this task?', 
                                         QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
            if reply == QMessageBox.Yes:
                task = self.tasks[selected_index.row()]
                self.tasks.remove(task)
                self.update_task_list()
                self.save_tasks()  # Save tasks after removal

    def update_task_list(self):
        self.task_list.setModel(QStringListModel(self.tasks))

    def load_tasks(self):
        if os.path.exists("tasks.txt"):
            with open("tasks.txt", "r") as file:
                return [line.strip() for line in file.readlines()]
        return []

    def save_tasks(self):
        with open("tasks.txt", "w") as file:
            for task in self.tasks:
                file.write(f"{task}\n")

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = TodoListApp()
    window.show()
    sys.exit(app.exec())
