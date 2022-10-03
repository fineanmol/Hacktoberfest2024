import React, { Component } from 'react'
import "../styles/card.css"
import Card from './Card'


import Icons from "../icons/icons"
import pokemon from 'pokemontcgsdk'
import Loader from './Loader'
import Dialog from './Dialog'

pokemon.configure({ apiKey: '211cfd2c-7f19-49de-a9f1-9945ad4a7215' })


export default class Decks extends Component {

  constructor() {
    super();
    this.d = [
      {
        "id": "d-bw1-1",
        "name": "Green Tornado",
        "types": [
          "Grass",
          "Psychic"
        ],
        "cards": [
          {
            "id": "bw1-5",
            "name": "Serperior",
            "rarity": "Rare Holo",
            "count": 1
          },
          {
            "id": "bw1-5",
            "name": "Serperior",
            "rarity": "Rare",
            "count": 1
          },
          {
            "id": "bw1-3",
            "name": "Servine",
            "rarity": "Uncommon",
            "count": 3
          },
          {
            "id": "bw1-1",
            "name": "Snivy",
            "rarity": "Common",
            "count": 4
          },
          {
            "id": "bw1-7",
            "name": "Pansage",
            "rarity": "Common",
            "count": 2
          },
          {
            "id": "bw1-9",
            "name": "Petilil",
            "rarity": "Common",
            "count": 2
          },
          {
            "id": "bw1-13",
            "name": "Deerling",
            "rarity": "Common",
            "count": 2
          },
          {
            "id": "bw1-14",
            "name": "Sawsbuck",
            "rarity": "Rare",
            "count": 1
          },
          {
            "id": "bw1-49",
            "name": "Musharna",
            "rarity": "Rare",
            "count": 1
          },
          {
            "id": "bw1-48",
            "name": "Munna",
            "rarity": "Uncommon",
            "count": 2
          },
          {
            "id": "bw1-54",
            "name": "Scolipede",
            "rarity": "Rare",
            "count": 1
          },
          {
            "id": "bw1-53",
            "name": "Whirlipede",
            "rarity": "Uncommon",
            "count": 2
          },
          {
            "id": "bw1-52",
            "name": "Venipede",
            "rarity": "Uncommon",
            "count": 2
          },
          {
            "id": "bw1-77",
            "name": "Patrat",
            "rarity": "Common",
            "count": 2
          },
          {
            "id": "bw1-87",
            "name": "Audino",
            "rarity": "Uncommon",
            "count": 2
          },
          {
            "id": "bw1-93",
            "name": "Energy Search",
            "rarity": "Common",
            "count": 2
          },
          {
            "id": "bw1-100",
            "name": "Potion",
            "rarity": "Common",
            "count": 2
          },
          {
            "id": "bw1-92",
            "name": "Energy Retrieval",
            "rarity": "Uncommon",
            "count": 2
          },
          {
            "id": "bw1-97",
            "name": "Poké Ball",
            "rarity": "Uncommon",
            "count": 2
          },
          {
            "id": "bw1-99",
            "name": "Pokémon Communication",
            "rarity": "Uncommon",
            "count": 2
          },
          {
            "id": "bw1-101",
            "name": "Professor Juniper",
            "rarity": "Uncommon",
            "count": 2
          },
          {
            "id": "bw1-102",
            "name": "Revive",
            "rarity": "Uncommon",
            "count": 2
          },
          {
            "id": "hgss1-115",
            "name": "Grass Energy",
            "rarity": "Common",
            "count": 10
          },
          {
            "id": "hgss1-119",
            "name": "Psychic Energy",
            "rarity": "Common",
            "count": 8
          }
        ]
      },
      {
        "id": "d-bw1-2",
        "name": "Red Frenzy",
        "types": [
          "Fire",
          "Fighting"
        ],
        "cards": [
          {
            "id": "bw1-19",
            "name": "Emboar",
            "rarity": "Rare Holo",
            "count": 1
          },
          {
            "id": "bw1-19",
            "name": "Emboar",
            "rarity": "Rare",
            "count": 1
          },
          {
            "id": "bw1-17",
            "name": "Pignite",
            "rarity": "Uncommon",
            "count": 3
          },
          {
            "id": "bw1-15",
            "name": "Tepig",
            "rarity": "Common",
            "count": 4
          },
          {
            "id": "bw1-22",
            "name": "Simisear",
            "rarity": "Uncommon",
            "count": 2
          },
          {
            "id": "bw1-21",
            "name": "Pansear",
            "rarity": "Common",
            "count": 3
          },
          {
            "id": "bw1-25",
            "name": "Darmanitan",
            "rarity": "Rare",
            "count": 1
          },
          {
            "id": "bw1-23",
            "name": "Darumaka",
            "rarity": "Common",
            "count": 4
          },
          {
            "id": "bw1-58",
            "name": "Timburr",
            "rarity": "Common",
            "count": 2
          },
          {
            "id": "bw1-83",
            "name": "Stoutland",
            "rarity": "Rare",
            "count": 1
          },
          {
            "id": "bw1-82",
            "name": "Herdier",
            "rarity": "Uncommon",
            "count": 2
          },
          {
            "id": "bw1-81",
            "name": "Lillipup",
            "rarity": "Common",
            "count": 3
          },
          {
            "id": "bw1-89",
            "name": "Cinccino",
            "rarity": "Rare",
            "count": 1
          },
          {
            "id": "bw1-88",
            "name": "Minccino",
            "rarity": "Common",
            "count": 2
          },
          {
            "id": "bw1-93",
            "name": "Energy Search",
            "rarity": "Common",
            "count": 2
          },
          {
            "id": "bw1-104",
            "name": "Switch",
            "rarity": "Common",
            "count": 2
          },
          {
            "id": "bw1-92",
            "name": "Energy Retrieval",
            "rarity": "Uncommon",
            "count": 2
          },
          {
            "id": "bw1-99",
            "name": "Pokémon Communication",
            "rarity": "Uncommon",
            "count": 2
          },
          {
            "id": "bw1-101",
            "name": "Professor Juniper",
            "rarity": "Uncommon",
            "count": 2
          },
          {
            "id": "bw1-102",
            "name": "Revive",
            "rarity": "Uncommon",
            "count": 2
          },
          {
            "id": "bw1-106",
            "name": "Fire Energy",
            "count": 12
          },
          {
            "id": "bw1-110",
            "name": "Fighting Energy",
            "count": 6
          }
        ]
      },
      {
        "id": "d-bw1-3",
        "name": "Blue Assault",
        "types": [
          "Water",
          "Lightning"
        ],
        "cards": [
          {
            "id": "bw1-31",
            "name": "Samurott",
            "rarity": "Rare Holo",
            "count": 1
          },
          {
            "id": "bw1-31",
            "name": "Samurott",
            "rarity": "Rare",
            "count": 1
          },
          {
            "id": "bw1-29",
            "name": "Dewott",
            "rarity": "Uncommon",
            "count": 3
          },
          {
            "id": "bw1-27",
            "name": "Oshawott",
            "rarity": "Common",
            "count": 4
          },
          {
            "id": "bw1-34",
            "name": "Simipour",
            "rarity": "Uncommon",
            "count": 2
          },
          {
            "id": "bw1-33",
            "name": "Panpour",
            "rarity": "Common",
            "count": 3
          },
          {
            "id": "bw1-37",
            "name": "Swanna",
            "rarity": "Rare",
            "count": 1
          },
          {
            "id": "bw1-36",
            "name": "Ducklett",
            "rarity": "Common",
            "count": 2
          },
          {
            "id": "bw1-35",
            "name": "Basculin",
            "rarity": "Uncommon",
            "count": 2
          },
          {
            "id": "bw1-46",
            "name": "Galvantula",
            "rarity": "Rare",
            "count": 1
          },
          {
            "id": "bw1-45",
            "name": "Joltik",
            "rarity": "Common",
            "count": 2
          },
          {
            "id": "bw1-40",
            "name": "Blitzle",
            "rarity": "Common",
            "count": 2
          },
          {
            "id": "bw1-86",
            "name": "Unfezant",
            "rarity": "Rare",
            "count": 1
          },
          {
            "id": "bw1-85",
            "name": "Tranquill",
            "rarity": "Uncommon",
            "count": 2
          },
          {
            "id": "bw1-84",
            "name": "Pidove",
            "rarity": "Common",
            "count": 3
          },
          {
            "id": "bw1-93",
            "name": "Energy Search",
            "rarity": "Common",
            "count": 2
          },
          {
            "id": "bw1-100",
            "name": "Potion",
            "rarity": "Common",
            "count": 2
          },
          {
            "id": "bw1-92",
            "name": "Energy Retrieval",
            "rarity": "Uncommon",
            "count": 2
          },
          {
            "id": "bw1-97",
            "name": "Poké Ball",
            "rarity": "Uncommon",
            "count": 2
          },
          {
            "id": "bw1-101",
            "name": "Professor Juniper",
            "rarity": "Uncommon",
            "count": 2
          },
          {
            "id": "bw1-102",
            "name": "Revive",
            "rarity": "Uncommon",
            "count": 2
          },
          {
            "id": "bw1-107",
            "name": "Water Energy",
            "rarity": "Common",
            "count": 12
          },
          {
            "id": "bw1-108",
            "name": "Lightning Energy",
            "rarity": "Common",
            "count": 6
          }
        ]
      }
    ]
    this.state = { cards: false, loading: false, name: false, card: true, decks: false, msg : "Ready-Made Battle Decks!",search : "xy" }

  }

