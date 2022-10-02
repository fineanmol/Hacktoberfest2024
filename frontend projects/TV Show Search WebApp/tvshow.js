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