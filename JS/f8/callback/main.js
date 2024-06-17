// 1. là function.
// 2. Được truyền argument.
// 3. Gọi lại trong fuction chưa argument.

function print(cb) {
   console.log("size of cb: ", typeof cb);
   if(typeof cb === "function")
      cb("Thích học lập trình"); 
};

function callback(value) {
   console.log("Value: ", value);
};

print(callback);

//====================================================
const courses = [
   "JavaScript",
   "Java",
   "C#",
];

const htmls = courses.map((course, index) => {
   console.log(index, course);
   return `<h2>${course}</h2>`;
});

console.log(htmls.join(' '));

Array.prototype.map2 = function(cb) {
   let lenghtArray = this.length;
   let output = [];
   for(var i = 0; i < lenghtArray; i++) {
      let results = cb(this[i], i);
      output.push(results);
   }
   return output;
}

console.log(courses.map2(function(course, index) {
   return `<h2>${course}</h2>`
}).join(' '))