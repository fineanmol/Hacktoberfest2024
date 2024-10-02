// Initialize AOS (Animate On Scroll)
AOS.init();

// Array containing contributors data
const Contributors = contributors;

// Variables
const searchbox = document.getElementById("search");
let searchResult = null;
let initialContributorsNumber = 72;

// Get the current year dynamically
const currentYear = new Date().getFullYear();

// Function to set the current year in the HTML
function setCurrentYear() {
  document.querySelectorAll("[data-year]").forEach(el => {
    el.textContent = currentYear;
  });
  // Set the document title with the current year
  document.title = `Hacktoberfest ${currentYear} - Contributors`;
}

// Call the function to set the current year
setCurrentYear();

/**
 * Filters contributors based on the search string.
 * @param {string} str - The search string.
 * @param {Array} array - The array of contributors.
 * @returns {Array} - The filtered list of contributors.
 */
function filterUsers(str = "ContributorName", array) {
  const inputString = typeof str === "string" ? str.toLowerCase() : "";
  if (str === "") return "Cannot be empty, please enter a name";
  return array.filter((item) => {
    const fullName = item.fullname || "";
    return fullName.toLowerCase().includes(inputString);
  });
}

/**
 * Renders the contributors on the page.
 * @param {Array} array - The array of contributors to render.
 */
function render(array) {
  array.forEach((item) => {
    let username = document.createElement("span");
    username.innerHTML = item.fullname;

    let user = document.createElement("a");
    user.className = "box-item";
    user.setAttribute("href", item.username);
    user.setAttribute("id", item.id);
    user.append(username);

    if (item.id <= initialContributorsNumber) {
      document.getElementById("contributors").append(user);
    }
  });

  // Add avatars after rendering the contributors
  document.querySelectorAll("a.box-item").forEach((con) => {
    con.innerHTML += `<img loading="lazy" src="https://github.com/${
      con.href.split("https://github.com/")[1]
    }.png">`;
  });
}

// Initial rendering of contributors
render(contributors);

/**
 * Loads more contributors when scrolled near the bottom of the page.
 */
function loadMore() {
  if (initialContributorsNumber >= contributors.length) {
    return; // No more contributors to load
  } else {
    initialContributorsNumber += 84; // Increase the number of contributors displayed
    render(contributors); // Render the newly loaded contributors
  }
}

// Infinite scrolling functionality
window.addEventListener("scroll", () => {
  if (window.innerHeight + window.scrollY >= document.body.offsetHeight - 500) {
    loadMore(); // Load more contributors when near the bottom of the page
  }
});

// Event listener for the search box
searchbox.addEventListener("keyup", async (e) => {
  searchbox.value !== ""
    ? document.getElementById("loadMore").classList.add("hidden")
    : document.getElementById("loadMore").classList.remove("hidden");

  searchResult = await filterUsers(e.target.value, contributors);
  document.getElementById("contributors").innerHTML =
    e.target.value !== ""
      ? "<div class='text-center' id='loading'>Loading...</div>"
      : "";

  e.target.value !== ""
    ? searchResult.forEach((item) => {
        let username = document.createElement("span");
        username.innerHTML = item.fullname;

        let user = document.createElement("a");
        user.className = "box-item";
        user.setAttribute("href", item.username);
        user.append(username);

        document.getElementById("contributors").append(user);
      })
    : render(contributors); // Re-render contributors if no search input

  document.querySelectorAll("a.box-item").forEach((con) => {
    con.innerHTML += `<img loading="lazy" src="https://github.com/${
      con.href.split("https://github.com/")[1]
    }.png">`;
  });

  document.getElementById("loading").setAttribute("hidden", true);
});

/* Back-to-top button functionality */
const backToTopButton = document.querySelector("#back-to-top-btn");

window.addEventListener("scroll", scrollFunction);
function scrollFunction() {
  if (window.pageYOffset > 300) {
    if (!backToTopButton.classList.contains("btnEntrance")) {
      backToTopButton.classList.remove("btnExit");
      backToTopButton.classList.add("btnEntrance");
      backToTopButton.style.display = "block";
    }
  } else {
    if (backToTopButton.classList.contains("btnEntrance")) {
      backToTopButton.classList.remove("btnEntrance");
      backToTopButton.classList.add("btnExit");
      setTimeout(function () {
        backToTopButton.style.display = "none";
      }, 250);
    }
  }
}

backToTopButton.addEventListener("click", smoothScrollBackToTop);

function smoothScrollBackToTop() {
  const targetPosition = 0;
  const startPosition = window.pageYOffset;
  const distance = targetPosition - startPosition;
  const duration = 750;
  let start = null;
  window.requestAnimationFrame(step);
  function step(timestamp) {
    if (!start) start = timestamp;
    const progress = timestamp - start;
    window.scrollTo(
      0,
      easeInOutCubic(progress, startPosition, distance, duration)
    );
    if (progress < duration) window.requestAnimationFrame(step);
  }
}

function easeInOutCubic(t, b, c, d) {
  t /= d / 2;
  if (t < 1) return (c / 2) * t * t * t + b;
  t -= 2;
  return (c / 2) * (t * t * t + 2) + b;
}

// Toggle dark/light theme
document.querySelector(".tdnn").addEventListener("click", () => {
  document.body.classList.toggle("light");
  document.querySelector(".moon").classList.toggle("sun");
  document.querySelector(".tdnn").classList.toggle("day");
});

// Display live stats with the dynamic year
document.getElementById(
  "stats"
).innerHTML = `You guys are awesome, we have again passed the GitHub rate limit this hour. <a href="https://github.com/fineanmol/Hacktoberfest${currentYear}" target="_blank">Here</a> is a link to check out our repo's live stats.`;
