import sys
from PySide6.QtWidgets import QApplication, QMainWindow, QLabel, QVBoxLayout, QWidget, QLineEdit, QPushButton, QListView, QMessageBox
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

        self.add_button = QPushButton("Add Task")
        self.add_button.clicked.connect(self.add_task)
        self.layout.addWidget(self.add_button)

        self.remove_button = QPushButton("Remove Selected Task")
        self.remove_button.clicked.connect(self.remove_task)
        self.remove_button.setEnabled(False)  # Initially disable remove button
        self.layout.addWidget(self.remove_button)

        # Connect selection change to enable/disable remove button
        self.task_list.selectionModel().selectionChanged.connect(self.update_remove_button_state)

        self.update_task_list()

    def add_task(self):
        task = self.task_input.text().strip()  # Strip leading/trailing spaces
        if task:
            if task not in self.tasks:  # Prevent duplicate tasks
                self.tasks.append(task)
                self.task_input.clear()
                self.update_task_list()
            else:
                self.show_message("Error", "Task already exists.")
        else:
            self.show_message("Input Error", "Task cannot be empty.")

    def remove_task(self):
        selected_index = self.task_list.currentIndex()
        if selected_index.isValid():
            task = self.tasks[selected_index.row()]
            self.tasks.remove(task)
            self.update_task_list()

    def update_task_list(self):
        # Update the list model and clear selection
        self.task_list.setModel(QStringListModel(self.tasks))
        self.task_list.clearSelection()

    def update_remove_button_state(self):
        # Enable or disable the remove button based on selection
        self.remove_button.setEnabled(self.task_list.currentIndex().isValid())

    def show_message(self, title, message):
        msg_box = QMessageBox(self)
        msg_box.setWindowTitle(title)
        msg_box.setText(message)
        msg_box.setIcon(QMessageBox.Warning)
        msg_box.exec()

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = TodoListApp()
    window.show()
    sys.exit(app.exec())
