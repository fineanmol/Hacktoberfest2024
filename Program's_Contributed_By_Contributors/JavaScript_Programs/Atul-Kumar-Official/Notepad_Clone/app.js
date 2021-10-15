const writingArea = document.querySelector('.textarea');
const span = document.querySelector('span');
const tabs = document.getElementsByClassName('tab');
const modals = document.getElementsByClassName('modal');
const overlay = document.querySelector('.overlay');
const statusBarCheckBox = document.getElementById('status-bar-check-box');
const statusBar = document.querySelector('.status-bar');
const zoomInButton = document.getElementById('zoom-in');
const zoomOutButton = document.getElementById('zoom-out');
const defaultZoom = document.getElementById('default-zoom');
const zoomSubmodalTrigger = document.getElementById('zoom-submodal-trigger');
const zoomSubmodal = document.getElementById('zoom-submodal');
const fontSizeSelector = document.getElementById('font-size');
const closeBtn = document.getElementById('close');
const fontModal = document.getElementById('font-modal');
const fontModalOkButton = document.getElementById('font-submit');
const cancelBtn = document.getElementById('cancel');
const fontModalTrigger = document.getElementById('font-modal-trigger');
const timeDateTrigger = document.getElementById('time-date');
const months = ['Jan', 'Feb', 'Mar', 'Apr', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'];
const commandOptions = document.getElementsByClassName('command');
const googleSearcher = document.getElementById('google-search');
const replaceBtn = document.getElementById('replace-submit');
const findValue = document.getElementById('find');
const replaceValue = document.getElementById('replace-val');
const replaceModalTrigger = document.getElementById('replace');
const replaceModal = document.getElementById('replace-modal');
const replaceCloseBtn = document.getElementById('close-replace');
const replaceCancelBtn = document.getElementById('replace-cancel');
const saveBtn = document.getElementById('save');
let activeSubmodals = document.getElementsByClassName('active');


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

writingArea.addEventListener('input', ()=>
{
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

    let replacements = 0;

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
    if(minutes == 0)
    {
        minutes = "00";
    }

    if(hours > 12)
    {
        let meridian = "PM";
        writingArea.textContent += `${date} ${months[month-1]} ${year} ${hours}:${minutes} ${meridian}`;
    }
    else
    {
        let meridian = "AM";
        writingArea.textContent += `${date} ${month} ${year} ${hours} ${minutes} ${meridian}`;
    }

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

function load()
{
    let text = localStorage.getItem('text');
    writingArea.textContent = text;
}


function deactivateReplaceModal()
{
    replaceModal.style.display = "none";
    writingArea.setAttribute('contenteditable', true);
}

function deactivateFontModal()
{
    fontModal.style.display = "none";
    writingArea.setAttribute('contenteditable', true);
}

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

function generateModalId()
{
    let tabId = event.target.id;
    let modalId = tabId.slice(0, tabId.indexOf("-")) + "-modal";
    return modalId;
}

function activateModal(modalToBeActivated)
{
    for(let modal of modals)
    {
        modal.style.display = "none";
    }
    document.getElementById(modalToBeActivated).style.display = "block";
}

function activateOverlay()
{
    overlay.style.display = "block";
}

function deactivateModal()
{
    for(let modal of modals)
    {
        modal.style.display = "none";
    }
}

function deactivateSubmodals()
{
    activeSubmodals = document.getElementsByClassName('active');
    for(let activeSubmodal of activeSubmodals)
    {
        activeSubmodal.classList.remove("active");
    }
}

function zoomIn()
{
    defaultFontSize += 2;
    changeZoom(defaultFontSize);
}

function zoomOut()
{
    defaultFontSize -= 2;
    changeZoom(defaultFontSize);
}

function loadDefault()
{
    defaultFontSize = 16;
    changeZoom(defaultFontSize);
}

function changeZoom(defaultFontSize)
{
    writingArea.style.fontSize = `${defaultFontSize}px`;
}