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

// var promise1 = new Promise(function(resolve, reject) {
//    setTimeout(function() {
//       resolve([1, 2]);
//    }, 2000);
// });

// var promise2 = new Promise(function(resolve, reject) {
//    setTimeout(function() {
//       resolve([3])
//    }, 5000);
// })

// Promise.all([promise1, promise2])
//    .then(function([result1, result2]) {
//       console.log(result1.concat(result2));
   // })

//    const users = [
//       {
//          id: 1,
//          name: "Duong Pham",
//       },
//       {
//          id: 2,
//          name: "Bích Duy",
//       }
//    ]
// const comments = [
//    {
//       id: 1,
//       user_id: 1,
//       content: "Co di choi hong?"
//    },
//    {
//       id: 2,
//       user_id: 2,
//       content: "Co."
//    },
//    {
//       id: 3,
//       user_id: 1,
//       content: "HEHE."
//    },
// ]

// const getComments = function() {
//    return new Promise(function(resolve, reject) {
//       setTimeout(function() {
//          resolve(comments)
//       }, 2000);
//    });
// };
// const getUsers = function(userId) {
//    return new Promise(function(resolve, reject) {
//       const results = users.filter(function(user) {
//          return userId.includes(user.id);
//       })
//       setTimeout(function() {
//          resolve(results)
//       }, 2000);
//    });
// };

// getComments(comments)
//    .then(function(data) {
//       var userId = data.map(function(comment) {
//       return comment.user_id;
//    });
//    return getUsers(userId)
//       .then(function(users) {
//          return {
//             users: users,
//             comments: comments,
//          }
//       })
//    .then(function(data) {
//       const ulElement = document.getElementById('box-comment');
//       let xhtml = '';
//       data.comments.forEach(function(comment) {
//          let findUser = data.users.find(function(user) {
//             return comment.user_id === user.id;
//          });
//          xhtml += `<li>${findUser.name}: ${comment.content}</li>`
//       });
//       ulElement.innerHTML = xhtml;
//       console.log(ulElement);
//    })
// });


// fetch ===================
// JSON server: fake API server / mock API   
// return một promise 
// response.json() => phương thức trả về giống như JSON.parser()
// fetch("https://jsonplaceholder.org/posts")
//    .then(function(response) {
//       return response.json(); // json.parser()
//    })
//    .then(function(posts) {
//       const ulelement = document.getElementById('box-comment');
//       let xhmtl = '';
//       posts.forEach(function(post) {
//          xhmtl += `
//          <li>
//             <h2>${post.title}</h2>   
//             <p>${post.content}</p>
//          </li>
//          `
//       });
//       ulelement.innerHTML = xhmtl;
//    })

// fetch('http://localhost:3000/posts')
//    .then(function(response) {
//       return response.json();
//    })
//    .then(function(posts) {
//       console.log(posts);
//    })


// example ====


let urlAPI = "http://localhost:3000/courses";

function start() {
   getCourses(renderCourses);
   handleCreateForm();
}
start();

function getCourses(callback) {
   fetch(urlAPI)
         .then(function(response) {
            return response.json();
         })
         .then(callback);
}

function createCourse(data, callback) {
   fetch(urlAPI, {
         method: 'POST',
         headers: {
            'Content-Type': 'application/json'
         },
         body: JSON.stringify(data)
   })
   .then(response => response.json())
   .then(callback) 
}

function handleDelete(id) {
   fetch(urlAPI + '/' + id, {
         method: 'DELETE',
         headers: {
            'Content-Type': 'application/json'
         },
   })
   .then(response => response.json())
   .then(function(data) {
      let liElement = document.querySelector(`.data-id-${data.id}`)
      if(liElement) liElement.remove();
   }) 
}

function update(data, id, callback) {
   fetch(urlAPI + '/' + id, {
      method: 'PUT',
      headers: {
         'Content-Type': 'application/json'
      },
      body: JSON.stringify(data)
   })
   .then(response => response.json())
   .then(callback)
}

function handleUpdate(id) {
   var title = document.querySelector('input[name="name"]');
   var content = document.querySelector('input[name="content"]');
   let liElement = document.querySelector(`.data-id-${id}`)
   title.value = liElement.querySelector('h4').innerText;
   content.value = liElement.querySelector('p').innerText;
   var btn = document.querySelector("#btn");
   btn.innerText = "Update";
   
   btn.onclick = function(e) {
      let data = {
         title: title.value,
         content: content.value
      };
      update(data, id , function (data) {
         liElement.querySelector('h4').innerText = data.title;;
         liElement.querySelector('p').innerText = data.content;
         btn.innerText = "Submit";
         title.value = "";
         content.value = "";
      });
   } 
}

function renderCourses(courses) {
   var listCoursesBlock = document.querySelector("#box-comment");
   var htmls = courses.map(course => {
         return `
         <li class="data-id-${course.id}">
            <h4>${course.title}</h4>
            <p>${course.content}</p>
            <button onclick="handleDelete('${course.id}')">Xóa</button>
            <button onclick="handleUpdate('${course.id}')">Update</button>
         </li>
         `;
   });
   listCoursesBlock.innerHTML = htmls.join('');
}

function handleCreateForm() {
   var btn = document.querySelector("#btn");
   btn.onclick = function(event) {
         event.preventDefault(); // Ngăn chặn form reload lại trang
         var title = document.querySelector('input[name="name"]').value;
         var content = document.querySelector('input[name="content"]').value;
         var formData = {
            title,
            content,
         };
         createCourse(formData, function() {
         getCourses(renderCourses);
         });
   }
}



   












