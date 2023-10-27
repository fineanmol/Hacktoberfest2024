console.log("WElcome To Spotify")
let songIndex =0;
let songinfo= document.getElementsByClassName('songInfo')
let masterPlay = document.getElementById('MasterPlay')
let forward = document.getElementById('forward')
let backward = document.getElementById('backward')
let songitem = Array.from( document.getElementsByClassName('SongItems'))
let myprogressbar = document.getElementById('songprogress')
let mastername = document.getElementById('mastername')
let mastercover = document.getElementById('playingimg')

console.log(songitem)
let songs = [
    {songname:"Dream on - Aerosmith",filepath:"sources/Songs/DreamOn.mp3",coverpath:"sources/covers/DreamOn.jpeg"},
    {songname:"Good Riddance - Green Day",filepath:"sources/Songs/GoodRiddance.mp3",coverpath:"sources/covers/goodridance.jpeg"},
    {songname:"Hotel California - Eagles",filepath:"sources/Songs/HotelCalifornia.mp3",coverpath:"sources/covers/hotel.jpeg"},
    {songname:"Knockin on.. - Gun N' Roses",filepath:"sources/Songs/KnockinOnHeavensDoor.mp3",coverpath:"sources/covers/goodridance.jpeg"},
    {songname:"Stairway To Heaven - Led Z",filepath:"sources/Songs/Stairway to Heaven.mp3",coverpath:"sources/covers/Stairway.jpeg"},
    {songname:"Sweater Weather - The Neighbourhood",filepath:"sources/Songs/Sweater Weather.mp3",coverpath:"sources/covers/sweaterweather.jpeg"},
    {songname:"Sweet Child O' Mine - Guns N' Roses",filepath:"sources/Songs/Sweet Child O' Mine.mp3",coverpath:"sources/covers/sweet.jpeg"}
]   

songitem.forEach((Element,Index)=>{
    console.log(Element,Index)
    Element.getElementsByTagName("img")[0].src=songs[Index].coverpath;
    Element.getElementsByClassName("songname")[0].innerText = songs[Index].songname;
})

let audioElement= new Audio ('sources/Songs/DreamOn.mp3')
// handle play pause
masterPlay.addEventListener('click',()=>{
    if(audioElement.paused || audioElement.currentTime<=0){
        audioElement.play();
        masterPlay.classList.remove('fa-play-circle')
        masterPlay.classList.add('fa-pause-circle')
    }
    else{
        audioElement.pause();
        masterPlay.classList.remove('fa-pause-circle')
        masterPlay.classList.add('fa-play-circle')

    }

})  

audioElement.addEventListener('timeupdate',()=>{

    let progress = parseInt((audioElement.currentTime/audioElement.duration)*100)
    myprogressbar.value=progress

})

myprogressbar.addEventListener('change',()=>{
    audioElement.currentTime= (myprogressbar.value*audioElement.duration)/100
})

songitem.forEach((Element,i)=>{
    Element.addEventListener('click',(e)=>{
        console.log(Element,i)
        songIndex=i
        audioElement.src=songs[songIndex]['filepath']
        audioElement.currentTime=0;
        audioElement.play(); 
    })
    
})

document.getElementById('forward').addEventListener('click',()=>{
    if(songIndex>=6){
        songIndex = 0
    }
    else{
        songIndex+=1
    }
    mastercover.src=songs[songIndex]['coverpath']
    mastername.innerText=songs[songIndex]['songname']
    audioElement.src=songs[songIndex]['filepath']
    audioElement.currentTime=0;
    audioElement.play(); 
})

document.getElementById('backward').addEventListener('click',()=>{
    if(songIndex<=0){
        songIndex =6 
    }
    else{
        songIndex-=1
    }
    mastercover.src=songs[songIndex]['coverpath']
    mastername.innerText=songs[songIndex]['songname']
    audioElement.src=songs[songIndex]['filepath']
    audioElement.currentTime=0;
    audioElement.play(); 
    
}) 