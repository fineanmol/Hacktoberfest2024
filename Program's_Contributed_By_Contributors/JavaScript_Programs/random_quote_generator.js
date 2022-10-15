//Random quote generator made in Code Pen using Axios Api//
//You have to add the following HTML component on Code Pen for it to work properly : <div id="app"></div>//

class QuoteBox extends React.Component {
  constructor(props) {
    super(props);
      this.state = {
         quote: '',
         author: ''
      }
   }

   componentDidMount() {
      this.getQuote()
   }

   getQuote() {
      let url = 'https://gist.githubusercontent.com/camperbot/5a022b72e96c4c9585c32bf6a75f62d9/raw/e3c6895ce42069f0ee7e991229064f167fe8ccdc/quotes.json'
 
      axios.get(url)
         .then(res => {
            let data = res.data.quotes;
            let quoteNum = Math.floor(Math.random() * data.length);
            let randomQuote = data[quoteNum];

            this.setState({
               quote: randomQuote['quote'],
               author: randomQuote['author']
            })
         })
   }

   getNewQuote = () => {
      this.getQuote()
   }

   render() {
     const {quote, author} = this.state
      return (
         <div id='wrapper'>
            <h1 className='title'>Quote of the Day</h1>
            <div id='quote-box'>
               <div id='text'><p>{quote}</p></div>
               <div id='author'><h5>{author}</h5></div>
               <div id='buttons'>
                  <button id='new-quote' onClick={this.getNewQuote}>Refresh Quote</button>
                 <p></p>
                 <a href="twitter.com/intent/tweet" id="tweet-quote" target="_blank"><i class="fa-brands fa-square-twitter"></i></a>
               </div>
              <p></p>
            </div>
         </div>
      )
   }
}

ReactDOM.render(<QuoteBox />, document.getElementById('app'))