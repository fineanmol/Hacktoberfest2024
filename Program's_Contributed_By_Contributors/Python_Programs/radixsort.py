# Implementation of the Queue ADT using a linked list.
class lQueue :

  # Creates an empty queue.
  def __init__( self ):
    self._qhead = None 
    self._qtail = None 
    self._count = 0

  # Returns True if the queue is empty.
  def isEmpty( self ):
    return self._qhead is None

  # Returns the number of items in the queue.
  def __len__( self ):
    return self._count

  # Adds the given item to the queue.
  def enqueue( self, item ):
    node = _QueueNode( item ) 

    if self.isEmpty() :
      self._qhead = node 
    else :
      self._qtail.next = node

    self._qtail = node
    self._count += 1

  # Removes and returns the first item in the queue.
  def dequeue( self ):
    assert not self.isEmpty(), "Cannot dequeue from an empty queue." 
    node = self._qhead

    if self._qhead is self._qtail :
      self._qtail = None

    self._qhead = self._qhead.next 
    self._count -= 1
    return node.item

  # Private storage class for creating the linked list nodes.
class _QueueNode( object ):
  def __init__( self, item ):
    self.item = item
    self.next = None

#### Sorts a sequence of positive integers using the radix sort algorithm.

def radixSort( intList, numDigits ):

    # Create a list of queues to represent the bins.
    binArray = [-1]*10 
    for k in range( 10 ):
        binArray[k] = lQueue()

    # The value of the current column.
    column = 1

    # Iterate over the number of digits in the largest value.
    for d in range( numDigits ):
        # Distribute the keys across the 10 bins.
        for key in intList :
            digit = (key // column) % 10 
            binArray[digit].enqueue( key )

        # Gather the keys from the bins and place them back in intList.
        i=0
        for bin in binArray :
            while not bin.isEmpty() : 
                intList[i] = bin.dequeue() 
                i += 1
         # Advance to the next column value.
        column *= 10

    return(intList)
