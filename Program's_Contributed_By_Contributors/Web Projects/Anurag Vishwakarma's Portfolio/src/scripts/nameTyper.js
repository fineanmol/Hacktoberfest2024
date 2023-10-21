const typingName = document.getElementById('typingName');
const speed = 120;
const typingData = ["Anurag Vishwakarma.", "Software Engineer."];
let currentData = 0;
typingg = true;
let n = typingData[currentData].length - 1;



let textTyping = (i) => {

    if (typingg) {

        typingName.innerHTML = typingName.innerHTML + typingData[currentData][i];

        if (i < typingData[currentData].length - 1) {

            setTimeout(() => {
                i++;
                textTyping(i);
            }, speed);
        } else {
            typingg = false;
            
            setTimeout(() => {
                
                textTyping(i);
            }, 800);
        }

    } else {
        
        if(n == -1) {
            i = 0;
            typingg = true;
            currentData = ((currentData + 1)% typingData.length)
            n = typingData[currentData].length - 1;
            setTimeout(() => {
                
                textTyping(i);
            }, 500);
            
        } else {
            typingName.innerHTML = typingData[currentData].slice(0, n)
            setTimeout(() => {
                n--;
                textTyping(i);
            }, 100);

        }
    }
}

setTimeout(() => {

    textTyping(currentData);
}, 200);