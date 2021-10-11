const API_URL = 'https://api.themoviedb.org/3/discover/movie?sort_by=popularity.desc&api_key=7ea3b98fee3d82b5af6bcc62a153117f&page=1'

const SEARCH_API = 'https://api.themoviedb.org/3/search/movie?api_key=7ea3b98fee3d82b5af6bcc62a153117f&query="'

const IMG_path = 'https://image.tmdb.org/t/p/w1280'

const form = document.getElementById('form')
const search = document.getElementById('search')
const main = document.getElementById('main')

getMovies(API_URL)

async function getMovies(url){
    const res = await fetch(url)
    const data = await res.json()
    // console.log(data.results)
    showMovies(data.results)
}

function showMovies(movies){
    main.innerHTML = ''
    movies.forEach((movie)=>{
        const{ title, poster_path, vote_average, overview,release_date } = movie
        
        const movieElement = document.createElement('div')
        movieElement.classList.add('movie')
        movieElement.innerHTML=`
				<img
					src="${IMG_path+poster_path}"
					alt="${title}"
				/>
				<div class="movie-info">
					<h3>${title}</h3>
					<span class="${getVoteColor(vote_average)}">${vote_average}</span>
				</div>
                
				<div class="overview">
					<h3>Overview</h3>
					${overview}
				</div>
        `

        main.appendChild(movieElement)

    })
}

function getVoteColor(vote){
    if(vote>=8){
        return 'green'
    }
    else if(vote>=6){
        return 'orange'
    }else{
        return 'red'
    }
}

form.addEventListener('submit',(e)=>{
    e.preventDefault()

    const searchTerm = search.value

    if(searchTerm && searchTerm!==''){
        getMovies(SEARCH_API + searchTerm)
        search.value=''
    }else{
        window.location.reload()
    }
})

