#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TASK_FILE "tasks.txt"
#define MAX_TASK_LEN 100

typedef struct {
    char description[MAX_TASK_LEN];
    int priority;
    int completed;
} Task;

void add_task(const char *description, int priority) {
    FILE *file = fopen(TASK_FILE, "a");
    if (!file) {
        perror("Could not open file");
        return;
    }
    fprintf(file, "%s,%d,%d\n", description, priority, 0);
    fclose(file);
    printf("Added task: %s\n", description);
}

void list_tasks() {
    FILE *file = fopen(TASK_FILE, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }
    char line[128];
    int index = 1;
    while (fgets(line, sizeof(line), file)) {
        Task task;
        sscanf(line, "%[^,],%d,%d", task.description, &task.priority, &task.completed);
        printf("%d. %s - Priority: %d - Status: %s\n", index++, task.description, task.priority, task.completed ? "Done" : "Pending");
    }
    fclose(file);
}

void complete_task(int task_number) {
    FILE *file = fopen(TASK_FILE, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }
    FILE *temp_file = fopen("temp.txt", "w");
    if (!temp_file) {
        perror("Could not open temporary file");
        fclose(file);
        return;
    }

    char line[128];
    int index = 1;
    while (fgets(line, sizeof(line), file)) {
        Task task;
        sscanf(line, "%[^,],%d,%d", task.description, &task.priority, &task.completed);
        if (index == task_number) {
            task.completed = 1;
            printf("Task %d marked as completed.\n", task_number);
        }
        fprintf(temp_file, "%s,%d,%d\n", task.description, task.priority, task.completed);
        index++;
    }
    fclose(file);
    fclose(temp_file);
    remove(TASK_FILE);
    rename("temp.txt", TASK_FILE);
}

void delete_task(int task_number) {
    FILE *file = fopen(TASK_FILE, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }
    FILE *temp_file = fopen("temp.txt", "w");
    if (!temp_file) {
        perror("Could not open temporary file");
        fclose(file);
        return;
    }

    char line[128];
    int index = 1;
    while (fgets(line, sizeof(line), file)) {
        if (index != task_number) {
            fputs(line, temp_file);
        } else {
            printf("Deleted task %d\n", task_number);
        }
        index++;
    }
    fclose(file);
    fclose(temp_file);
    remove(TASK_FILE);
    rename("temp.txt", TASK_FILE);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage:\n");
        printf("  %s add <description> <priority>\n", argv[0]);
        printf("  %s list\n", argv[0]);
        printf("  %s complete <task_number>\n", argv[0]);
        printf("  %s delete <task_number>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "add") == 0 && argc >= 4) {
        add_task(argv[2], atoi(argv[3]));
    } else if (strcmp(argv[1], "list") == 0) {
        list_tasks();
    } else if (strcmp(argv[1], "complete") == 0 && argc >= 3) {
        complete_task(atoi(argv[2]));
    } else if (strcmp(argv[1], "delete") == 0 && argc >= 3) {
        delete_task(atoi(argv[2]));
    } else {
        printf("Invalid command.\n");
    }

    return 0;
}
