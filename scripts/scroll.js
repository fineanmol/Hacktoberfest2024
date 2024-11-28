
const scrollButton = document.getElementById("backToTop");
const docEl = document.documentElement;

function debounce(func, wait) {
  let timeout;
  return function (...args) {
    const context = this;
    clearTimeout(timeout);
    timeout = setTimeout(() => func.apply(context, args), wait);
  };
}

function handleScroll() {
  const scrollTop = docEl.scrollTop || document.body.scrollTop;
  scrollButton.style.display = scrollTop > 150 ? "block" : "none";
}

function smoothScrollTo(to, duration, callback) {
  const start = docEl.scrollTop,
    change = to - start,
    startTime = performance.now();

  function animateScroll(currentTime) {
    const elapsedTime = currentTime - startTime;
    const progress = elapsedTime / duration;
    const val = Math.easeInOutQuad(progress, start, change, 1);

    docEl.scrollTop = val;

    if (progress < 1) {
      requestAnimationFrame(animateScroll);
    } else if (callback && typeof callback === "function") {
      callback();
    }
  }

  requestAnimationFrame(animateScroll);
}

window.onscroll = debounce(handleScroll, 100);

scrollButton.addEventListener("click", () => {
  scrollButton.classList.add("startscrolling");
  smoothScrollTo(0, 1250, () => {
    scrollButton.classList.remove("startscrolling");
  });
});

scrollButton.addEventListener("pointerdown", () => {
  scrollButton.classList.add("mousedown");
});
scrollButton.addEventListener("pointerup", () => {
  scrollButton.classList.remove("mousedown");
});

Math.easeInOutQuad = (t, b, c, d) => {
  if (t < 0.5) return c * (2 * t * t) + b;
  return -c * ((t - 1) * (2 * t - 2) - 1) + b;
};


//changes made
//  Debouncing the onscroll event
// The onscroll event can fire rapidly, which could cause performance issues. Debouncing the scroll handler ensures the function runs less frequently.

// 2. Cache the scrollButton and documentElement
// Instead of repeatedly accessing document.documentElement.scrollTop, cache the reference to avoid unnecessary DOM lookups.

// 3. Use requestAnimationFrame for smoother animations
// Instead of using setTimeout, requestAnimationFrame is better suited for smooth animations and optimized for performance.

// 4. Reduce redundant event listeners
// You could combine the mousedown and mouseup event listeners into one, using the pointerdown and pointerup events for better flexibility across devices.

