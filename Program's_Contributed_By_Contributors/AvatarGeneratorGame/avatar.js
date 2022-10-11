
$(document).ready(function(){
    $('.clickme').click(function(){
     const name = $('#nameid').val();
     alert(name);
     $('.imgchange').attr('src'
     ,`https://joeschmoe.io/api/v1/${name}`);
     const b = $('.imgchange');
     console.log(b);
  
    });
   });

   $(".light").on("click", function () {
     $("section").css("background","linear-gradient(to bottom, #33ccff 0%, #ff66ff 100%)");
     $(".centerDiv").css("background","linear-gradient(to left top, #ec0d97 0%,#1c2bf3  90%)")
     $(".dark").css("visibility","visible");
     $(".light").css("visibility","hidden");
   });

   $(".dark").on("click", function () {
      $("section").css("background","rgb(6 10 12 / 98%)");
      $(".centerDiv").css("background","rgb(62 6 6 / 45%)")
      $(".dark").css("visibility","hidden");
      $(".light").css("visibility","visible");
    });