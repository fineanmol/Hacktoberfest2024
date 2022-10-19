let songIndex=0
let audioElement=new Audio('/Songs/1.mp3')
let masterPlay= document.getElementById('masterPlay')
let myProgressBar=document.getElementById('myProgressBar')
let gif=document.getElementById('gif')
let masterSongName=document.getElementById('masterSongName')
let songItem=Array.from(document.getElementsByClassName('songItem'))

let songs=[
    {songName:"Chandigarh Kare Ashiqui Remix", filePath:"/Songs/1.mp3", coverPath:"/Images/1.jpg"},
    {songName:"Srivalli-Remix", filePath:"/Songs/Srivalli-Remix(PagalWorld).mp3", coverPath:"/Images/2.jpg"},
    {songName:"I’ll-Be-There-For-You-x-Woh-Din", filePath:"/Songs/3.mp3", coverPath:"/Images/3.jpg"},
    {songName:"Brown-Munde", filePath:"/Songs/4.mp3", coverPath:"/Images/4.jpg"},
    {songName:"Sakhiyaan-Remix", filePath:"/Songs/5.mp3", coverPath:"/Images/5.jpg"},
    {songName:"Maar-Khayegaa", filePath:"/Songs/6.mp3", coverPath:"/Images/6.jpg"},
    {songName:"Main-Agar-Kahoon", filePath:"/Songs/7.mp3", coverPath:"/Images/7.jpg"},
    {songName:"Lafda-Zala", filePath:"/Songs/8.mp3 ", coverPath:"/Images/8.jpg"}
]

songItem.forEach((element,i)=>{
    console.log(element, i)
    element.getElementsByTagName("img")[0].src=songs[i].coverPath
    element.getElementsByClassName("songName")[0].innerText=songs[i].songName
})

//Handle play/pause click
masterPlay.addEventListener('click', ()=>{
    if(audioElement.paused || audioElement.currentTime<=0)
    {
        audioElement.play();
        masterPlay.classList.remove('fa-circle-play')
        masterPlay.classList.add('fa-circle-pause')
        gif.style.opacity=1;
    }else{
        audioElement.pause();
        masterPlay.classList.add('fa-circle-play')
        masterPlay.classList.remove('fa-circle-pause')
        gif.style.opacity=0;
    }
})

//Listening Events
audioElement.addEventListener('timeupdate', ()=>{
    progress=parseInt((audioElement.currentTime/audioElement.duration)*100)
    myProgressBar.value=progress
})

myProgressBar.addEventListener('change', ()=>{
    audioElement.currentTime=myProgressBar.value*audioElement.duration/100
})

const makeAllPlays=()=>{
    Array.from(document.getElementsByClassName('songItemPlay')).forEach((element)=>{
        element.classList.remove('fa-circle-pause')
        element.classList.add('fa-circle-play')
    })
}

Array.from(document.getElementsByClassName('songItemPlay')).forEach((element)=>{
    element.addEventListener('click',(e)=>{
        makeAllPlays();
        songIndex=parseInt(e.target.id)
        e.target.classList.remove('fa-circle-play')
        e.target.classList.add('fa-circle-pause')
        audioElement.src=`Songs/${songIndex}.mp3`
        masterSongName.innerText=songs[songIndex-1].songName
        audioElement.currentTime=0
        audioElement.play();
        gif.style.opacity=1;
        masterPlay.classList.remove('fa-circle-play')
        masterPlay.classList.add('fa-circle-pause')
    })
})

document.getElementById('next').addEventListener('click',()=>{
    if(songIndex>=8)
    {
        songIndex=1;
    }else{
        songIndex+=1;
    }
    audioElement.src=`Songs/${songIndex}.mp3`
    masterSongName.innerText=songs[songIndex-1].songName
    audioElement.currentTime=0
    audioElement.play();
    gif.style.opacity=1;
    masterPlay.classList.remove('fa-circle-play')
    masterPlay.classList.add('fa-circle-pause')
})

document.getElementById('previous').addEventListener('click',()=>{
    if(songIndex<=1)
    {
        songIndex=8;
    }else{
        songIndex-=1;
    }
    audioElement.src=`Songs/${songIndex}.mp3`
    masterSongName.innerText=songs[songIndex-1].songName
    audioElement.currentTime=0
    audioElement.play();
    gif.style.opacity=1;
    masterPlay.classList.remove('fa-circle-play')
    masterPlay.classList.add('fa-circle-pause')
})