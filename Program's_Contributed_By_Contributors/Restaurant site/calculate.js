function createBill(){
    var index=0;
    var items = ["null", "null", "null","null"];
    var quantities = ["null", "null", "null","null"];
    var prices = ["null", "null", "null","null"];
                            
                            
                            
    var e1 = document.getElementById("item1");
    var itemselected1 = e1.options[e1.selectedIndex].value;
    if(itemselected1!="1"){
    items[index]=itemselected1;
    quantities[index] = document.getElementById("q1").value;
    prices[index] = document.getElementById("p1").value;
    index++;
    }
                
    
    var e2 = document.getElementById("item2");
    var itemselected2 = e2.options[e2.selectedIndex].value;
    if(itemselected2!="1"){
    items[index]=itemselected2;
    quantities[index] = document.getElementById("q2").value;
    prices[index] = document.getElementById("p2").value;
    index++;
    }
    
    var e3 = document.getElementById("item3");
    var itemselected3 = e3.options[e3.selectedIndex].value;
    if(itemselected3!="1"){
    items[index]=itemselected3;
    quantities[index] = document.getElementById("q3").value;
    prices[index] = document.getElementById("p3").value;
    index++;
    }
    
    
    var fTot=0;
    strt(1);
    for(var i=0;i<index;i++){
    document.write("<tr>");
    createtbl(items[i]);
    createtbl(quantities[i]);
    createtbl(prices[i]);
    var tot=parseInt(quantities[i])*parseInt(prices[i]);
    document.write("<td>"+tot+"</td>");
    fTot+=tot;
    document.write("</tr>");
    }
    document.write("<tr><td colspan=\"3\"><strong>TOTAL</strong></td><td>"+fTot+"</td><tr>");
    strt(2);	
    }
    function createtbl(x){		
    document.write("<td>"+x+"</td>");
    }
    
    function strt(n){
    if(n==1){
    document.writeln("<h1 style=\"text-align:center;\">The Bill</h1>");
    document.writeln("<table width=\"90%\" border=\"1\">");
    document.writeln("<tr><th>ITEMS</th><th>QUANTITY</th><th>PRICE</th><th></th></tr>");
    }
        else
        document.write("</table>");
    }
    
    function createTot(x,y){
    var tot=parseInt(x)*parseInt(y);
    document.write("<td>"+tot+"</td>");
    }