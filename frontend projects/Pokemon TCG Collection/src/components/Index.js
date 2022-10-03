import React, { Component } from 'react'
import Card from './Card'
import Cards from './Cards'
export default class Index extends Component {

    constructor() {
        super()
        this.state = { input: "", search: false }
        this.handleOnChange = this.handleOnChange.bind(this);
        this.handleSearchClick = this.handleSearchClick.bind(this);
    }

    handleSearchClick() {
       // this.setState({ search: true })
    }

    handleOnChange(e) {
        this.setState({ input: e.target.value })
    }



    render() {

      //  if (this.state.search) return <Cards type="name" query={this.state.input} />


        return (
            <div>

                <div className="container my-4 mx-4" >
                    <div className='row'>
                        <div className='col-md-6 my-auto ' style={{ height: "512px" }}>
                            <Card img="https://images.pokemontcg.io/xy3/107.png" large={true} />
                        </div>
                        <div className='col-md-6 text-light my-auto'>
                            <h1>
                                Welcome to Pokemon TCG Lite!
                            </h1>
                            <p>

                                Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis vel pulvinar ante. Etiam dapibus enim sit amet pharetra venenatis. Vivamus non leo ultrices, fringilla elit vitae, venenatis mi. Nullam pharetra lacus non enim efficitur vestibulum. Sed eget lacus consectetur, gravida ipsum nec, hendrerit magna. In hac habitasse platea dictumst. Integer libero tellus, rutrum sit amet lorem eu, efficitur mattis nunc. Sed in molestie mi. Cras ornare, lectus vel elementum placerat, justo tortor pulvinar nisl, et gravida purus nunc cursus dolor.


                            </p>
                        </div>

                        <div className='col-12 my-4 d-flex justify-content-center' >

                        </div>

                    </div>
                </div>

            </div>
        )
    }
}
