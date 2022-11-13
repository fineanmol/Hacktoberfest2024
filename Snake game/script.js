/*
COLOR PALLETTE
light-purple : #D499B9
dark-purple :  #9055A2
dark-blue : #2E294E
darkest : #011638
*/

let canvas = document.querySelector('canvas');
let ctx = canvas.getContext('2d');
let tileSize = 20;
let rows, cols;
let gameStatus = false;
let score = 0;
let highScore = localStorage.getItem('highScore');
if (!highScore) {
  localStorage.setItem('highScore', score);
  highScore = localStorage.getItem('highScore');
}
document.querySelector('.high-score').innerHTML = `${highScore}`;
function checkHighScore(score) {
  if (!highScore) {
    localStorage.setItem('highScore', score);
    highScore = localStorage.getItem('highScore');
  } else if (highScore < score) {
    localStorage.setItem('highScore', score);
    highScore = localStorage.getItem('highScore');
  }
}
checkHighScore(score);

//UPDATE DOM

const updateDOM = () => {
  score++;
  checkHighScore(score);
  document.querySelector('.high-score').innerHTML = `${highScore}`;
  document.querySelector('.score').innerHTML = `Score : ${score}`;
};
//GETTING ROWS AND COLS
const getRowsAndCols = (width) => {
  rows = Math.floor(width / tileSize);
  cols = rows;
};
//INITIALIZE THE CANVAS
const init = () => {
  canvas.height = 600;
  canvas.width = 600;
  getRowsAndCols(600);
  if (window.innerWidth < 600) {
    getRowsAndCols(window.innerWidth - 50);
    canvas.height = rows * tileSize;
    canvas.width = cols * tileSize;
  }
  ctx.fillStyle = '#011638';
  ctx.fillRect(0, 0, canvas.width, canvas.height);
};
init();
document.addEventListener('resize', init);

//FOOD CLASS
class Food {
  constructor() {
    this.x;
    this.y;
  }

  generateFood() {
    this.x = Math.floor(Math.random() * cols) * tileSize;
    this.y = Math.floor(Math.random() * rows) * tileSize;
  }
  draw() {
    ctx.beginPath();
    ctx.fillStyle = 'red';
    ctx.rect(this.x, this.y, tileSize, tileSize);
    ctx.fill();
  }
}
//CLASS SNAKE
class Snake {
  constructor(dx, dy) {
    this.x = 80;
    this.y = 60;
    this.dx = dx;
    this.dy = dy;
    this.tail = [];
    this.total = 4;
  }

  draw() {
    if (this.tail.length === 0) {
      for (let i = 0; i < this.total - 1; i++) {
        this.tail[i] = { x: 20 * (i + 1), y: 60 };
      }
    }
    this.tail[this.total - 1] = { x: this.x, y: this.y };

    ctx.beginPath();
    ctx.fillStyle = '#D499B9';
    for (let i = 0; i < this.total - 1; i++) {
      ctx.rect(this.tail[i].x, this.tail[i].y, tileSize, tileSize);
      ctx.fill();
    }
    ctx.beginPath();
    ctx.fillStyle = '#83506c';
    ctx.rect(
      this.tail[this.total - 1].x,
      this.tail[this.total - 1].y,
      tileSize,
      tileSize
    );
    ctx.fill();
  }

  update() {
    this.x += this.dx * tileSize;
    this.y += this.dy * tileSize;
    if (this.tail.length === this.total) {
      for (let i = 0; i < this.total - 1; i++) {
        this.tail[i] = this.tail[i + 1];
      }
    }
    this.tail[this.total - 1] = {
      x: this.x,
      y: this.y,
    };
    if (this.x + tileSize > canvas.width || this.x < 0) {
      stopGame();
    }
    if (this.y + tileSize > canvas.height || this.y < 0) {
      stopGame();
    }
    if (this.eatenFood()) {
      this.total++;
      f.generateFood();
    }
    if (this.eatenTail()) {
      console.log('lost');
    }
    this.draw();
  }

