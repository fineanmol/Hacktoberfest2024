const API_URL = 'https://api.chucknorris.io/jokes/random'

/**
 * To run this you will need node installed
 * @author milos5593
 */
async function GET_JOKES() {
    const response = await fetch(API_URL)
    const { value } = await response.json()

    console.log(value)
}

GET_JOKES()
