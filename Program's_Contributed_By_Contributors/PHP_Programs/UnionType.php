<?php

// Union Type Pada Property
class word{
    public float|string $data;
}

$get_word = new word();
echo $get_word->data = "tipe string ini adalah kalimat";

// Union Type Pada Value
function funcTest(float|string|int $data): float|string|int {
    if(is_int($data)) {
        return 10;
    } else if(is_float($data)) {
        return 1.5;
    } else if(is_string($data)) {
        return 'ini adalah return string';
    }
}

var_dump(funcTest("masukan string"));
var_dump(funcTest(80));
var_dump(funcTest(5.0));