import { useSelector } from 'react-redux'
import parse from 'html-react-parser';
import { useEffect, useState } from 'react';

export default function Booking() {
  const movieInfo = useSelector((state) => state.movieInfo.value)
  const [movie, setMovie] = useState(movieInfo)

  useEffect(() => {
    const data = localStorage.getItem('movie')
    if (data != null) { setMovie(JSON.parse(data)) }
  }, [])
  console.log(movie)
  return (
    <div className=' text-white  flex bg-slate-950'>
      <img className=" p-8 h-80" src={movie.image?.medium != undefined ? movie.image.medium : "https://via.placeholder.com/360x480"} alt="" />
      <div className='flex-row'>
        <div className='flex'>
          <p className=' p-5'>{movie.name}</p>
          <p className='p-5'>-</p>
          <p className='p-5'>{movie.language}</p>
        </div>
        <hr />
        <div className='p-3 my-2 flex '>
          <p className='p-3'>Pick a Date :</p>
          <input className='text-white p-2 rounded-md bg-slate-800' type='date'></input>
          
        </div>
        <div className='p-3 my-2 flex '>
          <p className='p-3'>Pick a time :</p>
          <select className='text-white p-2 rounded-md bg-slate-800'  name="time" id="time">
            <option value="time1">10:00 AM</option>
            <option value="time2">12:00 PM</option>
            <option value="time3">02:00 PM</option>
            <option value="time4">04:00 PM</option>
          </select>
        </div>
        <div className='flex'>
          <button className='p-3 bg-blue-950 hover:bg-yellow-400 hover:text-black rounded-lg mx-5 '><a href="">Press to Book</a></button>
        </div>


      </div>
    </div>
  )
}