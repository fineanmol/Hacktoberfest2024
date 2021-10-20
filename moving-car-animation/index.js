document.addEventListener("DOMContentLoaded", function() {
    let flag = true;
   
    const cars=['https://github.com/Raven1233/Moving-car-animation/blob/master/Img_05.png?raw=true', 'https://github.com/Raven1233/Moving-car-animation/blob/master/Img_06.png?raw=true'];

    document.addEventListener('keypress', (f) => {
        if(f.which == 13){
            document.getElementById("surface").classList.toggle("movement");
            document.getElementById("car").classList.toggle("carmove");
        }
    });
    document.addEventListener('keypress', (f) => {
        if(f.which == 119){
            if(flag){
                flag=false;
                document.getElementById("car_image").src = cars[0];
            }
            else{
                flag=true;
                document.getElementById("car_image").src = cars[1];
            }
        }
    });
    document.addEventListener('keydown', function(e) {
        if (e.keyCode == 49) {
          document.getElementById('audio').play();
        }
        if (e.keyCode == 50) {
            document.getElementById('audio').pause();
        }
    })



});
