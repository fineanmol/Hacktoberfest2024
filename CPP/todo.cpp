#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QListView>
#include <QStringListModel>
#include <QMessageBox>

class TodoListApp : public QMainWindow {
    Q_OBJECT

public:
    TodoListApp(QWidget *parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("Todo List App");
        setGeometry(100, 100, 400, 300);

        tasks = new QStringListModel(this);

        // Central widget setup
        central_widget = new QWidget(this);
        setCentralWidget(central_widget);

        // Layout setup
        layout = new QVBoxLayout();
        central_widget->setLayout(layout);

        // Task list setup
        task_list = new QListView(this);
        task_list->setEditTriggers(QListView::NoEditTriggers);
        task_list->setSelectionMode(QListView::SingleSelection);
        layout->addWidget(task_list);
        task_list->setModel(tasks);

        // Label and input for tasks
        label = new QLabel("Enter a task:");
        layout->addWidget(label);
        task_input = new QLineEdit(this);
        layout->addWidget(task_input);

        // Add button setup
        add_button = new QPushButton("Add", this);
        layout->addWidget(add_button);
        connect(add_button, &QPushButton::clicked, this, &TodoListApp::add_task);

        // Remove button setup
        remove_button = new QPushButton("Remove", this);
        layout->addWidget(remove_button);
        connect(remove_button, &QPushButton::clicked, this, &TodoListApp::remove_task);
    }

private slots:
    void add_task() {
        QString task = task_input->text();
        if (!task.isEmpty()) {
            tasks_list.append(task);
            tasks->setStringList(tasks_list);
            task_input->clear();
        } else {
            QMessageBox::warning(this, "Input Error", "Task cannot be empty.");
        }
    }

    void remove_task() {
        QModelIndex selected_index = task_list->currentIndex();
        if (selected_index.isValid()) {
            tasks_list.removeAt(selected_index.row());
            tasks->setStringList(tasks_list);
        } else {
            QMessageBox::warning(this, "Selection Error", "Please select a task to remove.");
        }
    }

private:
    QStringListModel *tasks;
    QStringList tasks_list;

    QWidget *central_widget;
    QVBoxLayout *layout;
    QListView *task_list;
    QLabel *label;
    QLineEdit *task_input;
    QPushButton *add_button;
    QPushButton *remove_button;
};

#include "todo.moc"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    TodoListApp window;
    window.show();
    return app.exec();
}