  eatenTail() {
    for (let i = 0; i < this.tail.length - 1; i++) {
      if (
        this.x + tileSize > this.tail[i].x &&
        this.y + tileSize > this.tail[i].y &&
        this.tail[i].x + tileSize > this.x &&
        this.tail[i].y + tileSize > this.y
      ) {
        stopGame();
        return true;
      }
    }
  }

  eatenFood() {
    if (
      this.x + tileSize > f.x &&
      this.y + tileSize > f.y &&
      f.x + tileSize > this.x &&
      f.y + tileSize > this.y
    ) {
      updateDOM();
      return true;
    } else {
      return false;
    }
  }

  dir(x, y) {
    this.dx = x;
    this.dy = y;
  }
}

let s = new Snake(1, 0);
let f = new Food();
if (gameStatus) {
  s.draw();
  f.generateFood();
}

const changeDirection = (e) => {
  if (e.keyCode === 37 && s.dx === 0) {
    s.dir(-1, 0);
  } else if (e.keyCode === 38 && s.dy === 0) {
    s.dir(0, -1);
  } else if (e.keyCode === 39 && s.dx === 0) {
    s.dir(1, 0);
  } else if (e.keyCode === 40 && s.dy === 0) {
    s.dir(0, 1);
  }
  document.removeEventListener('keydown', changeDirection);
  setTimeout(() => {
    document.addEventListener('keydown', changeDirection);
  }, 30);
};
document.addEventListener('keydown', changeDirection);

let fps, fpsInterval, now, then, elapsed;

const animate = () => {
  if (gameStatus) {
    requestAnimationFrame(animate);
  }
  now = Date.now();
  elapsed = now - then;
  //IF ENOUGH TIME HAS PASSED DRAW THE NEXT FRAME
  if (elapsed > fpsInterval) {
    then = now - (elapsed % fpsInterval);
    ctx.clearRect(0, 0, canvas.height, canvas.width);
    init();
    s.update();
    f.draw();
  }
};

const startAnimating = (fps) => {
  fpsInterval = 1000 / fps;
  then = Date.now();
  if (gameStatus) {
    animate();
  }
};

startAnimating(10);

const startGame = () => {
  score = 0;
  document.querySelector('.score').innerHTML = `Score : ${score}`;
  setTimeout(() => {
    document.querySelector('.counter h3').innerHTML = '3';
    setTimeout(() => {
      document.querySelector('.counter h3').innerHTML = '2';
    }, 1000);
    setTimeout(() => {
      document.querySelector('.counter h3').innerHTML = '1';
    }, 2000);
    setTimeout(() => {
      document.querySelector('.counter h3').classList.add('none');
      document.querySelector('.counter h3').innerHTML = '';
      s = new Snake(1, 0);

      gameStatus = true;
      s.draw();
      f.generateFood();
      startAnimating(10);
    }, 3000);
  }, 400);
};

document.querySelector('.start-game .btn').addEventListener('click', () => {
  document.querySelector('.start-game').classList.add('hide');
  window.addEventListener(
    'keydown',
    function (e) {
      if (
        ['Space', 'ArrowUp', 'ArrowDown', 'ArrowLeft', 'ArrowRight'].indexOf(
          e.code
        ) > -1
      ) {
        e.preventDefault();
      }
    },
    false
  );
  startGame();
});

function stopGame() {
  gameStatus = false;
  setTimeout(() => {
    clearTimeout(0, 0, canvas.width, canvas.height);
    init();
    document.querySelector('.game-over-box').classList.remove('hide');
    document
      .querySelector('.game-over-box .btn')
      .addEventListener('click', () => {
        document.querySelector('.game-over-box').classList.add('hide');
        document.querySelector('.counter h3').classList.remove('none');

        startGame();
      });
  }, 500);
}
