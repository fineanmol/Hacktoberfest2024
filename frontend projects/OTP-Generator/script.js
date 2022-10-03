var generateBtn = document.getElementById("generate-btn");
var outputOtp = document.querySelector("#output-otp");

window.onload = () => {
    document.getElementById("n").value = 4;
    outputOtp.value = "Generated OTP: " + randomOTP(4, "0123456789");
}


const randomOTP = (num, nums) => {
    let res = "";
    var arr = new Array(nums.length).fill(0);
    for(let i=0;i<num;i++){
        let index = Math.floor(Math.random() * nums.length);
        if(i == 0 && index == 0){
            arr[0] = 1;
        }
        if(arr[index] != 1){
            res += nums[index];
            arr[index] = 1;
        }
        else{
            i--;
        }
    }
    console.log(arr);
    return res;
}

generateBtn.addEventListener("click", () => {
    
    var n = document.getElementById("n").value;

    var num = parseInt(n);
    var nums = "0123456789";

    if(n <= 3){
        alert("Number should be Greater than 3");
    }
    else if(n >= 11){
        alert("Number should be Less than 11");
    }
    else{
        var ans = randomOTP(num, nums);
        outputOtp.value = "Generated OTP: " + ans;
    }
});