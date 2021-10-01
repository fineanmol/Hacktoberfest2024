function checkTriangle(x, y, z) {

    // Check for equilateral triangle
    if (x == y && y == z)
        console.log("Equilateral Triangle");

    // Check for isosceles triangle
    else if (x == y || y == z || z == x)
        console.log("Isosceles Triangle");

    // Otherwise scalene triangle
    else
        console.log("Scalene Triangle");
}

let x = 8,
    y = 7,
    z = 9;

// Function call
checkTriangle(x, y, z);