const navbar = document.getElementById('navigationBar');
let navMode = false;


function navBarToggleFunction() {
    if(navMode) {
        navbar.classList.remove('navBarActive');
        setTimeout(() => {
            navbar.classList.add('displayNone');
            
        }, 300);
        navMode = false;
    } else {
        
        
        navbar.classList.remove('displayNone');
        setTimeout(() => {
            
            navbar.classList.add('navBarActive');
        }, 100);
        
        navMode = true;
    }
}

let fixedWidth = document.documentElement.clientWidth;
function responsiveNavIssues() {
    setInterval(() => {
        
        let widthIssue = document.documentElement.clientWidth;
        if((widthIssue <= 700) && (fixedWidth != widthIssue)){
            navbar.classList.add('displayNone');
            fixedWidth = widthIssue;
        } 
        if((widthIssue > 700)){
            navbar.classList.remove('displayNone');
            fixedWidth = widthIssue;
        } 
    }, 1000);
}

responsiveNavIssues();