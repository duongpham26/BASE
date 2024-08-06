
const $ = document.querySelector.bind(document);
const $$ = document.querySelectorAll.bind(document);

const player = $(".player");
const cdElement = $(".cd");
const heading = $("header h2");
const cdThumb = $(".cd-thumb");
const audio = $("#audio");
const playBtn = $(".btn-toggle-play");
const progress = $(".progress");
const btnPrev = $(".btn-prev");
const btnNext = $(".btn-next");
const btnRandom = $(".btn-random");
const btnRepeat= $(".btn-repeat");
const playlist = $(".playlist");

const PLAYER_STORAGE_KEY = 'DUONGPHAM26_PLAYER'

const app = {
   currentIndex: 0,
   isPlaying: false,
   isRandom: false,
   isRepeat: false,
   config: JSON.parse(localStorage.getItem(PLAYER_STORAGE_KEY)) ||  {},
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
         name: "Lối nhỏ",
         singer: "Đen, Phương Anh Đào",
         path: "./assets/music/song4.mp3",
         image: "./assets/images/image4.jpg", 
      },
      {
         name: "Lối nhỏ",
         singer: "Đen, Phương Anh Đào",
         path: "./assets/music/song4.mp3",
         image: "./assets/images/image4.jpg", 
      },
      {
         name: "Lối nhỏ",
         singer: "Đen, Phương Anh Đào",
         path: "./assets/music/song4.mp3",
         image: "./assets/images/image4.jpg", 
      },
      {
         name: "Lối nhỏ",
         singer: "Đen, Phương Anh Đào",
         path: "./assets/music/song4.mp3",
         image: "./assets/images/image4.jpg", 
      },
      {
         name: "Lối nhỏ",
         singer: "Đen, Phương Anh Đào",
         path: "./assets/music/song4.mp3",
         image: "./assets/images/image4.jpg", 
      },
   ],

   setConfig: function(key, value) {
      this.config[key] = value;
      localStorage.setItem(PLAYER_STORAGE_KEY, JSON.stringify(this.config));
   },

   render: function() {
      const htmls = this.songs.map((song, index) => {
         return `
            <div class="song ${index == this.currentIndex?"active":""}" data-index="${index}">
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
      playlist.innerHTML = htmls.join("\n");
   },

   defineProperties: function() {
      Object.defineProperty(this, "currentSong", {
         get: function() {
            return this.songs[this.currentIndex]
         }
      })
   },

   handleEvent: function() {
      const _this = this;
      const cdWidth = cdElement.offsetWidth;

      //xử lí CD quay / dừng
      const cdThumbAnimate = cdThumb.animate([
         { transform: "rotate(360deg)"}
      ], {
         duration: 10000, // 10s
         iterations: Infinity
      })
      cdThumbAnimate.pause();

      // xử lí cd image 
      document.onscroll = function() {
         let scrollTop = document.documentElement.scrollTop || window.scrollY;
         let newCdWidth = cdWidth - scrollTop;
         if(newCdWidth < 0) newCdWidth = 0;
         cdElement.style.width = newCdWidth + "px";
         cdElement.style.opacity = newCdWidth / cdWidth
      }

      //xử lí click play
      playBtn.onclick = function() {
         if(_this.isPlaying) audio.pause();
         else audio.play();  
      }

      // khi được thực sự play
      audio.onplay = function() {
         _this.isPlaying = true;
         player.classList.add("playing");
         cdThumbAnimate.play();
      } 

      // khi thự sự pause
      audio.onpause = function() {
         player.classList.remove("playing");
         _this.isPlaying = false;
         cdThumbAnimate.pause();

      }

      // tiến độ bài hát
      audio.ontimeupdate = function() {
         if(audio.duration) {
            const progressPercent = Math.floor(audio.currentTime / audio.duration * 100);
            progress.value = progressPercent;
         }
      } 
     
      // xử lí khi tua bài
      progress.onchange = function(e) {
         const seekTime = e.target.value / 100 * audio.duration;
         audio.currentTime = seekTime;
      }

      // xử lí click next song
      btnPrev.onclick = function() {
         if(_this.isRandom) {
            _this.playRandomSong();
         } else {
            _this.prevSong();
         }
         audio.play();
         _this.render();
         _this.scrollToActiveSong();
      }

      // xử lí click next song
      btnNext.onclick = function() {
         if(_this.isRandom) {
            _this.playRandomSong();
         } else {
            _this.nextSong();
         }
         audio.play();
         _this.render();
         _this.scrollToActiveSong();
      }

      // khi bat tat random
      btnRandom.onclick = function(e) {
         _this.isRandom = !_this.isRandom;
         _this.setConfig("isRandom", _this.isRandom);
         btnRandom.classList.toggle("active", _this.isRandom);
         // if(_this.isRandom) {
         //    btnRandom.classList.remove("active");
         //    _this.isRandom = false;
         // }
         // else {
         //    btnRandom.classList.add("active")
         //    _this.isRandom = true;
         // }
      }

      // xử lí lặp lại một song
      btnRepeat.onclick = function(e) {
         _this.isRepeat = !_this.isRepeat;
         _this.setConfig("isRepeat", _this.isRepeat);
         btnRepeat.classList.toggle("active", _this.isRepeat);
         // if(_this.isRandom) {
         //    btnRandom.classList.remove("active");
         //    _this.isRandom = false;
         // }
         // else {
         //    btnRandom.classList.add("active")
         //    _this.isRandom = true;
         // }
      }

      // xử lí khi audio ended
      audio.onended = function() {
         if(_this.isRepeat) {
            audio.play();
         } else {
            btnNext.click();
         }
      }

      // lắng nghe hành vi click vao playlist 
      playlist.onclick = function(e) {
         const songNode = e.target.closest(".song:not(.active)");
         if( songNode || e.target.closest(".option")) {
            if(songNode) {
               _this.currentIndex = Number(songNode.dataset.index);
               _this.loadCurrentSong();
               _this.render();
               audio.play();
            }
            if(e.target.closest(".option")) {

            }
         }
      }
   },

   loadCurrentSong: function() { 
      heading.textContent = this.currentSong.name;
      cdThumb.style.backgroundImage = `url('${this.currentSong.image}')`;
      audio.src = this.currentSong.path;
      console.log(heading, cdThumb, audio);
   },
   
   loadConfig: function() {
      this.isRandom = this.config.isRandom;
      this.isRepeat  = this.config.isRepeat;

      // Object.assign(this, this.config) // không nên 
   },

   prevSong: function() {
      this.currentIndex--;
      if(this.currentIndex < 0 ) this.currentIndex = this.songs.length - 1;
      this.loadCurrentSong();
   },

   nextSong: function() {
      this.currentIndex++;
      if(this.currentIndex >= this.songs.length) this.currentIndex = 0
      this.loadCurrentSong();
   },

   playRandomSong: function() {
      let newIndex;
      do {
         newIndex = Math.floor(Math.random() * this.songs.length);
      } while(this.currentIndex == newIndex);
      this.currentIndex = newIndex;
      this.loadCurrentSong();      
   },

   scrollToActiveSong: function() {
      setTimeout(() => {
         $(".song.active").scrollIntoView({
            behavior: "smooth",
            block: "center"
         });
      }, 200)
   },

   start: function() {
      this.loadConfig();

      // định nghĩa các thuộc tích cho object
      this.defineProperties();

      // xử lí sự kiện
      this.handleEvent();

      // tải bài đầu tiên vào UI
      this.loadCurrentSong();

      // render 
      this.render();

      btnRandom.classList.toggle("active", this.isRandom);
      btnRepeat.classList.toggle("active", this.isRepeat);
   }
}

app.start();