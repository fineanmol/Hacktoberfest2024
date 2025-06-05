function countdown(){
    const second = 1000;
    const minute = second*60;
    const hour = minute*60;
    const day = hour*24;
    
    console.log(day);
    console.log(hour);
    console.log(minute);
    console.log(second);

    const newyear = new Date("apr 3, 2022 00:00:00").getTime();
    console.log(newyear);
    const today = new Date().getTime();
    console.log(today);

    const diff = newyear - today;

    const days = Math.floor(diff/day);
    const hours = Math.floor((diff%day)/hour);
    const minutes = Math.floor((diff%hour)/minute);
    const seconds = Math.floor((diff%minute)/second);

    document.getElementById("days").innerHTML = days;
    document.getElementById("hours").innerHTML = hours;
    document.getElementById("minutes").innerHTML = minutes;
    document.getElementById("seconds").innerHTML = seconds;
}

setInterval(countdown, 1000);
