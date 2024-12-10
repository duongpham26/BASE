




const canvas = document.getElementById("canvas");

let context = canvas.getContext("2d");

canvas.width = window.innerWidth;
canvas.height = window.innerHeight;
canvas.style.background = "white";

context.beginPath();
context.strokeStyle = "red";
let w = 500, h = 200;

context.moveTo(w,h);


let vuong = setInterval(() => {
   if(w < 800 && h == 200) {
      w+=1
   } else if(w == 800 && h < 400) {
      h++;
   } else if(w > 500 && h == 400) {
      w--;
   } else if(w == 500 && h > 200) {
      h--
      if(h == 200) clearInterval(vuong);
   }    
   context.lineTo(w, h);
   context.stroke();
}, 1)


setTimeout(()=>{
   context.fillStyle = "red";
   context.fill();   
   context.closePath();
}, 5200)

setTimeout(()=>{
   context.beginPath();

   let R = 60;
   w = 650 + R * Math.cos(3 * 2 * Math.PI  / 5 + Math.PI / 2 + Math.PI)
   h = 300 + R * Math.sin(3 * 2 * Math.PI  / 5 + Math.PI / 2 + Math.PI)
   context.strokeStyle = "yellow";
   context.moveTo(w,h);
   let angles = 0
   
   let array = [3, 0, 2, 4, 1, 3]
   let vuong2 = setInterval(() => {
      let i = 0;
      angles += array[i] * 2 * Math.PI  / 5;
      w = 650 + R * Math.cos(angles + Math.PI / 2 + Math.PI)
      h = 300 + R * Math.sin(angles + Math.PI / 2 + Math.PI)
      context.lineTo(w, h);
      context.stroke();
      i++;
      if(i > 5) clearInterval(vuong2);
   }, 500)
}, 5900)

setTimeout(()=>{
   // context.closePath();
   context.fillStyle = "yellow";
   context.fill(); 
     
}, 9400)



