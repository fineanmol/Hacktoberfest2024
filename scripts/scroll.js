window.onscroll = () => handleScroll();
const scrollButton = document.getElementById("backToTop");

function handleScroll() {
  const scrollTop =
    window.scrollY || document.body.scrollTop || document.documentElement.scrollTop;
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
  const start = document.documentElement.scrollTop || document.body.scrollTop,
    change = to - start,
    startTime = performance.now();

  function animateScroll(currentTime) {
    const elapsed = currentTime - startTime;
    const val = Math.easeInOutQuad(elapsed, start, change, duration);

    document.documentElement.scrollTop = val;
    document.body.scrollTop = val;

    if (elapsed < duration) {
      requestAnimationFrame(animateScroll);
    } else if (callback && typeof callback === "function") {
      callback();
    }
  }
  requestAnimationFrame(animateScroll);
}

Math.easeInOutQuad = (t, b, c, d) => {
  t /= d / 2;
  if (t < 1) return (c / 2) * t * t + b;
  t--;
  return (-c / 2) * (t * (t - 2) - 1) + b;
};
