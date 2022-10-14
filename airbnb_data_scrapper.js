// A simple program that can go to airbnb all listings page and scrape all data and store that in data.json file
const puppeteer = require("puppeteer");
const fs = require("fs");
const { scrollPageToBottom } = require("puppeteer-autoscroll-down");

(async () => {
  const result = [];
  const browser = await puppeteer.launch({
    headless: false,
  });

  const page = await browser.newPage();
  await page.goto("https://www.airbnb.com/", { waitUntil: "domcontentloaded" });

  scrollPageToBottom(page, {
    size: 500,
    delay: 250,
    stepsLimit: 25,
  });

  const hi = async () => {
    const links = await page.evaluate(() => {
      return Array.from(document.querySelectorAll("a.ln2bl2p")).map(
        (e) => e.href
      );
    });

    for (let i = 0; i < links.length; i++) {
      const newPage = await browser.newPage();
      await newPage.goto(links[i], { waitUntil: "domcontentloaded" });
      await newPage.waitForSelector(".ll4r2nl");
      const data = await getData(newPage);
      result.push(data);
      newPage.close();
      const json = JSON.stringify(result);
      fs.writeFile("data.json", json, "utf8", function (err) {
        if (err) throw err;
        console.log("complete");
      });
    }
    // browser.close();
  };
  setTimeout(() => hi(), 5000);
})();

const getData = async (newPage) => {
  try {
    await newPage.waitForSelector(".r1rl3yjt");
    await scrollPageToBottom(newPage);

    const data = await newPage.evaluate(async () => {
      const title = "_fecoyn4";
      const rating = "_17p6nbba";
      const review = "_11eqlma4";
      const lt = "_9xiloll";
      const price = "_tyxjp1";
      const about = "ll4r2nl";
      const reviews_cards = "r1rl3yjt";

      const data = {
        title: document.querySelector("." + title).textContent,
        rating: document.querySelector("." + rating).textContent,
        review: document.querySelector("." + review).textContent,
        lt: document.querySelector("." + lt).textContent,
        images: [
          ...document
            .querySelector("._88xxct")
            .querySelector("._skzmvy")
            .querySelectorAll("img"),
        ].map((img) => ({ url: img.src })),
        price: document.querySelector("." + price).textContent,
        about: document.querySelector("." + about).textContent,
        user: {
          profile: {
            url: document.querySelector("._9ofhsl").src,
          },
          name: document.querySelector(".tehcqxo h2").textContent,
          joinedAt: document.querySelector(".tehcqxo .l7n4lsf").textContent,
          reviews: document.querySelector(".c8jnr5n .l1dfad8f").textContent,
        },
        reviews: [...document.querySelectorAll("." + reviews_cards)].map(
          (e) => ({
            reivew: e.querySelector(".ll4r2nl").textContent,
            user: {
              profile: { url: e.querySelector("img").src },
              name: e.querySelector("._14i3z6h").textContent,
              createdAt: e.querySelector("li._1f1oir5").textContent,
            },
          })
        ),
      };

      return data;
    });

    return data;
  } catch (err) {
    console.log(err.message);
    return [];
  }
};
