import React, { Component } from 'react'
import { Link, Redirect, BrowserRouter as Router, Switch } from 'react-router-dom';
import Cards from './Cards';

export default class Navbar extends Component {


  constructor(props) {
    super(props)
    this.state = { input: "pikachu", search: false }
    // this.handleOnChange = this.handleOnChange.bind(this);
    // this.handleSearchClick = this.handleSearchClick.bind(this);
  }

  

  handleOnChange = (e) => {
    this.setState({ input: e.target.value })
  }

  render() {
    return (
      <>
     
        <div class="container my-3" style={{ marginTop: "70px" }}>


          <div class="row height d-flex justify-content-center align-items-center text-light">
            <div className='col-12 text-center justify-content-center'>
              <img class="logo" title="Reset Game" src="https://upload.wikimedia.org/wikipedia/commons/thumb/9/98/International_Pok%C3%A9mon_logo.svg/2000px-International_Pok%C3%A9mon_logo.svg.png" alt="Pokemon" />
            </div>
          
              
              <div className='col-3 my-1 text-center d-flex justify-content-center'>
                <Link to="/" style={{textDecoration : "none"}}> <button class="navbtn navbtn--stripe">Home</button></Link>

              </div>
              <div className='col-3 my-1 text-center d-flex justify-content-center'>
                <Link to="/decks" style={{textDecoration : "none"}}> <button class="navbtn navbtn--stripe">Decks</button></Link>
              </div>
              <div className='col-3 my-1 text-center d-flex justify-content-center'>
                <Link to="/cards" style={{textDecoration : "none"}}> <button class="navbtn navbtn--stripe">Cards </button></Link>
              </div>
              <div className='col-3 my-1 text-center d-flex justify-content-center'>
                <Link to="/aboutus" style={{textDecoration : "none"}}> <button class="navbtn navbtn--stripe">About </button></Link>
              </div>
              
            
          

          </div>
          

        </div>
      
       
      </>
    )
  }
}
