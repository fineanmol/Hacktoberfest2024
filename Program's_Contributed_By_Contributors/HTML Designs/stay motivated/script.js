fetch('https://type.fit/api/quotes')
    .then(data => data.json())
    .then(quoteData => {
            var ran = Math.floor(Math.random() * 10);
            document.getElementById('quoteElement').innerHTML=quoteData[ran].text+"<br>"+quoteData[ran].author;
        
    })