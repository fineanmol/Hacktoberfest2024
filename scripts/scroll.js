window.onscroll = () => handleScroll();
const scrollButton = document.getElementById("backToTop");

function handleScroll() {
  const scrollTop =
    document.body.scrollTop || document.documentElement.scrollTop;
  scrollButton.style.display = scrollTop > 150 ? "block" : "none";
}

scrollButton.addEventListener("click", () => {
  scrollButton.classList.add("startscrolling");
  smoothScrollTo(0, 1250, () => {
    scrollButton.classList.remove("startscrolling");
  });
});

scrollButton.addEventListener("mousedown", () => {
  scrollButton.classList.add("mousedown");
});

scrollButton.addEventListener("mouseup", () => {
  scrollButton.classList.remove("mousedown");
});

function smoothScrollTo(to, duration, callback) {
  const start = document.documentElement.scrollTop,
    change = to - start,
    increment = 20;
  let currentTime = 0;

  function animateScroll() {
    currentTime += increment;
    const val = Math.easeInOutQuad(currentTime, start, change, duration);
    document.documentElement.scrollTop = val;

    if (currentTime < duration) {
      setTimeout(animateScroll, increment);
    } else if (callback && typeof callback === "function") {
      callback();
    }
  }
  animateScroll();
}

Math.easeInOutQuad = (t, b, c, d) => {
  t /= d / 2;
  if (t < 1) return (c / 2) * t * t + b;
  t--;
  return (-c / 2) * (t * (t - 2) - 1) + b;
};
const button = document.querySelector('.annoying-button');

button.addEventListener('click', () => {
    const randomColor = `#${Math.floor(Math.random()*16777215).toString(16)}`;
    button.style.backgroundColor = randomColor;
});
const messages = [
  "I'm watching you!",
  "Catch me if you can!",
  "Oh no, not again!",
  "Click me if you dare!"
];

button.addEventListener('mouseover', () => {
  const randomMessage = messages[Math.floor(Math.random() * messages.length)];
  button.innerText = randomMessage;
});
