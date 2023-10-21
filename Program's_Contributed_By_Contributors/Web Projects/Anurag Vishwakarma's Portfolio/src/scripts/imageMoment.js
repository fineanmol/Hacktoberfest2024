const avatar = document.getElementById('avatar');

avatar.addEventListener('mousemove', function(hovPos){

    avatar.style.right = hovPos.x * 0.02 + "px";
    avatar.style.bottom = hovPos.y * 0.05 + "px";
    
    avatar.style.transform = `rotate(${hovPos.x * -.01}deg)`;
});