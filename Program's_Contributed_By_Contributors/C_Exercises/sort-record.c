#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100
#define MAX_AGE 150
#define MIN_AGE 0

typedef struct {
    char *name;
    int age;
} record;

record * rec_hand_create(int n); // Create a record array
void rec_sort(record * v, int n); // Sort the records
void rec_print(record * v, int n); // Print the records
void rec_free(record * v, int n); // Deallocate structure


int main(void) {
    int n;
    record *v;

    printf("Enter the number of records: ");
    scanf("%d", &n);

    v = rec_hand_create(n);
    rec_sort(v, n);
    rec_print(v, n);
    rec_free(v, n);

    rec_print(v, n);

    printf("%p", *v);

    return 0;

}

// Random number of characters within MAX_LEN
// Random age between MIN_AGE and MAX_AGE
record * rec_hand_create(int n) {
    record *v = malloc(n * sizeof(record));
    for (int i = 0; i < n; i++) {
        v[i].name = malloc(MAX_LEN * sizeof(char));
        for (int j = 0; j < MAX_LEN; j++) {
            v[i].name[j] = 'a' + rand() % 26;
        }
        v[i].age = rand() % (MAX_AGE - MIN_AGE + 1) + MIN_AGE;
    }
    return v;
}

void rec_sort(record *v, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i].age > v[j].age) {
                record temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

// Pretty print the array of records
void rec_print(record *v, int n) {
    for(int i = 0; i < n; i++) {
        printf("Name: %s\nAge: %d\n\n", (v + i)-> name, (v + i)->age);
    }
}


void rec_free(record *v, int n) {
    for (int i = 0; i < n; i++) {
        free(v[i].name);
    }
    free(v); // free and open source
}

