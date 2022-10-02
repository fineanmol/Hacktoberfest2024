document.querySelector('.toggle-mode').addEventListener('click',()=>{
    document.body.classList.toggle('dark')
    document.querySelector('.random-value').classList.toggle('dark')
    document.querySelector('.moon').classList.toggle('none')
    document.querySelector('.sun').classList.toggle('none')
})
