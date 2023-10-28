// Global variables or default values
const scrollButton = document.getElementById('backToTop') || window;
const scrollTrigger = 150; // Default value
const scrollDuration = 1250; // Default value

scrollButton.onscroll = scrollFunc;

function scrollFunc() {
    if (scrollButton.scrollTop > scrollTrigger) {
        scrollButton.style.display = "block";
    } else {
        scrollButton.style.display = "none";
    }
}

scrollButton.onclick = function () {
    scrollButton.classList.add('startscrolling');
    scrollTo(scrollButton, 0, scrollDuration, function () {
        scrollButton.classList.remove('startscrolling');
    });
};

scrollButton.onmousedown = function () {
    scrollButton.classList.add("mousedown");
};

scrollButton.onmouseup = function () {
    scrollButton.classList.remove("mousedown");
};

function scrollTo(element, to, duration, callback) {
    const start = element.scrollTop,
        change = (to - start),
        currentTime = 0,
        increment = 20;

    const animateScroll = function () {
        currentTime += increment;
        const val = Math.easeInOutQuad(currentTime, start, change, duration);
        element.scrollTop = val;
        if (currentTime < duration) {
            setTimeout(animateScroll, increment);
        } else if (callback && typeof callback === 'function') {
            callback();
        }
    };

    animateScroll();
}

Math.easeInOutQuad = function (t, b, c, d) {
    t /= d / 2;
    if (t < 1) return (c / 2 * t * t) + b;
    t--;
    return -c / 2 * (t * (t - 2) - 1) + b;
};
