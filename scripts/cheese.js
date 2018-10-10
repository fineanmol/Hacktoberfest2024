let twistHandler = document.getElementById('twist').addEventListener('click', () => {
    let cards = document.querySelectorAll('.spin');
    
    cards.forEach(card => card.classList.toggle('spinCard'));
}, false);

// function to change the background of the <section> part of cheese.html when the user clicks 'click for cheese' btn
function cheeseAppearance(){
    const jumbotron = document.getElementById('cheesetron');
    const randomNum = Math.floor((Math.random() * 3) + 1);

    switch (randomNum) {
      case 1: {
        jumbotron.className = 'cheesetron-1';
        break;
      }
      case 2: {
        jumbotron.className = 'cheesetron-2';
        break;
      }
      default: {
        jumbotron.className = 'cheesetron-3';
      }
    }
  }
