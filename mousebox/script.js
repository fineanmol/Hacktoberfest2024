const map = [];
const button = document.querySelector("button");
const screen = document.getElementById("playground");
const box = document.getElementById("box");
const velocity = 20.0;

var target_x = 50;
var target_y = 50;

const screenRec = screen.getBoundingClientRect();
var screen_x = screenRec.x;
var screen_y = screenRec.y;

var screen_width = screen.offsetWidth;
var screen_height = screen.offsetHeight;

var current_x = screenRec.x;
var current_y = screenRec.y;

var itemCount = 0;
var itemSpawned = [];
var maxItemSpawn = 3;

function render() {
  setInterval(() => {
    update();

    if (Math.abs(current_x - target_x) < 5) {
      current_x = target_x;
    }

    if (Math.abs(current_y - target_y) < 5) {
      current_y = target_y;
    }

    if (current_x > target_x) {
      current_x -= velocity;
    }

    if (current_x < target_x) {
      current_x += velocity;
    }

    if (current_y > target_y) {
      current_y -= velocity;
    }

    if (current_y < target_y) {
      current_y += velocity;
    }

    box.style.left = current_x + "px";
    box.style.top = current_y + "px";
  }, 15);
}

function update() {
  if (itemSpawned.length < maxItemSpawn) {
    var itemX = getRandomArbitrary(screen_x, screen_width);
    var itemY = getRandomArbitrary(screen_y, screen_height);

    itemSpawned.push({
      id: itemCount++,
      x: itemX,
      y: itemY,
    });

    console.log(itemSpawned)
  }
}

update();
render();

screen.addEventListener("click", function (e) {
  const screenRec = screen.getBoundingClientRect();
  target_x = e.x - screenRec.x;
  target_y = e.y - screenRec.y;
});

function getRandomArbitrary(min, max) {
  return Math.random() * (max - min) + min;
}
