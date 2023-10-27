import { useEffect, useState } from "react"
import { Card } from "./card"
import axios from "axios";
// 3bc286ad
function Home() {
  //   const API_URL = "http://www.omdbapi.com/?apikey=3bc286ad"
  //   // const API_URL = "http://www.omdbapi.com/?i=tt3896198&apikey=3bc286ad"



  const searchMovies = (title) => {
    axios.get(`https://api.tvmaze.com/search/shows?q=${title}`)
      .then(response => {
        console.log(response.data);
        setMovies(response.data)
      })
      .catch(error => {
        console.log(error);
      });
  }




const [movies, setMovies] = useState([])
const [searchName, setSearchName] = useState("")
useEffect(() => {
  searchMovies("all")
}, [])

return (
  <div className=" flex-col justify-center bg-slate-950">
    
    <div className=" bg-slate-500 rounded-md mx-10 my-4 p-3 flex">
      <input onChange={(e) => { e.target.value!="" && setSearchName(e.target.value) }} placeholder="Search for movies..." className=" border-hidden rounded-md w-5/6 h-9 mx-3 p-3" type="text" />
      <button onClick={() => { searchMovies(searchName) }} className=" bg-slate-400 mx-3 hover:bg-slate-600 hover:text-white active:text-black  border-hidden rounded-md w-2/6">Search</button>
    </div>
    <div className=" flex flex-wrap m-12">
      {
        movies?.map((item) => {
          return (
            <Card key={item.show.id} movie={item.show} />
          )
        })
      }

      {
        movies.length==0 && <h1 className="text-white p-10">No Movies Found</h1>
      }


      {/* <Card movie={movie1}/> */}fo

    </div>
  </div>
)
}

export default Home
