let speedTypingTestContainer = document.getElementById('speedTypingTest');
let spinner = document.getElementById('spinner');

let submitBtn = document.getElementById('submitBtn');
let resetBtn = document.getElementById('resetBtn');
let uniqueId = "";
let quoteText = "";

function Timer(secs) {
    let timeInSecsEl = document.getElementById('timer');

    let spanEl = document.createElement('span');
    uniqueId = setInterval(function() {
        timeInSecsEl.textContent = secs;

        spanEl.textContent = " seconds";
        spanEl.id = 'seconds';
        timeInSecsEl.appendChild(spanEl);

        secs += 1;
    }, 1000);
    spinner.classList.add('d-none');
}

function createElements() {
    let mainHeadingEl = document.createElement('h1');
    mainHeadingEl.classList.add('main-heading');
    mainHeadingEl.textContent = "Typing Speed Test";
    mainHeadingEl.id = "mainHeading";


    let subHeadingEl = document.createElement('p');
    subHeadingEl.textContent = "On your fingers lets set Go!";
    subHeadingEl.id = "subHeading";
    subHeadingEl.classList.add('para');


    let timerContainerEl = document.createElement('div');
    timerContainerEl.id = "timerContainer";
    timerContainerEl.classList.add('d-flex', 'flex-row');

    let clockImgEl = document.createElement('img');
    clockImgEl.id = "clockImg";
    clockImgEl.src = "https://assets.ccbp.in/frontend/dynamic-webapps/clock-img.png";
    clockImgEl.classList.add('clock-img');


    let timeInSecsEl = document.createElement('p');
    timeInSecsEl.classList.add('secs', 'mt-2');
    timeInSecsEl.id = "timer";

    let quoteContainerEl = document.createElement('div');
    quoteContainerEl.id = "quoteContainer";
    quoteContainerEl.classList.add('quote-container', "p-4", "mt-3", "mb-4", "w-100");

    let quoteEl = document.createElement('p');
    quoteEl.id = "quoteDisplay";
    quoteEl.classList.add("quote-display");


    let breakEl = document.createElement('br');
    breakEl.id = "break";

    let TextAreaEl = document.createElement('textarea');
    TextAreaEl.classList.add('w-100');
    TextAreaEl.id = "quoteInput";
    TextAreaEl.rows = "4";
    TextAreaEl.placeholder = "Type here!!";


    let resultTextEl = document.createElement('p');
    resultTextEl.classList.add('Result', "mb-4");
    resultTextEl.id = "result";


    // addElements();
    speedTypingTestContainer.appendChild(mainHeadingEl);
    speedTypingTestContainer.appendChild(subHeadingEl);
    timerContainerEl.appendChild(clockImgEl);
    timerContainerEl.appendChild(timeInSecsEl);
    speedTypingTestContainer.appendChild(timerContainerEl);
    quoteContainerEl.appendChild(quoteEl);
    quoteContainerEl.appendChild(breakEl);
    quoteContainerEl.appendChild(TextAreaEl);
    speedTypingTestContainer.appendChild(quoteContainerEl);
    speedTypingTestContainer.appendChild(resultTextEl);
}



function addQuote() {
    speedTypingTestContainer.textContent = "";
    createElements();
    
    let quoteEl = document.getElementById('quoteDisplay');
    quoteEl.textContent = quoteText;
    
    let timeInSecsEl = document.getElementById('timer');
    timeInSecsEl.textContent = "0 seconds";
    Timer(1);
}

function getQuote() {
    fetch("https://apis.ccbp.in/random-quote")
        .then(function(response) {
            return response.json();
        })
        .then(function(jsonResult) {
            quoteText = jsonResult.content;
            addQuote();
        });
}

createElements();
getQuote();

submitBtn.onclick = function() {
    let quoteInputEl = document.getElementById('quoteInput');
    let quoteInputElVal = quoteInputEl.value;

    let quoteEl = document.getElementById('quoteDisplay');
    let quoteElVal = quoteEl.textContent;

    let resultTextEl = document.getElementById('result');

    let timeInSecsEl = document.getElementById('timer');
    let time = timeInSecsEl.textContent;

    if (quoteElVal === quoteInputElVal) {
        clearInterval(uniqueId);
        resultTextEl.textContent = "You typed in " + (time);
    } else {
        resultTextEl.textContent = "You typed incorrect sentence";
    }
};

resetBtn.onclick = function() {
    speedTypingTestContainer.textContent = "";
    spinner.classList.remove('d-none');
    getQuote();
};