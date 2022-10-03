import React, { Component } from 'react'
import CardView from './CardView';
import { Link } from 'react-router-dom';

export default class Card extends Component {
    constructor(props) {
        super(props);
        this.state = {preview:false}
        this.viewCard = this.viewCard.bind(this);

    }

    viewCard(e) {

        let c = this.props;
        this.setState({preview:true});
        console.log(this.state);
    }


    render() {
        console.log(this.props.amount)

        if(this.state.preview) return <CardView card={this.props.card}/>

        if(this.props.large) {
            
        return (
            <Link to={`/card/${this.props.card}`}>
            <div onClick={this.viewCard} value = {this.props} class={`card ${this.props.color ? this.props.color : "white"} animated ${this.props.large ? "cardLarge" : ""}`} data-bs-toggle="modal" href="#exampleModalToggle" role="button" style={{ backgroundImage: `url("${this.props.img}")`, height: this.props.large ? "100%" : "320px", width: this.props.large ? "60%" : "240px" }}>
            {  ((this.props.amount ? <h1 className='p-2 text-light' style={{background:"black"}}> {this.props.amount} tttttttt</h1> : 'ssss') )}
            </div>
            </Link>
        )
        }
        else {
           return (
            <Link to={`/card/${this.props.card}`}>
              <div value = {this.props} onClick={this.viewCard} class={`card ${this.props.color ? this.props.color : "white"} animated ${this.props.large ? "cardLarge" : ""}`} style={{ backgroundImage: `url("${this.props.img}")`, height: this.props.large ? "520px" : "320px", width: this.props.large ? "410px" : "240px" }}>
              {  ((this.props.amount ? <h2 className='p-2 text-light' style={{background:"black",position:"absolute",bottom:0,right:"2px",borderRadius:"50%"}}> x{this.props.amount} </h2> : 'ssss') )}
        

              </div>
              </Link>)
        }
    }
}
