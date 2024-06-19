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
   };
   return output;
};

console.log(courses.map2(function(course, index) {
   return `<h2>${course}</h2>`;
}).join(' '));

//============================
//ForEach 
courses.forEach((a ,b, c) => {
   // console.log(c);
});

Array.prototype.forEach2 = function(cb) {
   for(var i in this) {
      if(this.hasOwnProperty(i))
         cb(this[i], i, this);   
   };
};

courses.forEach2((a ,b, c) => {
   // console.log(a, b, c);
});

//==================================
// filter 
const ages = [32, 33, 16, 40];
let age18 = ages.filter(function checkAdult(age, index, arr) {
   return age >= 18;
});

Array.prototype.filter2 = function(cb) {
   let output = [];
   for(let i in this) {
      if(this.hasOwnProperty(i)) {
         let check = cb(this[i], i, this);
         if(check) output.push(this[i]);
      };
   };
   return output;
};
let age182 = ages.filter2(function checkAdult(age, index, arr) {
   return age >= 18;
});
// console.log(age182);

//===============================
// reduce
const numbers = [15.5, 2.3, 1.1, 4.7];

let red = numbers.reduce(getSum, 0);

function getSum(total, num) {
  return total + Math.round(num);
}

// console.log(red);

Array.prototype.reduce2 = function(cb, initialValue) {
   let lenghtArray = this.length;
   let totalValue;
   let i;
   if(initialValue !== undefined) {
      totalValue = initialValue;
      i = 0;
   } else {
      totalValue = this[0];
      i = 1;
   };
   for(i; i < lenghtArray; i++) {
      totalValue = cb(totalValue, this[i], i, this);
   };
   return totalValue;
};

let red2 = numbers.reduce2(function(total, number) {
   return total + Math.round(number);
});

// console.log(red2);

// Empty elemets of array
// for(let i in this)

//====================================
// some()
Array.prototype.mySome = function(cb) {
   for(let index in this) {
       if(this.hasOwnProperty(index)) {
           if(cb(this[index], index, this))
               return true;
       };
   };
   return false;
};






