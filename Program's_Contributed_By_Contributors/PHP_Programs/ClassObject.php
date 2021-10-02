<?php

// class
class Order
{

}

// create object
$check_class = new Order();

// pada php 7
var_dump(get_class($check_class));
var_dump(Order::class);

// pada php 8
var_dump($check_class::class);