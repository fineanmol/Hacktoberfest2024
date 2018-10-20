let t = document.getElementById('twist').addEventListener('click', () => {
    let cards = document.getElementsByClassName('card')    
    cards.forEach(card => {
        card.classList.toggle('spinCard')
    })
}, false)

let l = document.getElementById('love').addEventListener('click', () => {
  let body = document.body
  document.querySelector("#header h1").innerHTML = "Broccoli Egg"
  body.classList.toggle("broccoli-green")
}, false)
