const form = document.querySelector('#searchForm');
form.addEventListener('submit', async function (e) {
    e.preventDefault();

    const searchTerm = form.elements.query.value;
    const config = { params: {q: searchTerm}}
    const res = await axios.get(`https://api.tvmaze.com/search/shows`, config)
    makeImages(res.data);
    form.elements.query.value = '';
})

const makeImages = (shows) => {
    const TV_Shows_lists = document.querySelector('.shows-list');
    TV_Shows_lists.innerHTML = "";

    for(let result of shows){
        if(result.show.image){

            const Shows_container = document.createElement('div');
            Shows_container.classList.add('shows-container');

            const Image_container = document.createElement('div');
            Image_container.classList.add('show-poster');

            const Img = document.createElement('img')
            Img.src = result.show.image.medium;

            Image_container.appendChild(Img);
            Shows_container.appendChild(Image_container);
            TV_Shows_lists.appendChild(Shows_container);

            
            
        }
    }
}


// const options = {
// 	method: 'GET',
// 	headers: {
// 		'X-RapidAPI-Key': '11b7df287emsha5582c68d488b43p1184ecjsn2d2833e64b7a',
// 		'X-RapidAPI-Host': 'imdb8.p.rapidapi.com'
// 	}
// };

// fetch('https://imdb8.p.rapidapi.com/auto-complete?q=game', {
//     "method": 'GET',
// 	"headers": {
// 		'X-RapidAPI-Key': '11b7df287emsha5582c68d488b43p1184ecjsn2d2833e64b7a',
// 		'X-RapidAPI-Host': 'imdb8.p.rapidapi.com'
// 	}

// })
// .then(response => response.json())
// .then(data => {
//     const list = response.d;

//     list.forEach((item) => {
//         const Movie_lists = document.querySelector('.movies-list');

//         const name = item.l;
//         const posterImage = item.i.imageUrl;
            
//         const Movies_container = document.createElement('div');
//         Movies_container.classList.add('movies-container');

//         const Image_container = document.createElement('div');
//         Image_container.classList.add('movie-poster');

//         const Img = document.createElement('img')
//         Img.src = posterImage;

//         const movie_details = document.createElement('div');
//         movie_details.classList.add('movie-details')

//         const movie_name = document.createElement('p');
//         movie_name.innerText = name;

//         Image_container.appendChild(Img);
//         movie_details.appendChild(movie_name);

//         Movies_container.appendChild(Image_container);
//         Movies_container.appendChild(movie_details);

//         Movie_lists.appendChild(Movies_container);



//     })

// })
// .catch(err => console.error(err));