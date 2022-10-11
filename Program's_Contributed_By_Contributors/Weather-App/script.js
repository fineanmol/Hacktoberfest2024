let weather = {
    "apiKey": "68ed4abc3779df4fb584dd461b1ad7f3",
    fetchWeather: function (city) {
        fetch(
            "https://api.openweathermap.org/data/2.5/weather?q="
            + city
            + "&units=metric&appid="
            + this.apiKey
        )
            // .then((Response) => Response.json())
            .then((Response) => {
                if (!Response.ok) {
                    alert("Error! No weather found. Please Enter Correct Location.");
                    throw new Error("Error! No weather found. Please Enter Correct Location.");
                }
                return Response.json();
            })
            .then((data) => this.displayWeather(data))
    },
    displayWeather: function (data) {
        const { name } = data;
        const { icon, description } = data.weather[0];
        const { temp, temp_min, temp_max , humidity } = data.main;
        const { speed } = data.wind;
        const { country } = data.sys;
        // const { } = data.
        // console.log(name,icon,description,temp,humidity,speed)
        document.querySelector(".city").innerText = "Weather in " + name + " (" + country + ")";
        document.querySelector(".icon").src = "https://openweathermap.org/img/wn/" + icon + ".png";
        document.querySelector(".description").innerText = description;
        document.querySelector(".temp").innerText = temp + "°C";
        document.querySelector(".Humidity").innerText = "Humidity: " + humidity + "%";
        document.querySelector(".Wind").innerText = "Wind Speed: " + speed + "Km/h";
        document.querySelector(".mintemp").innerText = "Minimum(Temp): " + temp_min + "°C";
        document.querySelector(".maxtemp").innerText = "Maximun(Temp): " + temp_max + "°C";
    },
    search: function () {
        this.fetchWeather(document.querySelector(".search-bar").value);
    }

};

document.querySelector(".search button")
    .addEventListener("click", function () {
        weather.search();
    });
document.querySelector(".search-bar").addEventListener("keyup", function (event) {
    if (event.key == "Enter") {
        weather.search();
    }
});

weather.fetchWeather("Jabalpur");
