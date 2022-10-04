<?php

$q = new SplStack();

$q[] = 1;
$q[] = 2;
$q[] = 3;
$q->push(4);
$q->add(4, 5);

$q->rewind();
while ($q->valid()) {
  echo "Value at index:".$q->key()." is ".$q->current(), "<br>";
  $q->next();
}
