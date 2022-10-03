 function time() {
    const today = new Date();
    let hour = today.getHours();
    let min = today.getMinutes();
    let sec = today.getSeconds();
     min = checkTime(min);
    sec = checkTime(sec);
    document.getElementById('txt').innerHTML = hour + ":" + min + ":" + sec;
    setTimeout(time, 1000);
}

    function checkTime(x){
    if (x < 10){
        x = "0" + x;
    }
    return x;
}
