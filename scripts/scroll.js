window.onscroll = () => {
  const scrollTop = document.documentElement.scrollTop || document.body.scrollTop;
  scrollButton.style.display = scrollTop > 150 ? "block" : "none";
};

const scrollButton = document.getElementById("backToTop");

scrollButton.addEventListener("click", () => {
  scrollButton.classList.add("startscrolling");
  smoothScrollTo(0, 1250, () => scrollButton.classList.remove("startscrolling"));
});

scrollButton.addEventListener("mousedown", () => scrollButton.classList.add("mousedown"));
scrollButton.addEventListener("mouseup", () => scrollButton.classList.remove("mousedown"));

function smoothScrollTo(to, duration, callback) {
  const start = document.documentElement.scrollTop, change = to - start, increment = 20;
  let currentTime = 0;

  (function animateScroll() {
    currentTime += increment;
    const val = Math.easeInOutQuad(currentTime, start, change, duration);
    document.documentElement.scrollTop = val;
    if (currentTime < duration) setTimeout(animateScroll, increment);
    else callback?.();
  })();
}

Math.easeInOutQuad = (t, b, c, d) => {
  t /= d / 2;
  return t < 1 ? (c / 2) * t * t + b : (-c / 2) * (--t * (t - 2) - 1) + b;
};
