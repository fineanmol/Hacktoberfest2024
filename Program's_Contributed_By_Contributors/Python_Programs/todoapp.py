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

        self.layout = QVBoxLayout(self.central_widget)
        self.task_list = QListView(editTriggers=QListView.NoEditTriggers, selectionMode=QListView.SingleSelection)
        self.layout.addWidget(self.task_list)

        self.layout.addWidget(QLabel("Enter a task:"))

        self.task_input = QLineEdit()
        self.layout.addWidget(self.task_input)

        self.add_button = QPushButton("Add", clicked=self.add_task)
        self.layout.addWidget(self.add_button)

        self.remove_button = QPushButton("Remove", clicked=self.remove_task)
        self.layout.addWidget(self.remove_button)

        self.update_task_list()

    def add_task(self):
        task = self.task_input.text().strip()
        if task and task not in self.tasks:
            self.tasks.append(task)
            self.task_input.clear()
            self.update_task_list()

    def remove_task(self):
        selected_index = self.task_list.currentIndex()
        if selected_index.isValid():
            self.tasks.pop(selected_index.row())
            self.update_task_list()

    def update_task_list(self):
        self.task_list.setModel(QStringListModel(self.tasks))

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = TodoListApp()
    window.show()
    sys.exit(app.exec())
