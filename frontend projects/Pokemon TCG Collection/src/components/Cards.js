import React, { Component } from 'react'
import "../styles/card.css"
import Card from './Card'

import pokemon from 'pokemontcgsdk'
import Loader from './Loader'
import Dialog from './Dialog'
pokemon.configure({ apiKey: '211cfd2c-7f19-49de-a9f1-9945ad4a7215' })


export default class Cards extends Component {

  constructor() {
    super();
    this.state = { cards: [], loading: false, card: true, name : false,msg :"Search A Pokemon Card :D" }
    console.log(window.location.href)

  }



  handleSearchClick = () => {
    this.setState({search:true})
    this.setState({loading:true})
    this.setState({ input: this.state.input});
    console.log("PPPPPP - " + this.state.input);
    // console.log(this.state)
   // window.location.href = `/cards/name/${this.state.input}`

    //this.setState({ search: true })
this.getCards();
  }

  handleOnChange = (e) => {
   this.setState({ input: e.target.value })
  }

  getCards() {
   // let det = this.props.search;
 
    switch(this.props.type) {
      case "name" : {
    pokemon.card.all({ q: 'name:' + this.state.input})
    .then((cards) => {
    
      this.setState({ cards: cards })
      this.setState({ name: this.state.input})
      this.setState({ loading: false })
      if(!this.state.cards.length) this.setState({msg:"No Results Found D:"});
      console.log(cards);
    }).catch((e) => {
      console.log(e);
      this.setState({msg:"No Results Found D:"})
      console.log(this.state.msg);
      this.setState({ loading: false })
      this.setState({cards:false})
      
    })
  
  }
  break;

  }
}



  render() {


 

    return (

      <section class="cards row">
  <div class="col-md-12  d-flex justify-content-center py-2">

<div class="search w-50">
  <i class="fa fa-search"></i>

    <div>
    <input type="text" class="form-control" id="cardname" onChange={this.handleOnChange}  placeholder="Search A Pokemon By Name" />
   <button class="btn btn-primary" onClick={this.handleSearchClick}>Search</button>
    </div>

</div>

</div>

        {
         
          this.state.loading ? <Loader/> : ((this.state.cards && this.state.cards.length) ? this.state.cards.map((card) => {
            return (<div className='col-md-3 col-sm-12' >
              <Card color="white" key={card.images.large} card = {card.id} img={card.images.small} />
            </div>)
          }) : <h2 className='text-light text-center my-4'>{this.state.msg}</h2>)
        }
    
   

      </section>



    )
  }
}