  decks = [
    'base', 'bw', 'col',
    'deckbase', 'deckbw', 'deckcol',
    'deckdp', 'deckecard', 'deckex',
    'deckgym', 'deckhgss', 'deckneo',
    'deckpl', 'decksm', 'deckswsh',
    'deckxy', 'dp', 'ecard',
    'ex', 'gym', 'hgss',
    'neo', 'pl', 'sm',
    'swsh', 'xy'
  ]

  colors = {
    normal: '#A8A77A',
    fire: '#EE8130',
    water: '#6390F0',
    electric: '#F7D02C',
    grass: '#7AC74C',
    ice: '#96D9D6',
    fighting: '#C22E28',
    poison: '#A33EA1',
    ground: '#E2BF65',
    flying: '#A98FF3',
    psychic: '#F95587',
    bug: '#A6B91A',
    rock: '#B6A136',
    ghost: '#735797',
    dragon: '#6F35FC',
    dark: '#705746',
    steel: '#B7B7CE',
    fairy: '#D685AD',
  };


  getDeck = () => {

    fetch('https://pokecardss.herokuapp.com/deck', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json'
      },
      body: JSON.stringify({ deck: this.state.search })
    }).then((response) => {
      response.json().then((json) => {

        this.setState({ decks: json.deck });
        console.log(this.state.decks)

      })


    })

  }


  selectDeck = (e) => {
this.setState({search:e.target.value});
console.log(this.state.search)
this.getDeck();
  }


  showDeck = (e) => {
    let id = e.target.id;
    let deck = false;
    this.state.decks.map((d) => {
      if (d.id === id) deck = d;
    })
    console.log(e.target.id)

    if (deck) {
      console.log(deck.id)
      let a = [];
      deck.cards.map((cardd) => {
        pokemon.card.find(cardd.id)
          .then(card => {

            card.amm = cardd.count
          console.log(card);
          console.log(cardd)
            a.push(card)
            //    console.log(this.state.cards)
            this.setState({ cards: a });
            this.setState({ name: deck.name })
            this.setState({msg : "Deck : " + deck.name})
          })

      })


    }

  }



  isLoading() {
    if (this.state.loading) return (<Loader />)
  }

  random(limit, prng) {
    if (!limit) limit = 2;
    //if (prng) return prng.next(limit);
    return Math.floor(Math.random() * limit);
  }

  shuffle(array, prng) {
    const shuffled = array.slice();

    // Fisher-Yates shuffle algorithm
    let currentIndex = shuffled.length;
    let randomIndex = 0;
    let temporaryValue;

    // While there remain elements to shuffle...
    while (currentIndex !== 0) {
      // Pick a remaining element...
      randomIndex = this.random(currentIndex, prng);
      currentIndex -= 1;

      // And swap it with the current element.
      temporaryValue = shuffled[currentIndex];
      shuffled[currentIndex] = shuffled[randomIndex];
      shuffled[randomIndex] = temporaryValue;
    }
    return shuffled;
  }

  sampleMany(array, amount, prng) {
    const len = array.length;
    if (!len) throw new Error("Tools.sampleMany() does not accept empty arrays");
    if (len === 1) return array.slice();
    if (typeof amount === 'string') amount = parseInt(amount);
    if (!amount || isNaN(amount)) throw new Error("Invalid amount in Tools.sampleMany()");
    if (amount > len) amount = len;
    return this.shuffle(array, prng).splice(0, amount);
  }



  getCards() {
    // let det = this.props.search;
    this.setState({ cards: this.d[0].cards })
    this.setState({ loading: false })
    let cs = [];

    this.d[0].cards.forEach((a) => {
      pokemon.card.find(a.id)
        .then(card => {
          cs.push(card)
          this.setState({ cards: cs })
        })
    })
    console.log(this.state.cards);
    this.setState({ cards: cs })

  }


  render() {



    if (this.state.loading) {
      return <Loader />
    }

    return (

      <section class="cards row">


<div className='col-12 text-light my-2 text-center'>

  <h2 className='m-auto'> {this.state.msg}</h2>
  <select  onChange={this.selectDeck} class="form-select center mx-4" style={{width:"200px"}}aria-label="Default select example" >
  <option  value="bw">Black & White</option>
  <option value="xy">XY</option>
  <option value="base">Classic</option>
  <option value="swsh">Sword & Shield</option>
  <option value="dp">Diamond & Pearl</option>
</select>
</div>
        {



          this.state.loading ? <Loader /> : ((this.state.cards && this.state.cards.length) ? this.state.cards.map((card) => {
          console.log(card.amm)
            return (<div className='col-md-3 col-sm-12' >
              <Card color="white" amount={card.amm} key={card.images.large} card={card.id} img={card.images.small} />
            </div>)
          }) : (this.state.decks ? this.state.decks.map((deck) => {
            let cc = deck.cards.slice(3, 15);
            return (
              <div onClick={this.showDeck} id={deck.id} class={`p-4 card ${this.props.color ? this.props.color : "white"} animated ${this.props.large ? "cardLarge" : ""}`} style={{ height: this.props.large ? "100%" : "320px", width: this.props.large ? "60%" : "240px" }}>

                <h3 className='text-light'> {deck.name}</h3>
                <p className='text-light my-2 p-0'>
                  <small>
                    Includes some of -
                    <ul style={{ lineHeight: "20px" }}>
                      <li>{cc[0].name} ({cc[0].count})</li>
                      <li>{cc[1].name} ({cc[1].count})</li>
                      <li>{cc[9].name} ({cc[9].count})</li>
                      <li>{cc[7].name} ({cc[7].count})</li>
                      <li> And more!</li>
                    </ul>
                  </small>
                </p>
                <div className='row my-2 mx-2' >
                  {
                    deck.types.map((type) => {
                      return (<div className='btn text-light bold p-auto col-6' >
                        <div class={`icon ${type.toLowerCase()}`}>
                          <img src={Icons[type.toLowerCase()]} />
                        </div>
                      </div>)
                    })

                  }

                </div>
              </div>
            )
          }) : <Loader />))}



      </section>



    )
  }
}
