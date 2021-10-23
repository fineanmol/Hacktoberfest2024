const leftHandle = document.querySelector("#left");
const rightHandle = document.querySelector("#right");
const topHandle = document.querySelector("#top");
const bottomHandle = document.querySelector("#bottom");
const shape = document.querySelector(".shape");

// For css result

const topLeft = document.querySelector("#topLeft");
const topRight = document.querySelector("#topRight");
const bottomLeft = document.querySelector("#bottomLeft");
const bottomRight = document.querySelector("#bottomRight");

leftHandle.addEventListener("input", (e)=>{
    shape.style.borderTopLeftRadius = leftHandle.value+'%';
    topLeft.textContent = leftHandle.value + "%";
})

topHandle.addEventListener("input", (e)=>{
    shape.style.borderTopRightRadius = topHandle.value+'%';
    topRight.textContent =  topHandle.value+'%';
})

rightHandle.addEventListener("input", (e)=>{
    shape.style.borderBottomRightRadius = rightHandle.value+'%';
    bottomRight.textContent = rightHandle.value+'%';
})

bottomHandle.addEventListener("input", (e)=>{
    shape.style.borderBottomLeftRadius = bottomHandle.value+'%';
    bottomLeft.textContent = bottomHandle.value+'%';
})

