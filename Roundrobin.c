#include<stdio.h> 
#include<stdlib.h>

int max(int a, int b) 
{ 
    return a > b ? a : b;
}

struct process 
{
int id, arrival_time, burst_time, completion_time, turnaround_time, waiting_time, response_time; int first_response_time, bt_remaining;
int isVisited, isFRTSet;
};

struct ganttNode 
{
int id, start, end; 
struct ganttNode *next;
};

void deallocateGanttNode(struct ganttNode *head) 
{ 
    if(head == NULL) 
    {
return;
}
deallocateGanttNode(head->next); 
free(head);
}

void displayQuestion(struct process *p, int n) 
{
printf("\n");
printf("INPUT\n"); 
printf("P#\tAT\tBT\n"); 
for(int i = 0; i < n; i++) 
{
printf("P%d\t%d\t%d\t\n", p[i].id, p[i].arrival_time, p[i].burst_time);
}
}

void display(struct process *p, int n, struct ganttNode *head, float avg_tat, float avg_wt, float avg_rt) 
{
    printf("\n");
printf("OUTPUT \n\n"); 
printf("P#\tAT\tBT\tCT\tTAT\tWT\tRT\n");
for(int i = 0; i < n; i++)
{
printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].arrival_time, p[i].burst_time, p[i].completion_time, p[i].turnaround_time, p[i].waiting_time, p[i].response_time);
}

printf("\nGantt Chart:\n");

struct ganttNode *temp = head; 
while(temp != NULL) 
{
printf("      ");
temp = temp->next;
}
printf("\n"); 
temp = head;
while(temp != NULL)
{ 
    if(temp->id != -1) 
    {
printf("| P%d ",temp->id);
} 
else 
{
printf("| -- ");
}
temp = temp->next;
}
printf("|\n"); 
temp = head;
while(temp != NULL) 
{ 
    printf("    ");
temp = temp->next;
}
printf("\n"); 
temp = head;
printf("%d",temp->start);
if(temp->end < 10) 
{ 
    printf("    ");
} 
else if (temp->end < 100) 
{ 
    printf("    ");
}
temp = head; 
while(temp != NULL) 
{
printf("%d",temp->end); 
if(temp->next != NULL) 
{
if(temp->next->start < 10) 
{ 
    printf("    ");
} 
else if (temp->next->start < 100) 
{ 
    printf("    ");
}
}
temp = temp->next;
}
printf("\n\n");
printf("Average Turnaround Time = %f\n", avg_tat); 
printf("Average Waiting Time = %f\n", avg_wt); 
printf("Average Response Time = %f\n", avg_rt);
printf("\n");
}

void mergeAT(struct process *arr, int start, int mid, int end) 
{
struct process *temp = (struct process*)malloc((end-start+1)*sizeof(struct process)); 
int i = start, j = mid+1, k = 0;
while(i <= mid && j <= end) 
{
if(arr[i].arrival_time <= arr[j].arrival_time) 
{ 
    temp[k++] = arr[i++];
} 
else
{
temp[k++] = arr[j++];
}
}
while(i <= mid) 
{ 
    temp[k++] = arr[i++];
}
while(j <= end) 
{ 
    temp[k++] = arr[j++];
}
k = 0;
while(start <= end) 
{ 
    arr[start++] = temp[k++];
}
free(temp); 
return;
}

void mergeSortAT
(struct process *arr, int start, int end) 
{ 
    if(start >= end) 
    {
return;
}
int mid = (start+end)/2; mergeSortAT(arr, start, mid); mergeSortAT(arr, mid+1, end); 
mergeAT(arr, start, mid, end);
return;
}

void mergeID(struct process *arr, int start, int mid, int end) 
{
struct process *temp = (struct process*)malloc((end-start+1)*sizeof(struct process)); 
int i = start, j = mid+1, k = 0;
while(i <= mid && j <= end) 
{ 
    if(arr[i].id <= arr[j].id) 
    {
temp[k++] = arr[i++];
} 
else 
{
temp[k++] = arr[j++];
}
}
while(i <= mid) 
{ 
    temp[k++] = arr[i++];
}
while(j <= end)
{ 
    temp[k++] = arr[j++];
}
k = 0;
while(start <= end) 
{ 
    arr[start++] = temp[k++];
}
free(temp); 
return;
}

