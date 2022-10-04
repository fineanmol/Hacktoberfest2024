<?php
/**
* A class that extends SplHeap for showing rankings in the Belgian
* soccer tournament JupilerLeague
*/
class Numbers extends SplHeap
{
    /**
     * We modify the abstract method compare so we can sort our
     * values using the values of a given array
     */
    public function compare($array1, $array2)
    {
        $values1 = array_values($array1);
        $values2 = array_values($array2);
        if ($values1[0] === $values2[0]) return 0;
        return $values1[0] < $values2[0] ? -1 : 1;
    }
}

$heap = new Numbers();
$heap->insert(array ('Even' => 0));
$heap->insert(array ('Odd' => 1));
$heap->insert(array ('Even' => 2));
$heap->insert(array ('Odd' => 3));
$heap->insert(array ('Even' => 4));
$heap->insert(array ('Odd' => 5));
$heap->insert(array ('Even' => 6));
$heap->insert(array ('Odd' => 7));
$heap->insert(array ('Even' => 8));
$heap->insert(array ('Odd' => 9));

$heap->rewind();

// Then we iterate through each node for displaying the result
while ($heap->valid()) {
  list ($numberSystem, $value) = each ($heap->current());
  echo $numberSystem . ': ' . $value . "<br>";
  $heap->next();
}
?>
