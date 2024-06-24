// JSON(JavaScript Object Notation)===========================================
// - Là một định dạng dữ liệu (chuỗi). Không phải kiểu dữ liệu
// - Cứu pháp đơn giản, nhẹ.
// - Thể hiện được kiểu dữ liệu: số, string, boolean, null, array, object,..
// - Có hai thao tác: encode và decode (stringify, parse).
// - Không thể hiện được class, function 
// - Server trả lại cho client là JSON 

// var json = '1'; // thể hiện kiểu dữ liệu number // '["JS", "C#"]' -> thể hiện dạng array // '{"name": "duong", "age": 18}'
// var json2 = '{"name": "duong", "age": 18}';
// var obj = JSON.parse(json2)
// console.log(typeof JSON.stringify(obj)); // \" -> dấu kép ngược 


// Promise =======================================================================
// - sync: viết trước thực hiện trước in ra trước.
// - async: viết trước nhưng thực hiện sau. // setimeout, setInterval, fetch, XMLHttPrequest, file reading, request animation frame.
// => callback để xử lí bất đồng bộ => promise.
// - nỗi đau (pain)
// callback hell, Pyramid of doom
// - lý cách hoat động promise
// - Thực hành, ví dụ

setTimeout(function() {
   console.log('Dòng này sẽ in ra sau')
}, 0)
// setTimeout là tác vụ bất động bộ (async)

console.log('Dòng này sẽ in ra trước') // Đây là tác vụ đồng bộ (sync)

// callback hell
// setTimeout(function() {
//    console.log("1")
//    setTimeout(function() {
//       console.log("2")
//       setTimeout(function() {
//          console.log("3")
//          setTimeout(function() {
//             console.log("4")
//             setTimeout(function() {
//                console.log("5")
//             }, 1000);
//          }, 1000);
//       }, 1000);
//    }, 1000);
// }, 1000);

// promise: xử lí cho các theo tác bất đồng bộ 
// 1. new Promise: tạo ra đối tượng(là contructor)
// 2. Executor 
// phả trả về resolve, reject => nếu không bị treo => memory lead 

var promise = new Promise( // trả về đối tượng 
   // executor function
   function(resolve, reject) {
      // logic
      // reject(): khi that bai
      // resolve(): khi thanh cong
      resolve("Thanh cong!");

   }
);

// 3 trang thai
// 1. Pendding: chờ thành công hay thất bại (memory lead nếu không resolve, reject)
// 2. Fulfilled: thành công -> then() -> finally()
// 3. Rejected: thất bại -> catch() -> finally()  

// promise // gọi đối tượng gọi methor then(callback function) , catch(callback function).
//    .then(function(status) {
//       console.log(status);
//    })
//    .catch(function(error) {
//       console.log(error);
//    })
//    .finally(function() {
//       console.log("Done!");
//    })

// chain

// promise
//    .then(function(data) {
//       return 1;
//    })
//    .then(function(data) {
//       console.log(data);
//       return 2;
//    })
//    .then(function(data) {
//       console.log(data);
//       return 3;
//    })

// promise
//    .then(function() {
//       return new Promise(function(resolve) { // nếu như không return không promise thì chạy ngay cái liền kề nó. 
//          setTimeout(resolve, 5000);
//       })
//    })
//    .then(function(data) {
//       console.log("data: ", 1);
//    })

// function sleep(ms) {
//    return new Promise((resolve) => {
//       setTimeout(resolve, ms);
//    })
// }

// sleep(1000)
//    .then(function(data) {
//       console.log(1);
//       return sleep(1000);
//    })
//    .then(function() {
//       console.log(2);
//    })

// console.log("hehe");

// function hell(value, cb) {
//    cb(value);
// }

// // Không sử dụng Promise dẫn đến tạo ra callback hell 
// hell(1, function (valueFromA) {
//    hell(valueFromA + 1, function (valueFromB) {
//        hell(valueFromB + 1, function (valueFromC) {
//            hell(valueFromC + 1, function (valueFromD) {
//                console.log(valueFromD + 1);
//            });
//        });
//    });
// });

// // Sử dụng Promise sẽ tạo ra đoạn code dễ đọc hơn và vẫn đảm bảo đúng logic
// function notHell(value) {
//    return new Promise(function (resolve) {
//        resolve(value);
//    });
// }

// notHell(1)
//    .then(function (value) {
//        return value + 1;
//    })
//    .then(function (value) {
//        return value + 1;
//    })
//    .then(function (value) {
//        return value + 1;
//    })
//    .then(function (value) {
//        console.log(value + 1);
//    });

// Promise methors ====
// .resolve, .reject, . all
// Một chuỗi có thể bị reject ở giữa đường. => các then tiếp theo bị bỏ qua. 
// Promise.all() => dùng các chức năng chạy song song => cả hai kết quả của nó làm gì đó.

// function sleep(ms) {
//    return new Promise((resolve) => {
//       setTimeout(resolve, ms);
//    })
// }

// sleep(1000)
//    .then(function(data) {
//       console.log(1);
//       return sleep(1000);
//    })
//    .then(function(data) {
//       console.log(2);
//       return new Promise(function(resovle, reject) { // ngắt ngay đây
//          reject('Error!');
//       })
//    })
//    .then(function(data) {
//       console.log(4);
//       return sleep(1000);
//    })
//    .then(function() {
//       console.log(4);
//    })
//    .catch(function(error) { // chạy xuống đây
//       console.log(error) 
//    })

var promise1 = new Promise(function(resolve, reject) {
   setTimeout(function() {
      resolve([1, 2]);
   }, 2000);
});

var promise2 = new Promise(function(resolve, reject) {
   setTimeout(function() {
      resolve([3])
   }, 5000);
})

Promise.all([promise1, promise2])
   .then(function([result1, result2]) {
      console.log(result1.concat(result2));
   })
      
   












