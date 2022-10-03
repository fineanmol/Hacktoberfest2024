function display_random_meme() 
{
     var theImages = [{
        src: "./t_meme/t_meme1.png"
    }, {
        src: "./t_meme/t_meme2.png"
    }, {
        src: "./t_meme/t_meme3.png"
    }, {
        src: "./t_meme/t_meme4.png"
    }, {
        src: "./t_meme/t_meme5.png"
    }, {
        src: "./t_meme/t_meme6.png"
    }, {
        src: "./t_meme/t_meme7.png"
    }, {
        src: "./t_meme/t_meme8.png"
    }, {
        src: "./t_meme/t_meme9.png"
    }, {
        src: "./t_meme/t_meme10.png"
    }];
    
    var preBuffer = [];
    for (var i = 0, j = theImages.length; i < j; i++) {
        preBuffer[i] = new Image();
        preBuffer[i].src = theImages[i].src;
    }

    function getRandomInt(min,max) 
    {
      
    imn = Math.floor(Math.random() * (max - min + 1)) + min;
    return preBuffer[imn];
    }  

    var newImage = getRandomInt(0, preBuffer.length - 1);
 
    var images = document.getElementsByTagName('img');
    var l = images.length;
    for (var p = 0; p < l; p++) {
        images[0].parentNode.removeChild(images[0]);
    }  
    document.body.appendChild(newImage);
}