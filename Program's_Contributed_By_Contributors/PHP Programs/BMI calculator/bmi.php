<?php
if ($_GET['submit']) {
    $mass = $_GET['mass'];
    $height = $_GET['height'];
    function bmi($mass, $height): float|int
    {
        return $mass / ($height * $height);
    }

    $bmi = bmi($mass, $height);
    $output = "";
    if ($bmi <= 18.5) {
        $output = "Under Weight";
    } else if ($bmi > 18.5 and $bmi <= 24.9) {
        $output = "Normal Weight";
    } else if ($bmi > 24.9 and $bmi <= 29.9) {
        $output = "Over Weight";
    } else if ($bmi > 30.0) {
        $output = "OBESE";
    }
    echo "Your BMI value is " . $bmi . " and you are : ";
    echo $output;
}
