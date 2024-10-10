import kivy
from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.recycleview import RecycleView
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button


class TodoRecycleView(RecycleView):
    def __init__(self, **kwargs):
        super(TodoRecycleView, self).__init__(**kwargs)
        self.data = []


class TodoApp(App):
    def build(self):
        self.tasks = []
        self.layout = BoxLayout(orientation="vertical")

        # RecycleView for displaying tasks
        self.rv = TodoRecycleView()
        self.layout.add_widget(self.rv)

        # TextInput for adding tasks
        self.task_input = TextInput(hint_text="Enter a task", multiline=False)
        self.layout.add_widget(self.task_input)

        # Add and Remove buttons
        self.add_button = Button(text="Add Task")
        self.add_button.bind(on_press=self.add_task)
        self.layout.add_widget(self.add_button)

        self.remove_button = Button(text="Remove Selected Task")
        self.remove_button.bind(on_press=self.remove_task)
        self.layout.add_widget(self.remove_button)

        return self.layout

    def add_task(self, instance):
        task = self.task_input.text
        if task:
            self.tasks.append({"text": task})
            self.rv.data = self.tasks
            self.task_input.text = ""

    def remove_task(self, instance):
        if self.rv.data:
            self.rv.data.pop()
            self.rv.refresh_from_data()


if __name__ == "__main__":
    TodoApp().run()
