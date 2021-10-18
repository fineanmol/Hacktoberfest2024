let p = new Promise((resolve, reject) => {
  let a = 1 + 7;
  if (a === 2) {
    resolve("Hello world");
  } else {
    reject("Failed");
  }
});

p.then((message) => {
  console.log(message);
}).catch((err) => {
  console.log(err);
});
