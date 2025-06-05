import sys
from PySide6.QtWidgets import QApplication, QMainWindow, QLabel, QVBoxLayout, QWidget, QLineEdit, QPushButton, QListView
from PySide6.QtCore import QStringListModel

class TodoListApp(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Todo List App")
        self.setGeometry(100, 100, 400, 300)

        self.tasks = []

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
        task = self.task_input.text().strip()  # Strip leading/trailing spaces
        if not task:
            self.label.setText("Task cannot be empty.")  # Provide feedback to the user
            return
        if task in self.tasks:
            self.label.setText("Task already exists.")  # Feedback for duplicates
            return
        self.tasks.append(task)
        self.task_input.clear()
        self.label.setText("Enter a task:")
        self.update_task_list()

    def remove_task(self):
        selected_index = self.task_list.currentIndex()
        if selected_index.isValid():
            task = self.tasks[selected_index.row()]
            self.tasks.remove(task)
            self.label.setText(f"Removed task: {task}")  # Feedback after removing
            self.update_task_list()
        else:
            self.label.setText("No task selected.")  # Feedback for no selection

    def update_task_list(self):
        self.task_list.setModel(QStringListModel(self.tasks))
        self.remove_button.setEnabled(bool(self.tasks))  # Disable if no tasks

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = TodoListApp()
    window.show()
    sys.exit(app.exec())