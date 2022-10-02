import React, { Component } from 'react'
import Footer from './components/Footer';
import Navbar from './components/Navbar'
import Testt from './components/Home'
import "./styles/style.css"
import Dialog from './components/Dialog';

import {
  BrowserRouter as Router,
  Routes as Switch,
  Route,
  Link
} from "react-router-dom";
import Cards from './components/Cards';
import Index from './components/Index';
import Decks from './components/Decks';
import CardView from './components/CardView';

export default class App extends Component {
  render() {
    let rr = ["ds", "dfd", "fdff", "efef"];
    return (

      <div className='container'>
       
        <Router>
        <Navbar/>
          <Switch>
            <Route exact path="/cards" element={<Cards type="name" />}>
            
            </Route>

            <Route exact path="/card/:id" element={<CardView />}>
            
            </Route>
            <Route exact path="/" element={<Index/>}>
            
            </Route>
            <Route exact path="/decks" element={<Decks/>}>
            
            </Route>
          
          </Switch>
        </Router>

        <Dialog />
      </div>
    )
  }
}
