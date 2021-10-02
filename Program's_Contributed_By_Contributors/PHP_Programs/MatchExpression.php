<?php
$word = "Saya ingin berbelanja di shopee karena gratis ongkir";

$result = match(true){
    str_contains($word, "shopee") => "Kalimat anda mengandung kata sebuah aplikasi online store",
    str_contains($word, "gojek") => "Kalimat anda mengandung kata sebuah aplikasi ojek online",
    default => "Kalimat anda tidak mengandung kata apa pun"
};

echo $result;