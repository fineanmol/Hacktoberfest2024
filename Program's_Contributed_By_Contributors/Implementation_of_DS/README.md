# Linked List

## What is a Linked List? 

A Linked List is a sequence of data structures, which are connected together via links i.e sequence of links which contains items. They include a series of connected nodes and each node stores the following :
- data item (i.e integer, strings etc)
- address of next node (connects one node to another)

Here is pictorial representation of a linked list :

![Linked-List](https://media.geeksforgeeks.org/wp-content/uploads/20220816144425/LLdrawio.png)

It has the following properties 
- If first node is empty, value of head points to NULL
- Successive elements are connected by pointer
- Last element points to NULL
- first node called the head of linked list
- Can grow or shrink in size during program execution
- Can be made as long as required.

## Types of Linked Lists:
**Simple Linked List**
: In this type, one can move or traverse the linked list in one direction.

**Doubly Linked List**
: In this type, one can traverse the linked list in both directions i.e forward or backward.

**Circular Linked List**
: Linked list in which the first and the last nodes are also connected to each other to form a circle. Here, the address of the last node consists of the address of the first node.

### How do we represent a node in C ?

In C, we represent a node using structures. Example below :
```
struct Node 
{
    int data;
    struct Node* next;
}
```
This is a node with an integer data type.

We can also represent a node as follows :
```
/**
 * struct listint_s - singly linked list
 * @data: integer type
 * @next: points to next node
 * Description: singly linked list node structure
 */

 typedef struct listint_s
 {
    int data;
    struct listint_s *next
 } listint_t;
```
We have used `typedef` to define a new data type. This data type can be used to define structure variables directly.

- `typedef` allows users to provide alternative names for the primitive (e.g int) and user defined (e.g struct) data types. This keyword adds a new name for existing data type but does not create a new type. Click [here](https://www.educative.io/answers/how-to-use-the-typedef-struct-in-c) to learn more about `typedef` and `struct` in C.

We will create a simple linked list with three nodes containing different integers :
 
 ---

 ## Header File
**`header.h`** file contains function declaration and macro definitions to be shared with various source files. At the source files the header file is included using the preprocessing directive `#include "header.h"`. The construct of the header file is a **wrapper *`#ifndef`*** and this is the format used :

```
#ifndef _HEADER_
#define _HEADER_

The entire header file

#endif
```
---
 ## Printing a list
**`printList.c`** file contains code to print a Linked List. It print the data in the first node and updates the value to the next node. The loop ends when the data is NULL.

### Visual Representation of printing Linked List
![Print_LList](https://www.log2base2.com/images/ds/print-linked-list.png)
 
 ---

 ## Inserting a node
 We now have a linked list with three integers. We can insert a new node in the linked list in three ways :
 - At front of linked list
 - After given node
 - At end of linked list.
 
 ### **1. Inserting node at front**
 When a new node is added before the head of a given Linked List, it becomes the new head node of the list. Example if the Linked List is 2->4->6 and we want to add 5 at the front, the list becomes 5->2->4->6. Let us call the function insertHead(). The function must receive a pointer to head pointer since it changes the head pointer to point to new node.

  ![Insert_head](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist_insert_at_start.png)

  #### Complexity Analysis
  - **Time Complexity** : O(1), we have a pointer to head and can directly add a node and change pointer. So time complexity of inserting node at head is O(1) as it does constant amount of time.
  - **Auxillary Space** : O(1).


  ### **2. Inserting node at nth position**
  We are given pointer to a node, and new node is inserted after given node.
  Steps include :
  - Check if previous node is NULL or not.
  - Allocate new node and assign data to new node
  - Make next of new node as next of previous node
  - Move next of previous node as new node.

  ![Insert_nth](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist_insert_middle.png)

  #### Complexity Analysis
  - **Time Complexity** : O(N), where N is size of linked list.

  - **Auxiliary Space** : O(1) since using constant space to modify pointers.

   ### **3. Inserting node at end**
   New node is always added after last node. Since a Linked List is typically represented by head we have to traverse till end then change next to last node to a new node.

   ![insert_end](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist_insert_last.png)

   #### Complexity Analysis
  **Time Complexity** : O(N), where N is number of nodes in linked list. Since there is loop frim head to end, function O(n) work.

        The method can be optimized to work in O(1) by keeping extra pointer to tail of linked list.

  **Auxiliary Space** : O(1)

---
## Deleting a node
**`delete.c`** contains code for deletion of a node from a Linked List from the beginning(head), end, whole list and deleting from any position.

### Deleting from Beginning
We will create a variable to store original head value and make the next node to be equal to head. We then free the unused memory of the variable created.
 
### Deleting from End
We create a variable that is equal to head of Linked List and then loop through while updating the value of temporary variable. We then make the last node value equal to NULL. This will delete the value of last node.

### Deleting whole List
This are steps used to delete whole Linked List :
1. Create temp variable to store head value.
2. Introduce a loop and make next node equal to the temp variable
3. Free the temporary value
4. Make value of head equal to temp value

- **Time Complexity:** O(n)
- **Auxiliary Space:** O(1)

### Deleting from any positiom
This function takes two parameters i.e pointer to head and position to be deleted. 
1. First, create a temp variable pointing to head
2. If position to be deleted is 0 it prints the value and advances the head pointer to next value.
3. To delete at specific position, temp point to previous node of node to be deleted.
4. Delete pointer point to node to be deleted i.e by using `temp->next->next`
5. Remember to free the node

- **Best Case:** O(1) if given position is 1
- **Average & Worst Case:** O(N) if position given is size - 1 then need to traverse till position not found
- **Space Complexity:** O(1) no extra space required

---

## Reversing Linked List
**`reverse.c`** contains code to reverse a Linked List using three methods :
- Iterative method
- Tail Recursive Approach
- Head Recursive Approach

### Iterative 
1. Initializing 3 pointers. previous and next as NULL, current as head
2. Iterate through linked list. In loop do following:
  - store next node as next i.e `next = current->next`
  - change next of current. Reversing happens i.e `current->next=prev`
  - move previous and current one step forward
    -`previous = current` & `current->next`
3. Outside loop make head value as previous

Visual representation is as shown:

![Reversing Iteratively](https://media.geeksforgeeks.org/wp-content/cdn-uploads/RGIF2.gif) 

- **Time Complexity:** O(n)
- **Auxiliary Space:** O(1)

### Tail Recursive Method
The `reverseTail` function takes three parameters i.e current, previous and head. The if statement marks the last node as head and updates the next to previous node. Outside if statement, the next struct is saved for recursive call and the next is updated. 

In the `reverseTailRec` function it calls the `reverseTail` with the three parameters as (*head, NULL, head) i.e current as pointer to head, previous passed NULL, and head value

- **Time Complexity:**: O(N) We do certain operation for every node of linked list
- **Auxiliary Space:** O(1) Constant space used


# Stack
A **stack** is a linear data structure that is dynamic in nature and behaves like a real world stack. An exanple of stack is a deck of cards or a pile of plates. A stack follows the principle of **Last In First Out (LIFO)** meaning that the last element inserted in the stack is first removed.

You can take a pile of plates kept on top of other as a real-example. The plate that was last placed on top is,most probably, the first placed to be removed i.e last plate in is the first plate out. If one wants to place a plate at the bottom , you must first remove all the plates on top. Same happens in a deck of cards. This is the principle of Last In First Out.

## Operations on Stack
In order to make manipulations in a stack, there are certain operations provided to us :
- **push(n)** : Insert element into stack
- **pop()** : Remove element from stack
- **peek()/top()** : Return value of top element without removing it
- **isEmpty()** : Return True if stack is empty else false
- **isFull** : Return True if stack full else otherwise
- **size()** : Returns size of stack

### LIFO Principle
![LIFO](https://cdn.programiz.com/sites/tutorial2program/files/stack.png)

## Working of Stack Data Structure
Operations are as follows :

1. A pointer called `top` is used to keep track of top element in stack.
2. When initializing stack, set value to -1 so as to check if stack is empty by comparing `top == -1`.
3. On pushing, increase `top` and place new element in position pointed to `top`.
4. On popping, return element pointed by top and reduce it's value
5. Before pushing, check if stack is full.
6. Before popping, check if stack empty. 

![Working Principle](https://cdn.programiz.com/sites/tutorial2program/files/stack-operations.png)

We will now check algorithms of basic operations

### peek()/top()
Return value of top element without removing it.
Algorithm is as follows :
```
begin procedure peek

    return stack[top]

end precedure
```
### isFull()
Return boolean i.e True if stack full else false.
Algorithm is as follows :
```
begin procedure isFull

    if top equals MAXSIZE
        return true
    else
        return false
    endif

end procedure
```
### isEmpty()
Return boolean i.e True if stack is empty else false.
Algorithm is as follows :
```
begin procedure isEmpty

    if top < 1
        return true
    else
        return false
    endif

end procedure
```
### push(n)
Adding new data element onto a stack where n is data to be inserted. Steps include :
1. Check if stack is full
2. If full, is said to be **overflow** condition.
3. If stack not full, increment top to point to next empty space.
4. Add data element to stack where top is pointing.
5. Return success

Pictorial Representation :


![Push Operation](https://www.tutorialspoint.com/data_structures_algorithms/images/stack_push_operation.jpg)


Algorithm is as follows :
```
begin procedure push

    if stack is full
        return
    endif

    increment top
    stack[top] assign data

end procedure
``` 
### pop()

Process of accessing an element and removing it from stack. In array implementation of stack, data is not actually removed but top is decremented in stack so as to point to next element. In linked list implementation pop removes data element and deallocates memory space.

Steps taken include :
1. Check if stack is empty
2. If stack empty, said to be **underflow** condition.
3. If stack not emty, access data element which top is pointing to.
4. Decrement top by 1
5. Return success.

Pictorial Representation :

![Pop operation](https://www.tutorialspoint.com/data_structures_algorithms/images/stack_pop_operation.jpg)

Algorithm is as follows :
```
begin procedure pop

    if stack is empty
        return
    endif
    
    store value of stack[top]
    decrement top
    return value

end procedure
```

### Complexity Analysis
All the operations perfomed above have a complexity of **O(1)**.

## Stack Implementation
Stack can be implemented using two methods ;
- Using array
- Using Linked List

### Array Implementation of Stack
A stack can be implemented using one-dimensional array. Stack implemented using array stores a fixed number of data values i.e static memory allocation where memory is allocated for declared variables by compiler and memory is allocated during compile time. 

The implementation is very simple. Define a one dimensional array of specific size and perform the basic operations in stack with help of variable called `top`.

Steps taken include :
1. Include all **header files** to be used in program and define `**MAXSIZE**` with specific values
2. Declare **functions** used in stack implementation.
3. Create a one-dimensional array with fixed size i.e `**int stack[MAXSIZE]**`
4. Define integer `top` and initialize with `-1` i.e `top = -1`

### Advantages of array implementation
1. Memory saved as pointers is not used
2. Easier to implement

### Disadvantages of array implementation
1. Not dynamic
2. Does not shrink or grow depending on needs at runtime.

### Linked List Implementation of Stack
We have observed that in implementation of stack using an array, we have to specify the size of an array at beginning i.e at compile time and we therefore cannot change the size of array at runtime. To solve this we can implement a stack using a linked list which allocates memory dynamically. Dynamic memory allocation is done at time of execution (at runtime). Fuctions **malloc()** supports dynamic memory allocation.

In Linked List implementation the nodes are maintained non-contigously in memory. Each node contains a pointer to it's immediate successor node in stack. 

Pictorial representation of stack using linked list is as shown below :


![Stack Linked List](https://static.javatpoint.com/ds/images/ds-linked-list-implementation-stack.png)


### Advantages of linked list implementation
1. Can grow or shrink depending on needs at runtime.
2. It does not waste memory with unoccupied array fields
3. Cleans objects automatically
4. They do not get corrupted easily hence more secure and reliable.

### Disadvantages of linked list implementation
1. Require extra memory due to using pointers.
2. Total size must be defined before
3. Random accessibility not possible.


## Applications of Stack
- **Browsers** - While using a browser the back button saves all the URL's visited in a stack. A new stack is added when visiting a new page and on pressing back the current URL is removed from stack and previous URL accessed

- **Reversing** - Putting all data in a stack and popping them will produce letters in reverse

- **Compilers** - Compilers use stack to calculate value of expression by converting expression to prefix and postfix them. More info [here](https://www.javatpoint.com/applications-of-stack-in-data-structure)

- **Backtracking** - This is a recursive algorithm used for solving optimization problem

- Delimiter or parenthesis checking.

- Undoing operation i.e using `ctrl-z`

- Balancing of parenthesis i.e for each opening parenthesis there is proper closing parenthesis

## Infix, Prefix and Postfix
Infix, Postfix and Prefix notations are three different but equivalent ways of writing expressions. The concept can easily be understood using examples.

- **Operation :** Any Expression of algebraic format (Example : A + B)
- **Operands :** A and B or 5 & 6 are operands
- **Operators :** +. -, %,*,/ etc are operators

### Infix Notation
This is an expression in which an operator appears between operands in an equation. i.e `<operand> <operator> <operand>`. An example is `A * ( B + C) / D`. This is expressed as "First add B & C in brackets, then multiply A by the sum, them finally divide by D".

This is the rule of precedence and associativity of operators.

Infix notation needs information to make the order of evaluation of operators clear: rules built into language about operator precedence and associativity, and brackets () to allow users to override these rules. Example, rule of associativity says we perform operations from left to right, so in the expression multiplication comes first. Similarly rules of precedence say we perform operations in this order :
```
1. () {} []
2. ^ i.e power
3. * / multiplication and division
4. + - addition and subtraction
```
### Prefix Notation / Polish Notation
An expression is called prefix if the operators appears in the expression before operands i.e `<operator> <operand> <operand>` example `/ * A + B C D`.

Although prefix "operators are evaluated left-to-right", they use values to their right and if these values involves computations then it changes order that operators have to be evaluated. In the example, although division is first operator on left, it acts on result of multiplication, therefore multiplication happens before (addition will come before multiplication as well).
Adding brackets the expression becomes `(/ (* A (+ B C) ) D )`
Another example :
```
Input :  Prefix :  *+AB-CD
Output : Infix : ((A+B)*(C-D))

Input :  Prefix :  *-A/BC-/AKL
Output : Infix : ((A-(B/C))*((A/K)-L))
```

### Postfix Notation / Reverse Polish Notation
An expression is called postfix if the operators appears in the expression after operands i.e `A B C + * D /`

Order of evaluation is "left to right" and brackets cannot change order. Since `+` is to left of `*` addition is therefore perfomed before multiplication. Operators act on values to left of them example "+" acts on "B" and "C". Simpler version is `((A (B C +) *) D / )`. Thus, the `*` uses the two values immediately preceding: "A", and the result of the addition. Similarly, the `/` uses the result of the multiplication and the "D".

## Infix to Postfix 
Converting an infix notation to postfix is among one application of stack. An expression for example `a + b * (c + d)` can be converted to postfix equivalent `abcd + * +` when an operand appears before an operator. 

The compiler scans the expression either from left to right or from right to left. Consider the expression above. The compiler first scans expression `c + d`, to become `cd +` as one single operand. Scanning from left, compiler will now evaluate `b * (cd +)`(putting in brackets to make it one operand). The expression will be evaluated to become `bcd + *`. Final step after scanning from left the expression becomes `a + (bcd + *)` and the result will be `abcd + * +`. Please note Precedence and Associative rule of operators.

### Steps to convert Infix expression to Postfix expression using Stack:
- Scan infix from left to right
- If scanned character is operand, output it.
- Else,
    - If precedence and associativity of scanned operator are greater than precedence and associativity of operator in stack(or stack empty or contain `(`) then push it.
    - `^` operator is right associative and other operators like `+ - * /` are left associative. Check for condition when both ,operator at top of stack and scanned operator are `^`. In this condition, precedence of scanned operator is high hence will be pushed into operator in stack. When top of operator stack is same as scanned operator, then pop operator from stack because of left associativity due to which scanned operator has less precedence.
      - Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
- If scanned char is `(`, push to stack
- If `)`, pop stack and output till `(` found and discard all parenthesis.
- Repeat above steps till infix expression scanned and print output
- Pop and output from stack until not empty


This can be implemented using :
- Linked List implemented in `InfToPostLL.c` file
- Arrays implemented in `InfToPostArray.c` file.

- **Time Complexity :** O(N), N is size of infix expression

- **Auxiliary Space :** O(N)

## Infix to Prefix
Converting an infix notation to prefix is among one application of stack. An expression for example `a + b * (c + d)` can be converted to postfix equivalent `+ a * b + cd` where an operator appear before operands.

The compiler will scan the operator from left to right. Considering the expression above the compiler will first evaluate expression `c + d` to become `+ cd` according to order of precedence where brackets is of higher precedence. Next will be `b * (+ cd)` to become `* b + cd` (remember `+ cd` considered as one operand). Lastly, `a + (* b + cd)` evaluated to `+ a * b + cd` which is the prefix equivalent.

### Steps to convert Infix expression to Prefix expression using Stack:

1. Reverse the infix expression and scan expression from left to right.

2. If an operand print out operand
3. If operator and stack is empty, push the operator to the stack
4. If the incoming operator has *higher precedence* than top of stack, push the incoming operator into stack
5. If incoming operator has *same precedence* as that of top of stack, push incoming operator into stack
6. If incoming operator has lower precedence than top of stack. pop and print top of stack. test incoming operator against top of stack and pop whenever operator finds an operator of lower or same precedence.
7. If incoming operator has same precedence with top of stackand incoming operator is `^` then pop top of stack till condition is true. If not true push `^`
8. Pop and print all operators from top of stack when reaching end of expression
9. If operator is `)` push to stack
10. If operator is `(` pop all operator till `)` is found
11. If top of stack is `)` push operator on stack and reverse output

### Pseudocode

```
Function InfixtoPrefix(stack, infix)
infix = reverse(infix)
loop i = 0 to infix.length
if infix[i] is operand -> prefix += infix[i]
else if infix[i] is ( -> stack.push(infix[i])
else if infix[i] is ) -> pop & print stack till ) 
else if infix[i] is an operator

    if stack isEmpty
        push.infix[i] on top of stack

    else if precedence(infix[i] > precedence(stack.top)) 
        push infix[i] on top of stack

    else if (infix[i] == prcedence(stack.top) && infix[i] == ^)
        pop & print top values till true
        push infix[i]

    else if (infix[i] == precedence(stack.top))
        push infix[i] on stack

    else if (infix[i] < precedence(stack.top))
        pop stack & print till stack not empty &infix[i] < precedence(stack.top)

    push infix[i] onto stack
    end loop
pop and print remaining elements
prefix = reverse(prefix)
return 
```
This can be implemented using :
- Linked List implemented in `InfToPreLL.c` file
- Arrays implemented in `InfToPreArray.c` file.

## Postfix to Infix

## Prefix to Infix


## References
1. [Stack Data Structure using Array](http://www.btechsmartclass.com/data_structures/stack-using-array.html)

2. [Infix, Prefix and Postfix](https://www.cs.man.ac.uk/~pjj/cs212/fix.html)

3. [Infix to Postfix](https://www.codewithharry.com/videos/data-structures-and-algorithms-in-hindi-37/)