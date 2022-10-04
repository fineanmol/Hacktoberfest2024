const { ICECREAM_STOCK } = require("./stock");

// Checks if the Asked Flavour is Available, Resolves(in 2 sec.) only when Available
const checkStock = (flavour) => {
  const flavourKey = flavour.toLowerCase();

  return new Promise((resolve, reject) => {
    setTimeout(() => {
      if (flavourKey in ICECREAM_STOCK && ICECREAM_STOCK[flavourKey] > 0) {
        // Stock is Updated as the IceCream is Selected..
        ICECREAM_STOCK[flavourKey] -= 1;
        resolve(`${flavour} Icecream is PRESENT in Stock !!`);
      } else if (
        flavourKey in ICECREAM_STOCK &&
        ICECREAM_STOCK[flavourKey] == 0
      ) {
        reject(`${flavour} Flavour is Sold Out !!`);
      } else {
        reject(`${flavour} - No Such Flavour in Stock`);
      }
    }, 2000);
  });
};

// Prepares the IceCream after Checking the STock
const prepare_IceCream = (flavour) => {
  return new Promise((resolve, reject) => {
    checkStock(flavour)
      .then((msg) => {
        console.log(msg);

        // Updated Stock is printed
        console.log("Stock is now: ", ICECREAM_STOCK);
        resolve("Preparing...");
      })
      .catch((error) => {
        console.log("Can't Prepare..");
        reject(error);
      });
  });
};

const buyIceCream = (response, iceCream_choice) => {
  return new Promise((resolve, reject) => {
    console.log(response);

    prepare_IceCream(iceCream_choice)
      .then((msg) => {
        console.log(msg);
        setTimeout(
          () =>
            resolve(
              `Here's Your Choice of Ice-Cream : ${iceCream_choice}\nPromise Fullfilled !!`
            ),
          3000
        );
      })
      .catch((err) => {
        reject(err);
      });
  });
};

module.exports = { orderIceCream: buyIceCream };
