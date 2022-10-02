function display_random_meme() 
{
     var theImages = [{
        src: "./text_m/text_m1.png"
    },{
        src: "./text_m/text_m2.png"
    },{
        src: "./text_m/text_m3.png"
    },{
        src: "./text_m/text_m4.png"
    },{
        src: "./text_m/text_m5.png"
    },{
        src: "./text_m/text_m6.png"
    }, ];
    
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