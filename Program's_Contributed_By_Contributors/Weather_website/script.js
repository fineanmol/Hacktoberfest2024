const apiKey = "c21ef0ab41cdd3b3089d1ce8db8e3c21";
const apiURL = `https://api.openweathermap.org/data/2.5/weather?q=mumbai`;

const searchBox = document.querySelector(".search input");
let searchBtn = document.querySelector(".search button");
const baseURL = "https://api.openweathermap.org/data/2.5/weather?q=";

const weatherIcon = document.querySelector(".weather-icon");


async function defaultWeather() {
    const response = await fetch(apiURL + `&appid=${apiKey}&units=metric`);
    let data = await response.json();
    document.querySelector(".city").innerHTML = data.name;
    document.querySelector(".temp").innerHTML = Math.round(data.main.temp) + "°C"
    document.querySelector(".wind").innerHTML = data.wind.speed + "km/h"
    document.querySelector(".humidity").innerHTML = data.main.humidity + "%";
}

defaultWeather();


async function checkWeather() {

    let cityName = searchBox.value;
    const reqURL = `${baseURL}${cityName}&appid=${apiKey}&units=metric`;
    const response = await fetch(reqURL);
    let data = await response.json();
    document.querySelector(".city").innerHTML = data.name;
    document.querySelector(".temp").innerHTML = Math.round(data.main.temp) + "°C"
    document.querySelector(".wind").innerHTML = data.wind.speed + "km/h"
    document.querySelector(".humidity").innerHTML = data.main.humidity + "%";

    if (data.weather[0].main == "Clouds") {
        weatherIcon.src = "images/clouds.png";
    }

    else if (data.weather[0].main == "Clear") {
        weatherIcon.src = "images/clear.png";
    }

    else if (data.weather[0].main == "Drizzle") {
        weatherIcon.src = "images/drizzle.png";
    }

    else if (data.weather[0].main == "Mist") {
        weatherIcon.src = "images/mist.png";
    }

    else if (data.weather[0].main == "Rain") {
        weatherIcon.src = "images/rain.png";
    }

    else if (data.weather[0].main == "Snow") {
        weatherIcon.src = "images/snow.png";
    }
}

searchBtn.addEventListener("click", () => {
    checkWeather()
})
