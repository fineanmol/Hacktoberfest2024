const Joi = require("joi");
const express = require("express");
const app = express();
app.use(express.json());

const genres = [
  { id: 0, type: "Action" },
  { id: 1, type: "Romance" },
  { id: 2, type: "Fantasme" },
  { id: 3, type: "Fiction" },
  { id: 4, type: "Horror" },
];

app.get("/api/genres", (req, res) => {
  res.send(genres);
});

app.get("/api/genres/:id", (req, res) => {
  const genre = genres.find((c) => c.id === parseInt(req.params.id));
  if (!genre) res.statusCode(404).send("The genre has not been found");
  res.send(genre);
});

function ValidateGenre(genre) {
  const schema = {
    name: Joi.string().min(3).required,
  };

  return Joi.validate(genre, schema);
}

app.post("/api/genres", (req, res) => {
  const { error } = ValidateGenre(req.body);
  if (error) return res.status(400).send(error.details[0].message);
  const genre = {
    id: genres.length + 1,
    name: req.body.name,
  };
  genres.push(genre);
  res.send(genre);
});

app.put("/api/genres/:id", (req, res) => {
  //Validating
  const genre = genres.find((c) => c.id === parseInt(req.params.id));
  if (!genre)
    return res.status(404).send("The genre with the given Id doesn't exist");
  //If invalid return bad request 400

  const { error } = ValidateGenre(req.body);
  if (error) {
    return res.status(404).send(error.details[0].message);
  }
  //Update the genre
  genre.name = req.body.name;
  //return the updated genre
  res.send(genre);
});

app.delete("/api/genres/:id", (req, res) => {
  //Look for the genre
  //Not existing, return 404
  const genre = genres.find((c) => c.id === parseInt(req.params.id));
  if (!genre) res.status(404).send("The genre with the given Id doesn't exist");

  //Delete
  const index = genres.indexOf(genre);
  genres.splice(index, 1);
  //Return
  res.send(genre);
});

const port = process.env.port || 3000;
app.listen(port, () => console.log(`Listening on port ${port}....`));
