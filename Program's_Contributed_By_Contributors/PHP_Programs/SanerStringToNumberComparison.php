<?php 

$compare_1 = 0 == "0";                        //   PHP 7 or earlier (TRUE) | PHP 8 (TRUE)
$compare_2 = 0 == "0.0";                      //   PHP 7 or earlier (TRUE) | PHP 8 (TRUE)
$compare_3 = 0 == "kata";                  //   PHP 7 or earlier (TRUE) | PHP 8 (FALSE)
$compare_4 = 0 == "";                         //   PHP 7 or earlier (TRUE) | PHP 8 (FALSE)
$compare_5 = 12 == "     60     ";            //   PHP 7 or earlier (TRUE) | PHP 8 (TRUE)
$compare_6 = 12 == "ini adalah string60";     //   PHP 7 or earlier (TRUE) | PHP 8 (FALSE)

var_dump($compare_1);
var_dump($compare_2);
var_dump($compare_3);
var_dump($compare_4);
var_dump($compare_5);
var_dump($compare_6);