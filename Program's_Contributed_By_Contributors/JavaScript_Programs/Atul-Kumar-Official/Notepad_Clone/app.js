// Area where the user will type
const writingArea = document.querySelector('.textarea');

const span = document.querySelector('span');
const tabs = document.getElementsByClassName('tab');
const modals = document.getElementsByClassName('modal');

const overlay = document.querySelector('.overlay');

const statusBarCheckBox = document.getElementById('status-bar-check-box');
const statusBar = document.querySelector('.status-bar');

// Zoom buttons
const zoomInButton = document.getElementById('zoom-in');
const zoomOutButton = document.getElementById('zoom-out');
const defaultZoom = document.getElementById('default-zoom');

// Zoom submodals
const zoomSubmodalTrigger = document.getElementById('zoom-submodal-trigger');
const zoomSubmodal = document.getElementById('zoom-submodal');

// Font Button
const fontSizeSelector = document.getElementById('font-size');

// Font Modals
const fontModal = document.getElementById('font-modal');
const fontModalOkButton = document.getElementById('font-submit');
const fontModalTrigger = document.getElementById('font-modal-trigger');

// Close buttons
const closeBtn = document.getElementById('close');
const cancelBtn = document.getElementById('cancel');

const timeDateTrigger = document.getElementById('time-date');
const months = ['Jan', 'Feb', 'Mar', 'Apr', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'];

const commandOptions = document.getElementsByClassName('command');

const googleSearcher = document.getElementById('google-search');

// Replace
const replaceBtn = document.getElementById('replace-submit');
const replaceValue = document.getElementById('replace-val');
const replaceModalTrigger = document.getElementById('replace');
const replaceModal = document.getElementById('replace-modal');
const replaceCloseBtn = document.getElementById('close-replace');
const replaceCancelBtn = document.getElementById('replace-cancel');

// Find
const findValue = document.getElementById('find');

// Save Button
const saveBtn = document.getElementById('save');

// Exit Buttons
const exitBtn = document.getElementById('exit');
const exitWindowBtn = document.getElementById('exit-window');

// Open Button
const openBtn = document.getElementById('open-btn');

let activeSubmodals = document.getElementsByClassName('active');

// Load the text saved in localStorage
load();

// Checking if the local storage contains some text
let text = localStorage.getItem('text');
if(text === null)
{
    localStorage.setItem("text", "");
}

// Variables to manage state
let fileHasChanged = false;
let tabHasActivated = false;
let defaultFontSize = 16;

// Adding event listeners

openBtn.addEventListener('click', importData);

exitBtn.addEventListener('click', () => {
    window.close();
})

exitWindowBtn.addEventListener('click', () => {
    window.close();
});

writingArea.addEventListener('input', ()=>
{
    // If the text in writingArea matches the text in localStorage, then asterisk will not 
    // be shown in the title bar else it will be shown
    if(text != writingArea.textContent)
    {
        span.textContent = "*Untitled - Notepad";
        fileHasChanged = true;
    }
    if(text == writingArea.textContent)
    {
        span.textContent = "Untitled - Notepad";
        fileHasChanged = false;
    }
});

googleSearcher.addEventListener('click', () =>
{
    // Get the document selection and search google
    if(document.getSelection)
    {
        let selectedText = document.getSelection().toString();
        location.href = `https://www.google.com/search?q=${selectedText}`;
    }
});

saveBtn.addEventListener('click', save);

replaceModalTrigger.addEventListener('click', ()=>
{
    replaceModal.style.display = "flex";    
    deactivateModal();
    writingArea.setAttribute('contenteditable', false); 
}); 

replaceCancelBtn.addEventListener('click', deactivateReplaceModal);
replaceCloseBtn.addEventListener('click', deactivateReplaceModal);

replaceBtn.addEventListener('click', ()=>
{
    let text = writingArea.textContent;
    let replaceText = replaceValue.value;
    let findText = findValue.value;

    let wordsArray = text.split(" ");

    wordsArray.forEach(function(word, index)
    {
        if(word === findText)
        {
            replacements++;
            wordsArray[index] = replaceText;
        }
    });

    text = wordsArray.join(" ");
    writingArea.textContent = text;
})

timeDateTrigger.addEventListener('click', ()=>
{
    deactivateModal();
    
    let dateTime = new Date();

    let date = dateTime.getDate();
    let month = dateTime.getMonth();
    let year = dateTime.getFullYear();
    let hours = dateTime.getHours();
    let minutes = dateTime.getMinutes();
    
    minutes = minutes == 0 ? "00" : minutes.toString();
    
    let meridian;
    meridian = hours > 12 ? "PM" : "AM";
    
    writingArea.textContent += `${date} ${months[month-1]} ${year} ${hours}:${minutes} ${meridian}`;

});

cancelBtn.addEventListener('click', ()=>
{
    deactivateFontModal();
});

closeBtn.addEventListener('click', ()=>
{
    deactivateFontModal();
});

fontModalOkButton.addEventListener('click', ()=>
{
    deactivateFontModal();

    let fontFamily = document.getElementById('font-family').value;
    let fontStyle = document.getElementById('font-style').value;
    let fontSize = document.getElementById('font-size').value;

    switch(fontStyle)
    {
        case "Regular":
            writingArea.style.fontWeight = "normal";
            writingArea.style.fontStyle = "normal";
            break;
        case "Bold":
            writingArea.style.fontWeight = "bold";
            break;
        case "Italic":
            writingArea.style.fontStyle = "italic";
            break;
        case "Bold-Italic":
            writingArea.style.fontWeight = "bold";
            writingArea.style.fontStyle = "italic";
            break;  
    }

    writingArea.style.fontFamily = fontFamily;
    writingArea.style.fontSize = fontSize + "px";
});

fontModalTrigger.addEventListener('click', ()=>
{
    deactivateModal();
    fontModal.style.display = "flex";
    writingArea.setAttribute('contenteditable', false);
});

zoomInButton.addEventListener('click', zoomIn);
zoomOutButton.addEventListener('click', zoomOut);
defaultZoom.addEventListener('click', loadDefault);

zoomSubmodalTrigger.addEventListener('click', ()=>
{
    if(zoomSubmodal.classList.contains("active"))
    {
        zoomSubmodal.classList.remove("active");
    }
    else
    {
        zoomSubmodal.classList.add("active");
    }
});

overlay.addEventListener('click', ()=>
{
    deactivateModal();
    deactivateSubmodals();
    overlay.style.display = "none";
    tabHasActivated = false;
});

statusBarCheckBox.addEventListener('click', ()=>
{
    if(statusBar.classList.contains("hidden"))
    {
        statusBar.classList.remove("hidden");
        statusBarCheckBox.classList.add("active-tab");
    }
    else
    {
        statusBar.classList.add("hidden");
        statusBarCheckBox.classList.remove("active-tab");
    }
});

for(let commandOption of commandOptions)
{
    commandOption.addEventListener('click', event =>
    {
        let action = event.target.id;
        
        document.execCommand(action, false, null);
    });
}

for(let tab of tabs)
{
    tab.addEventListener('click', ()=>
    {
        tabHasActivated = true;
        activateModal(generateModalId());
        activateOverlay();
        deactivateSubmodals();
    });
    tab.addEventListener('mouseover', ()=>
    {
        if(tabHasActivated)
        {
            activateModal(generateModalId());
            activateOverlay();
            deactivateSubmodals();
        }
    })
}

// Declaring functions

// Function: Saves the text to localStorage
function save()
{
    deactivateModal();

    localStorage.setItem('text', writingArea.textContent);

    let text = localStorage.getItem('text');

    if(text != writingArea.textContent)
    {
        span.textContent = "*Untitled - Notepad";
        fileHasChanged = true;
    }
    if(text == writingArea.textContent)
    {
        span.textContent = "Untitled - Notepad";
        fileHasChanged = false;
    }
}

// Function: Loads the text from localStorage
function load()
{
    let text = localStorage.getItem('text');
    writingArea.textContent = text;
}

// Function: Deactivates the replace modal
function deactivateReplaceModal()
{
    replaceModal.style.display = "none";
    writingArea.setAttribute('contenteditable', true);
}

// Function: Deactivates the font modal
function deactivateFontModal()
{
    fontModal.style.display = "none";
    writingArea.setAttribute('contenteditable', true);
}

// Dynamically creating font sizes
for(let i = 1; i <= 100; i++)
{
    if(i === 16)
    {
        let option = `<option value = "${i}" selected>${i}</option>`
        fontSizeSelector.innerHTML += option;
    }
    else
    {
        let option = `<option value = "${i}">${i}</option>`;
        fontSizeSelector.innerHTML += option;
    }
}

// Function: Generates modal ID
function generateModalId()
{
    let tabId = event.target.id;
    let modalId = tabId.slice(0, tabId.indexOf("-")) + "-modal";
    return modalId;
}

// Function: Activates the specified modal
function activateModal(modalToBeActivated)
{
    for(let modal of modals)
    {
        modal.style.display = "none";
    }
    document.getElementById(modalToBeActivated).style.display = "block";
}

// Function: Activates the overlay
function activateOverlay()
{
    overlay.style.display = "block";
}

// Function: Deactives all the modals
function deactivateModal()
{
    for(let modal of modals)
    {
        modal.style.display = "none";
    }
}

// Function: Deactives all the submodals
function deactivateSubmodals()
{
    activeSubmodals = document.getElementsByClassName('active');
    for(let activeSubmodal of activeSubmodals)
    {
        activeSubmodal.classList.remove("active");
    }
}

// Function: Increases the font size by 2px
function zoomIn()
{
    defaultFontSize += 2;
    changeZoom(defaultFontSize);
}

// Function: Decreases the font size by 2px
function zoomOut()
{
    defaultFontSize -= 2;
    changeZoom(defaultFontSize);
}

// Function: Sets the font size to 16px
function loadDefault()
{
    defaultFontSize = 16;
    changeZoom(defaultFontSize);
}

// Function: Changes the font size
function changeZoom(defaultFontSize)
{
    writingArea.style.fontSize = `${defaultFontSize}px`;
}

// Function: Imports the data from the client's system
function importData(){
    const input = document.createElement('input');
    input.type = "file";
    input.click();

    input.addEventListener('change', () => {
        let file = input.files[0];
        let text = file.text();
        text
        .then(content => {
            writingArea.innerHTML = content;
            let text = localStorage.getItem('text');

            span.textContent = "*Untitled - Notepad";
            fileHasChanged = true;

            deactivateModal();
        })
        .catch(error => {
            console.log(`Failed to import data: ${error}`);
        });
    })
}