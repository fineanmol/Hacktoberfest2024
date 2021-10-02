<?php
//create and assign values to Array
$phoneBrands = array("Xiaomi", "Samsung", "HP", "LG", "Realme");

//count array length
$arrlength = count($phoneBrands);

//print Phone Brands: to view
echo "Phone Brands: <br>";

//looping Through the array
for($x = 0; $x < $arrlength; $x++) {
    echo $phoneBrands[$x];
    echo "<br>";
}
?>