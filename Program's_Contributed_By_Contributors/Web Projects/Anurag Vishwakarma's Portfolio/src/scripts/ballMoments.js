const balls = document.getElementsByClassName("bluredCircles");
const desinedByAnurag = document.getElementById("desinedByAnurag");
const mySkillBoxes = document.getElementsByClassName("mySkillBoxes");


for (let x = 0; x < balls.length; x++) {

    balls[x].addEventListener('mousemove', function (ballHov) {

        balls[x].style.transform = `rotate(${ballHov.y * .8}deg)`;
        balls[x].style.boxShadow = `${ballHov.x * .1}rem ${ballHov.y * .1}rem 5rem pink`;


    });
}

desinedByAnurag.addEventListener('mousemove', function (createrPos) {
    desinedByAnurag.style.paddingTop = `${createrPos.y * .05}rem`;
    desinedByAnurag.style.paddingLeft = `${createrPos.x * .005}rem`;

})

for (let j = 0; j < mySkillBoxes.length; j++) {
    mySkillBoxes[j].addEventListener('mousemove', function (skillPos) {
        mySkillBoxes[j].style.marginLeft = `${skillPos.x * 0.006}` + "rem"
        mySkillBoxes[j].style.marginTop = `${skillPos.y * 0.004}` + "rem"

    })
}
