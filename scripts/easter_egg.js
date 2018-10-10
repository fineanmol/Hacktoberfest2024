document.addEventListener('keydown', function(event) {
  if(event.keyCode == 192) {
    console.log("Äru svensk?");
  }

  if(event.keyCode == 84) {
    if (document.body.classList.contains('terminal')) {
      document.body.classList.remove('terminal');
    }
    else {
      document.body.classList.add('terminal');
    }
  }
});


document.getElementById('invert-btn').onclick = (e) => {
  e.preventDefault();

  const mainContainer = document.getElementById("main-container");

  if (document.body.classList.contains('inverted')) {
    document.getElementById('footer').style.filter = 'invert(0)';
    document.getElementById('navbar').style.filter = 'invert(0)';

    if (!!mainContainer) {
      mainContainer.style.filter = "invert(0)";
    }

    document.body.classList.remove('inverted');
  }
  else {
    document.getElementById('footer').style.filter = 'invert(1)';
    document.getElementById('navbar').style.filter = 'invert(1)';

    if (!!mainContainer) {
      mainContainer.style.filter = "invert(1)";
    }

    document.body.classList.add('inverted');
    console.log('If you\'re using IE or Opera, you don\'t know what you are missing!');
  }
}

/*
 * Konami code
 *
 */
var allowedKeys = {
  37: 'left',
  38: 'up',
  39: 'right',
  40: 'down',
  65: 'a',
  66: 'b'
};

var konamiCode = ['up', 'up', 'down', 'down', 'left', 'right', 'left', 'right', 'b', 'a'];
var codePosition = 0;

document.addEventListener('keydown', function(e) {
  var key = allowedKeys[e.keyCode];
  var requiredKey = konamiCode[codePosition];

  if (key === requiredKey) {
    codePosition++;

    if (codePosition === konamiCode.length) {
      executeEasterEgg();
      codePosition = 0;
    }
  } else {
    codePosition = 0;
  }
});

function executeEasterEgg() {
  var html = document.createElement('div');
  var image = '<div style="position:absolute;top:50%;left:50%;transform:translate(-50%,-50%);background-color:#ccc;padding:10px;"><h1 style="text-align:center;">You´re such a nerd!!!</h1><img src="https://i.giphy.com/media/4hnQDVKVARZ6w/giphy.webp"></div>'

  html.innerHTML = image;
  document.body.appendChild(html);
}
