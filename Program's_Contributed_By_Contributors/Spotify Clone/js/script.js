
// document.addEventListener('DOMContentLoaded', function() {

//     var playBtn = document.querySelector("#playBtn")
//     var PauseBtn = document.querySelector("#pauseBtn")
//     var music = new Audio('assets/Eternal.mp3')
//     var like = document.querySelector("#like")
//     var likedSong = document.querySelector(".liked")

//     playBtn.addEventListener("click", () => {
//         music.play()
//         console.log("music is playing")
//         playBtn.style.display = "none"
//         PauseBtn.style.display = "inline"
//     })

//     PauseBtn.addEventListener("click", () => {
//         music.pause()
//         console.log("music stopped")
//         playBtn.style.display = "inline"
//         PauseBtn.style.display = "none"
//     })

//     like.addEventListener("click", () => {

//         if (like.style.color === "red") {
//             like.style.color = "grey"
//             likedSong.innerHTML = '<div> </div>'
//         } else {
//             like.style.color = "red"
//             likedSong.innerHTML = '<div class="card"> <img src="images/artist_image.jpeg" alt="Eternal">  <div class="card_info"> <p class="card_name">Eternal Youth</p> <p class="card_artist">RUDE</p> </div> </div>'

//         }
//     })

// })


const {songs} = {
    "songs": [
        {
            "name": "Eternal Youth",
            "artist": "Rude",
            "location": "./assets/Eternal.mp3",
            "image": "./images/artist_image.jpeg",
            "liked": true,
            "id": 0
        },
        {
            "name": "Never Gonna Give You Up",
            "artist": "Rick Astely",
            "location": "./assets/NGGYU.mp3",
            "image": "./images/content/nggyp.jpg",
            "liked": true,
            "id": 1
        },
        {
            "name": "Keeping It",
            "artist": "Sou",
            "location": "./assets/keepingIt.mp3",
            "image": "./images/content/keepingIt.png",
            "liked": false,
            "id": 2
        },
        {
            "name": "Eye of the Tiger",
            "artist": "Surviour",
            "location": "./assets/eyeTiger.mp3",
            "image": "./images/content/survivor.jpg",
            "liked": false,
            "id": 3
        },
        {
            "name": "Kenny G Collection",
            "artist": "Kenny G",
            "location": "./assets/kenny.mp3",
            "image": "./images/content/kennyg.jpg",
            "liked": false,
            "id": 4
        },
        {
            "name": "Noctornal",
            "artist": "The Midnight",
            "location": "./assets/noctornal.mp3",
            "image": "./images/content/noctornal.jpg",
            "liked": false,
            "id": 5
        },
        {
            "name": "Unravel",
            "artist": "TK",
            "location": "./assets/unravel.mp3",
            "image": "./images/content/unravel.jpg",
            "liked": false,
            "id": 6
        }
    ]
}

document.addEventListener("DOMContentLoaded", () => {
    const playerHead = document.getElementById("player");
    let playBtn = document.getElementById("playBtn");
    let pauseBtn = document.getElementById("pauseBtn");
    let cardCollections = document.querySelectorAll(".card_collection_main");
    let currentSong = new Audio();
    
    playerHead.style.display = "none";

    const createCard = (song) => {
        const card = document.createElement("div");
        const img = document.createElement("img");
        const cardInfo = document.createElement("div");
        const cardName = document.createElement("p");
        const cardArtist = document.createElement("p");

        card.className = "card";
        cardInfo.clasName = "card_info";
        cardName.className = "card_name";
        cardArtist.className = "card_artist";

        cardName.innerHTML = song.name;
        cardArtist.innerHTML = song.artist;
        img.src = song.image;
        img.alt = song.name;

        cardInfo.append(cardName, cardArtist);
        card.append(img, cardInfo);

        card.onclick = function(){
            playerHead.style.display = "flex";
            currentSong = updatePlayer(song)
            playPauseFunc(currentSong)
            //returns the song, updates the player head, adds play pause functionality
        }

        return card;
    }

    const updatePlayer = ({name, artist, location, image, liked, id}) => {
        currentSong.setAttribute("src", location);

        const songContainer = document.querySelector(".song");
        const artistContainer = document.querySelector(".artist");
        const likeBtn = document.querySelector(".likeBtn");
        const artistImage = document.querySelector(".artist_image");
        const endTime = document.getElementById("endTime");

        playBtn = document.getElementById("playBtn");
        pauseBtn = document.getElementById("pauseBtn");

        playBtn.style.display = "inline";
        pauseBtn.style.display = "none";

        songContainer.innerHTML = name;
        artistContainer.innerHTML = artist;
        artistImage.src = image;

        likeBtn.id = id;
        likeBtn.style.color = "grey";
        if(liked){
            likeBtn.style.color = "red"
        }

        likeBtn.onclick = function(){
            likeSong(id, likeBtn, name)
        }

        currentSong.onloadedmetadata = () => {
            let duration = currentSong.duration;
            duration = (duration/60).toPrecision(3) + "";
            endTime.innerHTML = duration;
        }
        return currentSong;
    }

    const playPauseFunc = (song) => {
        playBtn = document.getElementById("playBtn");
        pauseBtn = document.getElementById("pauseBtn");

        playBtn.addEventListener("click", () => {
            song.play();
            playBtn.style.display = "none";
            pauseBtn.style.display = "inline";
        });

        pauseBtn.addEventListener("click", () => {
            song.pause();
            playBtn.style.display = "inline";
            pauseBtn.style.display = "none";
        })
    }

    const likeSong = (id, likeBtn, songName) => {
        cardCollections = document.querySelectorAll(".card_collection_main");
        let likedSongs = cardCollections[0].children;
        likedSongs = Array.from(likedSongs);

        if(songs[id].liked){
            console.log(likeBtn)
            likeBtn.style.color = "grey";
            songs[id].liked = false;
            likedSongs.forEach((songCard) => {
                const name = songCard.lastChild.firstChild.innerHTML;
                if(name == songName){
                    songCard.style.display = "none";
                    songCard.remove();
                }
            });
        } else {
            songs[id].liked = true;
            likeBtn.style.color = "red";
            cardCollections[0].append(createCard(songs[id]))
        }
    }

    const updateCollection = () => {
        cardCollections = document.querySelectorAll(".card_collection_main");
        cardCollections.forEach((collection, index) => {
            if(index === 0){
                songs.forEach((song) => {
                    if(song.liked){
                        collection.append(createCard(song))
                    }
                })
            } else {
                songs.forEach((song) => {
                    collection.append(createCard(song));
                });
            }
            if(index%2 !== 0){
                collection.classList.toggle("reverse")
            }
        })
    }

    updateCollection();

})



