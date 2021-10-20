document.getElementById("getText").addEventListener("click", getText);
document.getElementById("getUsers").addEventListener("click", getUsers);
document.getElementById("addPost").addEventListener("submit", addPost);

function getText() {
  fetch("sample.txt")
    .then((res) => {
      return res.text();
    })
    .then((data) => {
      document.getElementById("output").innerHTML = data;
    })
    .catch((err) => {
      console.log(err);
    });
}

function getUsers() {
  fetch("users.json")
    .then((res) => {
      return res.json();
    })
    .then((data) => {
      let output = `<h2>Users</h2>`;
      data.map((user) => {
        output += `<ul>
        <li>
        ${user.name}
        ${user.email}
        </li>
        </ul>`;
      });
      document.getElementById("output").innerHTML = output;
    })
    .catch((err) => {
      console.log(err);
    });
}

//Fetching Post from json placeholder

document.getElementById("getPost").addEventListener("click", getPost);

function getPost() {
  fetch("https://jsonplaceholder.typicode.com/posts")
    .then((res) => {
      return res.json();
    })
    .then((data) => {
      let postOutput = `<h2>Posts</h2>`;
      data.map((userData) => {
        postOutput += `
        <div>
        <h4>${userData.title}</h4>
        <p>${userData.body}</p>
        </div>
        `;
      });
      document.getElementById("getPost").innerHTML = postOutput;
    })
    .catch((err) => {
      console.log(err);
    });
}

//sending data to api using post method

function addPost(e) {
  e.preventDefault();

  let title = document.getElementById("title").value;
  let body = document.getElementById("body").value;

  fetch("https://jsonplaceholder.typicode.com/posts", {
    method: "POST",
    headers: {
      Accept: "application/json , text/plain , */*",
      "Content-type": "application/json",
    },
    body: JSON.stringify({ title: title, body: body }),
  })
    .then((res) => {
      return res.json();
    })
    .then((data) => {
      console.log(data);
    })
    .catch((err) => {
      console.log(err);
    });
}
