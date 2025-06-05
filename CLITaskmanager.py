import argparse
import json
import os


TASKS_FILE = 'tasks.json'


def load_tasks():
    if os.path.exists(TASKS_FILE):
        with open(TASKS_FILE, 'r') as f:
            return json.load(f)
    return []


def save_tasks(tasks):
    with open(TASKS_FILE, 'w') as f:
        json.dump(tasks, f, indent=4)


def add_task(description, priority=1):
    tasks = load_tasks()
    tasks.append({'description': description, 'priority': priority, 'completed': False})
    save_tasks(tasks)
    print(f"Added task: {description}")


def list_tasks():
    tasks = load_tasks()
    for i, task in enumerate(tasks, 1):
        status = "Done" if task['completed'] else "Pending"
        print(f"{i}. {task['description']} - Priority: {task['priority']} - Status: {status}")


def complete_task(index):
    tasks = load_tasks()
    if 0 <= index < len(tasks):
        tasks[index]['completed'] = True
        save_tasks(tasks)
        print(f"Task {index + 1} marked as completed.")
    else:
        print("Invalid task number.")


def delete_task(index):
    tasks = load_tasks()
    if 0 <= index < len(tasks):
        removed_task = tasks.pop(index)
        save_tasks(tasks)
        print(f"Deleted task: {removed_task['description']}")
    else:
        print("Invalid task number.")


parser = argparse.ArgumentParser(description="Simple CLI Task Manager")
subparsers = parser.add_subparsers(dest='command')

add_parser = subparsers.add_parser('add', help='Add a new task')
add_parser.add_argument('description', type=str, help='Task description')
add_parser.add_argument('--priority', type=int, default=1, help='Task priority (default: 1)')


list_parser = subparsers.add_parser('list', help='List all tasks')


complete_parser = subparsers.add_parser('complete', help='Mark a task as complete')
complete_parser.add_argument('index', type=int, help='Task number to complete (1-based index)')


delete_parser = subparsers.add_parser('delete', help='Delete a task')
delete_parser.add_argument('index', type=int, help='Task number to delete (1-based index)')


args = parser.parse_args()
if args.command == 'add':
    add_task(args.description, args.priority)
elif args.command == 'list':
    list_tasks()
elif args.command == 'complete':
    complete_task(args.index - 1)
elif args.command == 'delete':
    delete_task(args.index - 1)
else:
    parser.print_help()
