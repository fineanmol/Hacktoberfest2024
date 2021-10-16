const img = document.querySelector("#img");

        const newJoke = () =>{
    fetch('https://meme-api.herokuapp.com/gimme')
    .then((res )=> res.json())
    .then((data)=> {
        img.src = data.preview[2]
    })
    .catch(err =>{
        console.log('err');
    })
}
img.addEventListener('click',newJoke)
newJoke();