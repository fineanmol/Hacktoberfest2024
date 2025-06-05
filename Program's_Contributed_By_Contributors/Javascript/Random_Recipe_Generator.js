<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Random Recipe Generator</title>
    <style>
        /* Add some basic styling for the recipe display */
        body {
            font-family: Arial, sans-serif;
        }
        .recipe {
            margin: 20px;
            padding: 20px;
            border: 1px solid #ccc;
            border-radius: 5px;
        }
        .recipe h2 {
            font-size: 24px;
        }
    </style>
</head>
<body>
    <div class="recipe">
        <h2 id="recipeTitle">Recipe Title</h2>
        <h3>Ingredients:</h3>
        <ul id="ingredientList">
            <li>Ingredient 1</li>
            <li>Ingredient 2</li>
            <li>Ingredient 3</li>
        </ul>
        <h3>Instructions:</h3>
        <ol id="instructionList">
            <li>Step 1</li>
            <li>Step 2</li>
            <li>Step 3</li>
        </ol>
    </div>
    <button id="generateButton">Generate Recipe</button>

    <script>
        // Sample data for the recipe
        const recipes = [
            {
                title: "Spaghetti Bolognese",
                ingredients: ["Spaghetti", "Ground beef", "Tomato sauce", "Onion", "Garlic", "Olive oil"],
                instructions: ["Heat olive oil in a pan.", "Sauté chopped onion and garlic.", "Add ground beef and brown it.", "Stir in tomato sauce.", "Cook spaghetti according to package instructions.", "Serve sauce over cooked spaghetti."]
            },
            {
                title: "Caesar Salad",
                ingredients: ["Romaine lettuce", "Croutons", "Parmesan cheese", "Caesar dressing"],
                instructions: ["Toss lettuce with dressing.", "Sprinkle with cheese and croutons."]
            }
            // Add more recipes here...
        ];

        // Function to generate a random recipe
        function generateRandomRecipe() {
            const randomIndex = Math.floor(Math.random() * recipes.length);
            const randomRecipe = recipes[randomIndex];

            document.getElementById("recipeTitle").textContent = randomRecipe.title;
            
            const ingredientList = document.getElementById("ingredientList");
            ingredientList.innerHTML = "";
            randomRecipe.ingredients.forEach(ingredient => {
                const li = document.createElement("li");
                li.textContent = ingredient;
                ingredientList.appendChild(li);
            });
            
            const instructionList = document.getElementById("instructionList");
            instructionList.innerHTML = "";
            randomRecipe.instructions.forEach(instruction => {
                const li = document.createElement("li");
                li.textContent = instruction;
                instructionList.appendChild(li);
            });
        }

        // Attach the generateRandomRecipe function to the button click event
        const generateButton = document.getElementById("generateButton");
        generateButton.addEventListener("click", generateRandomRecipe);

        // Generate a random recipe on page load
        generateRandomRecipe();
    </script>
</body>
</html>
