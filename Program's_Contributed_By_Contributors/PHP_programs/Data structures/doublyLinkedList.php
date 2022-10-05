<?php
// Instantiating an object of class SplDoublyLinkedList
$dlist = new SplDoublyLinkedList();

// Inserting elements at the end of the list
$dlist->push('php');
$dlist->push('doubly');
$dlist->push('linkedList');

// Displaying the list
echo "Original List : ";
for ($dlist->rewind(); $dlist->valid(); $dlist->next()) {
	echo $dlist->current()." ";
}

// Deleting element from the end of the list
$dlist->pop();

// Adding a new element at specific index
// Add 'code' at index 2
$dlist->add(2, "code");

// Displaying the updated list
echo "\n<br>Updated List : ";
for ($dlist->rewind(); $dlist->valid(); $dlist->next()) {
	echo $dlist->current()." ";
}

// Printing the count of nodes
echo "\n<br>Total nodes = " . $dlist->count() . "<br>";

// Printing the node at top of the list
echo "Top node = ". $dlist->top() . "<br>";

// Printing the node at bottom of the list
echo "Bottom node = " . $dlist->bottom() . "\n";
