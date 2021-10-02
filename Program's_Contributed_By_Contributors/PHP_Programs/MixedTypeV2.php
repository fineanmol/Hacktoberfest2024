<?php

function funcMixed(mixed $param): mixed
{
    if (is_string($param)) {
        return "String";
    }else if(is_int($param)){
        return 1;
    }else if(is_array($param)){
        return [];
    }
}

var_dump(funcMixed('Ini adalah sebuah kalimat'));
var_dump(funcMixed(120));
var_dump(funcMixed(['array 1', 'array 2']));