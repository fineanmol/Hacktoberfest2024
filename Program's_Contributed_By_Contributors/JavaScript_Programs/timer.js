// ___________________________________
// Make your text into Minion language
// ___________________________________

// enter Text equal to your input text
let Text = 'What do you mean?'

// API URL
const url = 'https://api.funtranslations.com/translate/minion.json'

// making custom URL with your endpoint
const makeURL = (url, Text) => url + '?text=' + Text

// Calling the API to transform your text
const minion = async (url, Text) => {
    const res = await fetch(makeURL(url, Text))
    const resJSON = res.json()
    console.log(resJSON.contents.translated)
}

minion(url, Text)