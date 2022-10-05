//odd even function
function odd_even(n)
{
    if (n % 2 == 0)
        return "even";
    else
        return "odd";
}

//main function
function main()
{
    var n = 2;
    console.log(odd_even(n));
}

main();

// Output:
// even