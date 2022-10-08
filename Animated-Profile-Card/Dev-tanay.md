# HTML CODE: 


<!DOCTYPE html>
<!-- Created By CodingLab - www.codinglabweb.com -->
<html lang="en" dir="ltr">
  <head>
    <meta charset="UTF-8">
  <!------<title> Animated Profie Card | CodingLab </title>-------->
    <link rel="stylesheet" href="style.css">
   <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.2/css/all.min.css"/>
   </head
<body>
<div class="main-box">
<div class="content">
  <input type="checkbox" id="check">
  <label class="box" for="check">
  <div class="share">SHARE</div>
  <div class="cancel">CANCEL</div>
  </label>
  <div class="image-box">
    <!---<img src="james.jpeg" alt="">--->
    <div class="about">
    <div class="details">
      <div class="name">James Bernal</div>
      <div class="job">Devoloper | Youtuber</div>
      <div class="icon">
        <a href="#"><i class="fab fa-facebook-f"></i></a>
        <a href="#"><i class="fab fa-twitter"></i></a>
        <a href="#"><i class="fab fa-instagram"></i></a>
        <a href="#"><i class="fab fa-youtube"></i></a>
      </div>
    </div>
    </div>
  </div>
</div>
</div>
</body>
</html>


# CSS CODE: 


@import url('https://fonts.googleapis.com/css2?family=Poppins:wght@200;300;400;500;600;700&display=swap');
*{
  margin: 0;
  padding: 0;
  box-sizing: border-box;
  font-family: 'Poppins',sans-serif;
}
body{
  background: #3498db;
}
.main-box{
  position: absolute;
  left: 50%;
  bottom: 8%;
  transform: translateX(-50%);
  width: 400px;
  height: 550px;
  text-align: center;
}
.main-box .content{
  position: relative;
  height: 100%;
  width: 100%;
}
.content .box{
  position: absolute;
  height: 50px;
  width: 100%;
  left: 0;
  bottom: 0;
  border-radius: 25px;
  cursor: pointer;
}
.share, .cancel{
  position: absolute;
  height: 100%;
  width: 100%;
  left: 0;
  top: 0;
  font-size: 20px;
  font-weight: 600;
  color: #2980b9;
  line-height: 50px;
  background: #fff;
  letter-spacing: 1px;
  border-radius: 25px;
  opacity: 0;
  transition: all 0.3s ease;
}
.content .box .share{
  opacity: 1;
}
#check:checked ~ .box .share{
  opacity: 0;
}
#check:checked ~ .box .cancel{
  opacity: 1;
}
.content .image-box{
  position: absolute;
  height: 450px;
  width: 100%;
  bottom: 130px;
  left: 50%;
  transform: translateX(-50%);
  background: #fff;
  padding: 10px;
  border-radius: 25px;
  transition: all 0.4s ease;
}
#check:checked ~ .image-box{
  bottom: 70px;
}
#check{
  display: none;
}
.image-box::before{
  position: absolute;
  content: '';
  bottom: -12px;
  left: 50%;
  transform: translateX(-50%) rotate(45deg);
  height: 30px;
  width: 30px;
  background: #fff;
  z-index: -1;
}
.image-box img{
  height: 100%;
  width: 100%;
  object-fit: cover;
  border-radius: 26px;
}
.image-box .about{
  position: absolute;
  background: rgba(0, 0, 0, 0.5);
  height: 100%;
  width: 100%;
  left: 0;
  top: 0;
  border-radius: 25px;
  padding: 20px;
  text-align: center;
  opacity: 0;
  transition: all 0.3s ease;
}
#check:checked ~ .image-box .about{
  opacity: 1;
}
.about .details{
  position: absolute;
  width: 100%;
  left: 0;
  bottom: 35px;
}
.details .name, .job{
  font-size: 18px;
  font-weight: 500;
  color: #fff;
}
 .details .icon i{
   font-size: 20px;
   color: #fff;
   height: 45px;
   width: 45px;
   line-height: 43px;
   border-radius: 50%;
   border: 2px solid #fff;
   margin: 14px 5px;
   transition: all 0.3s ease;
 }
.details .icon i:hover{
  transform: scale(0.95);
}
