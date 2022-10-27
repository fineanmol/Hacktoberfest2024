#include <iostream>
using namespace std;
#define max 50
typedef struct process
{
    int proc_id;
    int priority;
} process;
void swap(process *a, process *b)
{
    process temp = *a;
    *a = *b;
    *b = temp;
}
void max_heapify(process PQ[], int n, int i)
{
    int largest = i;
    if (2 * i + 1 < n && PQ[2 * i + 1].priority > PQ[largest].priority)
        largest = 2 * i + 1;

    if (2 * i + 2 < n && PQ[2 * i + 2].priority > PQ[largest].priority)
        largest = 2 * i + 2;

    if (largest != i)
    {
        swap(&PQ[i], &PQ[largest]);
        max_heapify(PQ, n, largest);
    }
}
process find_max(process PQ[], int n)
{
    if (n > 0)
        return PQ[0];
    else
        cout << "Priority Queue is empty" << endl;
}
process extract_max(process PQ[], int *n)
{
    if (n > 0)
    {
        process temp = PQ[0];
        PQ[0] = PQ[*n - 1];
        *n = *n - 1;
        max_heapify(PQ, *n, 0);
        return temp;
    }
    else
        cout << "Priority Queue is empty" << endl;
}
void insert(process PQ[], int *n, process new_proc)
{
    *n = *n + 1;
    PQ[*n-1] = new_proc;
    int i = *n-1 ;
    while (i > 0 && PQ[i].priority > PQ[(i) / 2].priority)
    {
        swap(&PQ[i], &PQ[(i) / 2]);
        i = (i) / 2;
    }
}
void increase_key(process PQ[], int n, int index, int new_key)
{
    if(index>=n)
    {
        cout<<"Not Possible"<<endl;
        return;
    }
    if (PQ[index].priority >= new_key)
    {
        cout << "Increment not possible" << endl;
        return;
    }
    else
    {
        PQ[index].priority = new_key;
        int i = index;
        while (i > 0 && PQ[i].priority > PQ[(i) / 2].priority)
        {
            swap(&PQ[i], &PQ[(i) / 2]);
            i = (i) / 2;
        }
    }
}

int main()
{
    process PQ[max], temp, new_proc;
    int choice, priority;
    int index, key;
    int n = 0;
    do
    {
        cout << endl;
        cout << "1. Insert" << endl
             << "2. Extract_Max" << endl
             << "3. Find_max" << endl
             << "4. Increase_key" << endl
             << "5. Print" << endl
             << "6. EXIT" << endl;
        cout << "Which Process you want to perform: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the priority of task: ";
            cin >> new_proc.priority;
            insert(PQ, &n, new_proc);
            break;
        case 2:
            temp = extract_max(PQ, &n);
            cout << "The priority of extracted process is: " << temp.priority << endl;
            break;
        case 3:
            temp = find_max(PQ, n);
            cout << "The maximum priority among all the processes is: " << temp.priority << endl;
            break;
        case 4:
            cout << "Enter the index: ";
            cin >> index;
            cout << "Enter the new priority: ";
            cin >> key;
            increase_key(PQ, n, index, key);
            break;
        case 5:
            if (n == 0)
                cout << "Priority Queue is empty" << endl;
            else
            {
                cout << "The priorities of processes are:" << endl;
                for (int i = 0; i < n; i++)
                {
                    cout << PQ[i].priority << " ";
                }
                cout << endl;
            }
            break;
        default:
            break;
        }
    } while (choice != 6);

    return 0;
}
