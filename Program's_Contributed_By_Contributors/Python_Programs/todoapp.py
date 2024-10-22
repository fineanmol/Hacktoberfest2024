import sys
from PySide6.QtWidgets import QApplication, QMainWindow, QLabel, QVBoxLayout, QWidget, QLineEdit, QPushButton, QListView
from PySide6.QtCore import QStringListModel

# Main class for the Todo List application
class TodoListApp(QMainWindow):
    def __init__(self):
        super().__init__()  # Initialize the parent QMainWindow class
        self.setWindowTitle("Todo List App")  # Set the window title
        self.setGeometry(100, 100, 400, 300)  # Set the window size and position

        self.tasks = []  # Initialize an empty list to hold tasks

        self.central_widget = QWidget()  # Create a central widget for the main window
        self.setCentralWidget(self.central_widget)  # Set the central widget

        self.layout = QVBoxLayout()  # Create a vertical box layout
        self.central_widget.setLayout(self.layout)  # Set the layout for the central widget
        
        # Create a QListView to display tasks
        self.task_list = QListView()
        self.task_list.setEditTriggers(QListView.NoEditTriggers)  # Disable editing of list items
        self.task_list.setSelectionMode(QListView.SingleSelection)  # Allow only single item selection
        self.layout.addWidget(self.task_list)  # Add the task list to the layout
        
        # Create a label to prompt user for input
        self.label = QLabel("Enter a task:")
        self.layout.addWidget(self.label)  # Add the label to the layout

        # Create a QLineEdit for task input
        self.task_input = QLineEdit()
        self.layout.addWidget(self.task_input)  # Add the input field to the layout

        # Create a button to add tasks
        self.add_button = QPushButton("Add")
        self.add_button.clicked.connect(self.add_task)  # Connect button click to add_task method
        self.layout.addWidget(self.add_button)  # Add the button to the layout

        # Create a button to remove tasks
        self.remove_button = QPushButton("Remove")
        self.remove_button.clicked.connect(self.remove_task)  # Connect button click to remove_task method
        self.layout.addWidget(self.remove_button)  # Add the button to the layout

        self.update_task_list()  # Initial call to populate the task list

    # Method to add a task from the input field
    def add_task(self):
        task = self.task_input.text()  # Get the text from the input field
        if task:  # Check if the input is not empty
            self.tasks.append(task)  # Add the task to the list
            self.task_input.clear()  # Clear the input field
            self.update_task_list()  # Update the displayed task list

    # Method to remove the selected task from the list
    def remove_task(self):
        selected_index = self.task_list.currentIndex()  # Get the currently selected index
        if selected_index.isValid():  # Check if the selection is valid
            task = self.tasks[selected_index.row()]  # Get the task at the selected index
            self.tasks.remove(task)  # Remove the task from the list
            self.update_task_list()  # Update the displayed task list

    # Method to update the task list view
    def update_task_list(self):
        self.task_list.setModel(QStringListModel(self.tasks))  # Set the model for the task list view

# Entry point for the application
if __name__ == "__main__":
    app = QApplication(sys.argv)  # Create the application instance
    window = TodoListApp()  # Create an instance of the TodoListApp
    window.show()  # Show the application window
    sys.exit(app.exec())  # Execute the application and exit when done
