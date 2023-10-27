import { useSelector } from 'react-redux'
import parse from 'html-react-parser';
import { useEffect, useState } from 'react';
import { Link } from 'react-router-dom';

export default function Summary() {
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
                    <p className=' p-5'>{movie.rating.average}</p>
                </div>
                <hr />
                <div className='p-5 pb-2'>
                    {parse(movie.summary)}
                </div>
                <p className='px-5 py-1'>{movie.language}</p>
                <p className='px-5 py-1'>{movie.premiered}</p>
                <div className='flex'>
                    <button className='px-5 py-1 bg-blue-950 hover:bg-yellow-400 hover:text-black rounded-lg m-2 '><a href={movie.officialSite}>Visit Official Page</a></button>
                    <Link className='px-5 py-1 bg-blue-950 hover:bg-yellow-400 hover:text-black rounded-lg m-2 ' to="/booking">Book This Movie/Series</Link>
                </div>


            </div>
        </div>
    )
}