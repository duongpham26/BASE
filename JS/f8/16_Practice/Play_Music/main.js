
const $ = document.querySelector.bind(document);
const $$ = document.querySelectorAll.bind(document);

const app = {
   songs: [
      {
         name: "Lối nhỏ",
         singer: "Đen, Phương Anh Đào",
         path: "./assets/music/song1.mp3",
         image: "./assets/images/image1.jpg", 
      },
      {
         name: "Comethru",
         singer: "Jeremy Zacker",
         path: "./assets/music/song2.mp3",
         image: "./assets/images/image2.jpg", 
      },
      {
         name: "Night Changes",
         singer: "One Direction",
         path: "./assets/music/song3.mp3",
         image: "./assets/images/image3.jpg",  
      },
      {
         name: "Night Changes",
         singer: "One Direction",
         path: "./assets/music/song3.mp3",
         image: "./assets/images/image3.jpg",  
      },
      {
         name: "Night Changes",
         singer: "One Direction",
         path: "./assets/music/song3.mp3",
         image: "./assets/images/image3.jpg",  
      },
      {
         name: "Night Changes",
         singer: "One Direction",
         path: "./assets/music/song3.mp3",
         image: "./assets/images/image3.jpg",  
      },
      {
         name: "Night Changes",
         singer: "One Direction",
         path: "./assets/music/song3.mp3",
         image: "./assets/images/image3.jpg",  
      }
   ],

   render: function() {
      const htmls = this.songs.map((song, index) => {
         return `
            <div class="song active" data-index="${index}">
               <div class="thumb"
                     style="background-image: url('${song.image}')">
               </div>
               <div class="body">
                     <h3 class="title">${song.name}</h3>
                     <p class="author">${song.singer}</p>
               </div>
               <div class="option">
                     <i class="fas fa-ellipsis-h"></i>
               </div>
            </div>
         `
      })
      $(".playlist").innerHTML = htmls.join("\n");
   },

   handleEvent: function() {
      const cdElement = $(".cd");
      const cdWidth = cdElement.offsetWidth;
      document.onscroll = function() {
         let scrollTop = document.documentElement.scrollTop || window.scrollY;
         let newCdWidth = cdWidth - scrollTop;
         if(newCdWidth < 0) newCdWidth = 0;
         cdElement.style.width = newCdWidth + "px";
         cdElement.style.opacity = newCdWidth / cdWidth
         
      }
   },



   start: function() {
      this.render();
      this.handleEvent();
   }
}

app.start();