import sys
from PySide6.QtWidgets import QApplication, QMainWindow, QLabel, QVBoxLayout, QWidget, QLineEdit, QPushButton, QListView
from PySide6.QtCore import QStringListModel, Qt

class TodoListApp(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Todo List App")
        self.setGeometry(100, 100, 400, 300)

        self.tasks = []  # Use a list to maintain task order

        # Central widget and layout
        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)
        self.layout = QVBoxLayout()
        self.central_widget.setLayout(self.layout)

        # Task list view
        self.task_list = QListView()
        self.task_list.setEditTriggers(QListView.NoEditTriggers)
        self.task_list.setSelectionMode(QListView.SingleSelection)
        self.layout.addWidget(self.task_list)

        # Input label and task input field
        self.label = QLabel("Enter a task:")
        self.layout.addWidget(self.label)
        self.task_input = QLineEdit()
        self.task_input.textChanged.connect(self.toggle_add_button)
        self.task_input.returnPressed.connect(self.add_task)  # Press Enter to add
        self.layout.addWidget(self.task_input)

        # Add and Remove buttons
        self.add_button = QPushButton("Add")
        self.add_button.setEnabled(False)  # Disabled initially
        self.add_button.clicked.connect(self.add_task)
        self.layout.addWidget(self.add_button)

        self.remove_button = QPushButton("Remove")
        self.remove_button.setEnabled(False)  # Disabled initially
        self.remove_button.clicked.connect(self.remove_task)
        self.layout.addWidget(self.remove_button)

        self.update_task_list()

    def toggle_add_button(self):
        """Enable Add button only if the task input is not empty or just spaces."""
        self.add_button.setEnabled(bool(self.task_input.text().strip()))

    def toggle_remove_button(self):
        """Enable Remove button only if a task is selected."""
        self.remove_button.setEnabled(self.task_list.currentIndex().isValid())

    def add_task(self):
        task = self.task_input.text().strip()
        if task:
            self.tasks.append(task)  # Add task and keep order
            self.task_input.clear()
            self.update_task_list()

    def remove_task(self):
        selected_index = self.task_list.currentIndex()
        if selected_index.isValid():
            task = self.tasks[selected_index.row()]
            self.tasks.remove(task)
            self.update_task_list()

    def update_task_list(self):
        """Update the task list view with the current tasks."""
        model = QStringListModel(self.tasks)
        self.task_list.setModel(model)

        # Connect the selection changed signal after setting the model
        self.task_list.selectionModel().selectionChanged.connect(self.toggle_remove_button)
        self.toggle_remove_button()  # Update Remove button status

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = TodoListApp()
    window.show()
    sys.exit(app.exec())
