const canvas = document.getElementById("canvas1");
const ctx = canvas.getContext("2d");
const btn = document.querySelector("button");
canvas.width = window.innerWidth;
canvas.height = window.innerHeight;
let hue = 0; //HSL(120 green ,240 blue and 0 red)
console.log(ctx);

window.addEventListener("resize", function () {
  //evertime the window is resized there is distortion thus we are assinging the height and width of the cavas everytime we resize the window , also drawing the reactangle eveytime .
  canvas.width = window.innerWidth;
  canvas.height = window.innerHeight;
});

const mouse = {
  X: null,
  Y: null,
};

function makecircle() {
  ctx.fillStyle = "silver";
  ctx.strokeStyle = "silver";
  ctx.beginPath();
  ctx.arc(mouse.X, mouse.Y, 5, 0, 6.28);
  ctx.fill();
}

canvas.addEventListener("click", (e) => {
  mouse.X = e.x;
  mouse.Y = e.y;
  for (let i = 0; i < 10; i++) particlesArray.push(new Particle()); //everytime i click i add a new particle
});

canvas.addEventListener("mousemove", (e) => {
  mouse.X = e.x;
  mouse.Y = e.y;
  for (let i = 0; i < 2; i++) particlesArray.push(new Particle());
});

canvas.addEventListener("touchmove", (e) => {
  mouse.X = e.x;
  mouse.Y = e.y;
  for (let i = 0; i < 2; i++) particlesArray.push(new Particle());
});

function randomColorGen() {
  return `rgba(${Math.random() * 255},${Math.random() * 255},${
    Math.random() * 255
  },${Math.random()})`;
}

function distance(x, y) {
  return Math.sqrt((x[0] - x[1]) ** 2 + (y[0] - y[1]) ** 2);
}

class Particle {
  constructor() {
    this.x = mouse.X;
    this.y = mouse.Y;
    // this.x = Math.random() * canvas.width;
    // this.y = Math.random() * canvas.height;
    this.size = Math.random() * 15 + 1;
    this.speedX = Math.random() * 5 - 2.5;
    this.speedY = Math.random() * 5 - 2.5;
    this.color = "hsl(" + (hue % 360) + ",100%,50%)";
    // this.color = randomColorGen();
  }

  //methods

  update() {
    if (this.x > canvas.width || this.x < 0) this.speedX *= -1;
    if (this.y > canvas.height || this.y < 0) this.speedY *= -1;
    this.x += this.speedX;
    this.y += this.speedY;
    if (this.size > 0.4) this.size -= 0.1;

    if (this.size < 0.4) {
      particlesArray.splice(particlesArray.indexOf(this), 1);
    }

    // this.color='hsl('+hue+',100%,50%)'
  }

  draw() {
    ctx.fillStyle = this.color;
    ctx.strokeStyle = this.color;
    ctx.beginPath();
    ctx.arc(this.x, this.y, this.size, 0, 6.28);
    ctx.fill();
  }

  drawline() {
    ctx.strokeStyle = this.color;
    for (let par of particlesArray) {
      if (distance([par.x, this.x], [par.y, this.y]) < 100) {
        ctx.beginPath();
        ctx.moveTo(par.x, par.y);
        ctx.lineTo(this.x, this.y);
        ctx.stroke();
      }
    }
  }
}

const particlesArray = [];

// function seeding() {
//   for (let i = 0; i < 10; i++) {
//     particlesArray.push(new Particle());
//   }
// }

// seeding();

function handleParticles() {
  for (let particle of particlesArray) {
    ctx.lineWidth = 0.2;

    particle.draw();
    particle.drawline();
    particle.update();
  }
}

function sleep(ms) {
  return new Promise((resolve) => setTimeout(resolve, ms));
}

async function animate() {
  // p.update();
  //   ctx.clearRect(0, 0, canvas.width, canvas.height);

  ctx.fillStyle = `rgba(0,0,0,0.1)`;
  ctx.fillRect(0, 0, canvas.width, canvas.height);
  handleParticles();
  hue++;

  requestAnimationFrame(animate);
}

animate();