let result=document.getElementById("inputtext");

let answer=(number)=>{
     result.value=result.value+number;	
}
let Result=()=>{
	try{
		result.value=eval(result.value)
	}
	catch(err){
		alert("something wrong");
	}
} 	
function clr(){
	result.value="";
}
function del(){
	result.value=result.value.slice(0,-1);
}