void mergeSortID(struct process *arr, int start, int end) 
{ 
    if(start >= end) 
    {
return;
}
int mid = (start+end)/2; 
mergeSortID(arr, start, mid); 
mergeSortID(arr, mid+1, end); 
mergeID(arr, start, mid, end); 
return;
}

int main() 
{
int n, time_quantum;
printf("Round Robin (RR) Scheduling Algorithm :\n");
printf("Enter the number of process: "); 
scanf("%d", &n);
struct process *p = (struct process*)malloc(n * sizeof(struct process)); 
for(int i = 0; i < n; i++) 
{
p[i].id = i+1;
printf("Enter Arrival Time & Burst Time for P%d: ", i+1); 
scanf("%d", &p[i].arrival_time);
scanf("%d", &p[i].burst_time); 
p[i].bt_remaining = p[i].burst_time; 
p[i].isVisited = 0;
p[i].isFRTSet = 0;
}
printf("Enter Time Quantum: "); 
scanf("%d", &time_quantum); 
displayQuestion(p, n);

 
mergeSortAT(p, 0, n-1);
int queue[100], front = -1, rear = -1; front = rear = 0;
queue[rear] = 0;
p[0].isVisited = 1;

int time = 0, completedCount = 0, sum_tat = 0, sum_wt = 0, sum_rt = 0; 
struct ganttNode *head = NULL, *tail = NULL;

while(completedCount != n) 
{ 
    int index = queue[front]; 
    front++;

if(p[index].arrival_time > time) 
{
struct ganttNode *newNode = (struct ganttNode*)malloc(sizeof(struct ganttNode)); 
newNode->id = -1;
newNode->next = NULL; 
newNode->start = time;
newNode->end = p[index].arrival_time; 
if(head == NULL) 
{
head = newNode; tail = newNode;
} 
else 
{
tail->next = newNode; 
tail = newNode;
}
}

if(p[index].isFRTSet == 0) 
{
p[index].first_response_time = max(time, p[index].arrival_time);
p[index].isFRTSet = 1;
time = p[index].first_response_time;
}

int currentStart = max(time, p[index].first_response_time);

if(p[index].bt_remaining - time_quantum > 0) 
{ 
    p[index].bt_remaining -= time_quantum; time += time_quantum;
}
else 
{
time += p[index].bt_remaining; p[index].bt_remaining = 0; p[index].completion_time = time;
p[index].turnaround_time = p[index].completion_time - p[index].arrival_time; 
p[index].waiting_time = p[index].turnaround_time - p[index].burst_time; 
p[index].response_time = p[index].first_response_time - p[index].arrival_time;

sum_tat += p[index].turnaround_time; 
sum_wt += p[index].waiting_time; 
sum_rt += p[index].response_time; 
completedCount++;
}

if(head != NULL && tail->id == p[index].id) 
{ 
    tail->end = time;
} 

else {
struct ganttNode* newNode = (struct ganttNode*)malloc(sizeof(struct ganttNode)); 
newNode->id = p[index].id;
newNode->start = currentStart; 
newNode->end = time;
newNode->next = NULL; 
if(head == NULL) 
{
head = newNode; 
tail = newNode;
} 
else 
{
tail->next = newNode;
tail = newNode;
}
}

for(int i = 1; i < n; i++) 
{
if(p[i].bt_remaining > 0 && p[i].arrival_time <= time && p[i].isVisited == 0) 
{ 
    queue[++rear] = i;
p[i].isVisited = 1;
}
}

if(p[index].bt_remaining > 0) 
{ 
    queue[++rear] = index;
}

if(front > rear) 
{
for(int i = 1; i < n; i++) 
{ 
    if(p[i].bt_remaining > 0) 
    {
queue[++rear] = i; 
p[i].isVisited = 1;
break;
}
}
}
}
float avg_tat = (float)sum_tat / n; 
float avg_wt = (float)sum_wt / n; 
float avg_rt = (float)sum_rt / n; 
mergeSortID(p, 0, n-1);
display(p, n, head, avg_tat, avg_wt, avg_rt);

free(p); 
deallocateGanttNode(head); return 0;
}

