//Check off specific toDos by clicking
$("ul").on("click", "li", function(){
    $(this).toggleClass("completed");
}); 
$("ul").on("click", "span", function(e){
    $(this).parent().fadeOut(500,function(){
        $(this).remove();
    });
    e.stopPropagation();
});
$("input[type='text']").keypress(function(e){
    if(e.which === 13){
        var todoText = $(this).val();
        $(this).val("");
        //create a new li and add it to existing ul
        $("ul").append("<li><span><i class='fa-solid fa-trash-can'></i></span>" + todoText + "</li>")
    }
});
$(".fa-plus").click(function(){
    $("input[type='text']").fadeToggle()
});
$(".fa-print").click(function(){
    var element = document.querySelector("#invoice");
    html2pdf(element, {
        margin: 40,
        filename: 'To-Do.pdf'
    });
});
  