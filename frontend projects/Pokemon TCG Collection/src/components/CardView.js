import React, { Component } from 'react'
import Card from "./Card"
import pokemon from 'pokemontcgsdk'

export default class CardView extends Component {

    constructor(props) {
        super(props)
       
        this.state = {card:false}
    }


    getCard = () => {

        pokemon.card.find(window.location.href.split('/')[4] ? window.location.href.split('/')[4]  : "lucario")
            .then(card => {
                console.log(card)
                this.setState({ card: card })

            })

     
    }

    componentDidMount() {
        this.getCard();
    }

    render() {
       if(!this.state.card) return <></>;
        return (
            <div>

                <div className="container my-4 mx-4" >
                    <div className='row'>
                        <div className='col-md-6 my-auto ' style={{ height: "512px" }}>
                            <Card img={this.state.card.images.large} large={true} />
                        </div>
                        <div className='col-md-6 text-light my-auto'>
                            {
                                Object.keys(this.state.card).map((key) => {
                                   if(typeof this.state.card[key] === typeof "") return (<div> <b> {key.toUpperCase()} : </b> {  this.state.card[key]} </div>);
                                    
                                })
                        
                            }
                        </div>

                        <div className='col-12 my-4 d-flex justify-content-center' >

                        </div>

                    </div>
                </div>

            </div>
        )
    }
}
