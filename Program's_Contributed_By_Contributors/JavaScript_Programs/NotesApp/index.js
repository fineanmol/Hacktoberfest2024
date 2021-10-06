//8caf07b921da49a3821686cc962c45a7

console.log("Running");
let json;

let newsSack = document.getElementById("newsSack");

const xhr= new XMLHttpRequest();
xhr.open('GET','https://newsapi.org/v2/top-headlines?country=us&apiKey=8caf07b921da49a3821686cc962c45a7',true);

xhr.onload = function(){
    if(this.status===200){
        json = JSON.parse(this.responseText);
        let articles = json.articles;
        let index=1;
        for(news in articles){
            console.log(articles[news].title);
            newsSack.innerHTML +=`
            <div class="card">
    <div class="card-header" id="heading${index}">
      <h2 class="mb-0">
        <button class="btn btn-link btn-block text-left" type="button" data-toggle="collapse" data-target="#collapse${index}" aria-expanded="true" aria-controls="collapse${index}">
        ${articles[news].title}
        </button>
      </h2>
    </div>

    <div id="collapse${index}" class="collapse show" aria-labelledby="heading${index}" data-parent="#accordionExample">
      <div class="card-body">
        ${articles[news].content} <a href="${articles[news].url}" target="_blank">Read more at... </a>
      </div>
    </div>
  </div>
            
        `;
            
        }
        
        

        
    }

}
xhr.send();




