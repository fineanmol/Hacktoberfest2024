fetch("https://api.quotable.io/random")
  .then((response) => response.json())
  .then((response) => {
    const quoteText = response.content;
    const authorName = response.author;
    // console.log(quoteText);
    const quoteDisplay = document.getElementById("quoteDisplay");
    const author = document.getElementById("author");

    quoteDisplay.innerHTML = quoteText;
    author.innerHTML = authorName;
  });
