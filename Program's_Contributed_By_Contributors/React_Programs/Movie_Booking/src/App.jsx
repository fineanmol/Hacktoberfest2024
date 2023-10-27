import Home from './components/Home'
import { BrowserRouter as Router, Routes, Route, Link } from 'react-router-dom'
import Summary from './components/Summary'
import Booking from './components/Booking'
import Error from './components/error'
export default function App() {

 

  return (
    <div>
      <Router>
        <Link to='/'  >
          <h1   className=" text-black bold text-2xl text-center bg-yellow-500 rounded-md mx-10 my-8 p-3 font-bold">
            Movie-Booking
          </h1>
        </Link>
        <Routes>
          <Route path='/' element={<Home />} />
          <Route path='/summary' element={<Summary />} />
          <Route path='/booking' element={<Booking />} />
          <Route path='*' element={<Error />} />
        </Routes>
        <p className='p-10 text-center text-gray-600'>Hint : Use the Big Logo to get back to home page </p>
      </Router>

    </div>
  )
}
