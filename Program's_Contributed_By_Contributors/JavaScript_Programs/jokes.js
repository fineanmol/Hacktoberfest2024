const express = require('express');
const fetch = require('node-fetch');

const app = express();

async function fetchJoke(url) {
  try {
    const response = await fetch(url);
    const data = await response.json();
    return data.joke;
  } catch (error) {
    console.error('Error fetching joke:', error);
    throw error;
  }
}

// Endpoint to get a random joke
app.get('/joke', async (req, res) => {
  try {
    const joke = await fetchJoke('https://official-joke-api.appspot.com/jokes/random');
    res.json({ joke });
  } catch (error) {
    res.status(500).json({ error: 'Internal Server Error' });
  }
});

// Endpoint to get a random programming joke
app.get('/programming-joke', async (req, res) => {
  try {
    const joke = await fetchJoke('https://official-joke-api.appspot.com/jokes/programming/random');
    res.json({ joke });
  } catch (error) {
    res.status(500).json({ error: 'Internal Server Error' });
  }
});

// Endpoint to get a random dad joke
app.get('/dad-joke', async (req, res) => {
  try {
    const response = await fetch('https://icanhazdadjoke.com/', {
      headers: {
        Accept: 'application/json',
      },
    });
    const data = await response.json();
    res.json({ joke: data.joke });
  } catch (error) {
    res.status(500).json({ error: 'Internal Server Error' });
  }
});

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});
