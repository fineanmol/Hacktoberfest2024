var randomnum = Math.floor(Math.random() * 100)+1;
var guess = 0;
function guessNumber()
{
    var num = document.getElementById('input-value').value;
    
    if (num > 100 || num < 1 || num ==='')
    {
        document.getElementById('result').innerText = 'Invalid Input';
    }
    else
    {
        guess++;
        var num = parseInt(document.getElementById('input-value').value);
        if (num === randomnum)
        {
            document.getElementById('result').innerHTML = '<i><b>Guessed the answer correctly in '+ guess + ' guesses <b></i>';
        }
        else if (num > randomnum)
        {
            document.getElementById('result').innerText = 'Guess a smaller number';
        }
        else
        {
            document.getElementById('result').innerText = 'Guess a bigger number';
        }
    }    
}