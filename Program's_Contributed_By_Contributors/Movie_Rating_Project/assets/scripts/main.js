const backdrop = document.querySelector("#backdrop");
const addMovieBtn = document.querySelector("#addMovieBtn");
const modal = document.querySelector(".modal");
const modalCancelBtn = document.querySelector(".btn--passive");

addMovieBtn.addEventListener("click", function () {
  backdrop.className = "visible";
  modal.classList.add(
    "visible",
    "modal__title",
    "modal_content",
    "modal_actions"
  );

  backdrop.addEventListener("click", function () {
    backdrop.className = "";
    modal.classList.remove(
      "visible",
      "modal__title",
      "modal_content",
      "modal_actions"
    );
  });
  modalCancelBtn.addEventListener("click", function () {
    backdrop.className = "";
    modal.classList.remove(
      "visible",
      "modal__title",
      "modal_content",
      "modal_actions"
    );
  });
});

const movieAddBtn = document.querySelector(".btn--success");
const movieTitleInput = document.querySelector("#title");
const movieImageInput = document.querySelector("#image-url");
const movieRatingInput = document.querySelector("#rating");

const cardMovieListUl = document.querySelector("#movie-list");

movieAddBtn.addEventListener("click", function () {
  //   alert("wrking");
  const li = document.createElement("li");
  const h2 = document.createElement("h2");
  const img = document.createElement("img");
  const p = document.createElement("p");
  const span1 = document.createElement("span");
  const span2 = document.createElement("span");

  li.className = "movie-element__image";
  h2.className = "movie-element__info";
  img.setAttribute("src", movieImageInput.value);
  img.setAttribute("alt", "");

  h2.textContent = movieTitleInput.value;
  p.textContent = "rating ";
  span1.textContent = movieRatingInput.value;
  span2.textContent = "/5";

  span1.appendChild(span2);
  p.appendChild(span1);
  li.appendChild(h2);
  li.appendChild(img);
  li.appendChild(p);
  cardMovieListUl.appendChild(li);

  // Swal.fire("Good job!", "You clicked the button!", "success");
  Swal.fire({
    title: '"Good job!", "You clicked the button!", "success"',
    width: 600,
    padding: "3em",
    color: "#716add",
    background: "#fff url(/images/trees.png)",
    backdrop: `
      rgba(0,0,123,0.4)
      url("https://media.tenor.com/xzjlrhYq_lQAAAAj/cat-nyan-cat.gif")
      left top
      no-repeat
    `,
  });

  backdrop.className = "";
  modal.classList.remove(
    "visible",
    "modal__title",
    "modal_content",
    "modal_actions"
  );

  //Remover

  li.addEventListener("click", function () {
    cardMovieListUl.removeChild(li);
  });
});
