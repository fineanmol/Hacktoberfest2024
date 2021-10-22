function delAge() {
    document.getElementById('ageInDays').remove();
}

function ageInDays() {
    var birthYear = prompt("Birth Year");
    var birthMonth = prompt("Birth Month");
    var birthDay = prompt("Birth Date");

    let totalDays = 0;
    const birthDate = new Date(birthYear, birthMonth, birthDay);
    const curDate = new Date();
    if (birthDate.getDate() < curDate.getDate()) {
        totalDays = 30 + birthDate.getDate() - curDate.getDate(); //Just approximate values
    }
    else {
        totalDays = birthDate.getDate() - curDate.getDate();
    }
    let totalYears = curDate.getFullYear() - birthDate.getFullYear();
    let totalMonths = 0;
    if (birthDate.getMonth() < curDate.getMonth()) {
        totalMonths = curDate.getMonth() - birthDate.getMonth();
    }
    else {
        totalMonths = 12 + curDate.getMonth() - birthDate.getMonth();
        totalYears -= 1;
    }
    totalDays += (totalYears * 365) + (totalMonths * 30) + totalDays;

    console.log(totalYears);
    console.log(totalMonths);
    console.log(totalDays);
    
    var h1 = document.createElement('h1');
    var textAnswer = document.createTextNode('You are ' + totalDays + ' days old');
    h1.setAttribute('id', 'ageInDays');
    h1.appendChild(textAnswer);
    document.getElementById('flex-box-result').appendChild(h1);
}
