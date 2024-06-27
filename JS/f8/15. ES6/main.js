// 1. const, var, const ====================================
// scope: phạm vi, hosting: đưa lên đầu.
// var(hosting): scope -> globle
// let / const: scope -> local
// - Thuộc tích của object vẫn thay đổi được

// 2. template string =====================================================
// `${}`
// 3. Muti-string String ` ===============================================
//   line 1
//   line 2
//`
// 4. Arrow function ======================================================
// () => {}
// declaration function / expression function(gán cho biến một một function) 
// const sum = (a, b) => ({a, b}); // Không dụng được với constructor function / context;
// console.log(sum(1,2));


// 5. classes ============================================================

// contructor fucntion
// function Course(name, price) {
//    this.name = name;
//    this.price = price;
// }

// classes 
// class Course {
//    constructor(name, price) {
//       this.name = name;
//       this.price = price;
//    }
//    getName() {
//       return this.price;
//    }
// }
// const course1 = new Course("JavaScipt", 1000);
// const course2 = new Course("CSharp", 2000);
// console.log(course1, course2, course1.getName());

// 5. Default parameter values ===========================
// function x() {
//    console.log(1);
// }
// console.log(x());

// 6. Enhaced object literals ===========================
// - Định nghĩa key: value object.
// - Định nghĩa methor object.
// - Định nghĩ key cho object dưới dạng biến. 
// var name = "JavaScript";
// var price = 1000;
// var content = "content1"

// var courses = {
//    name,
//    price,
//    [content]: "HEHE",
//    getName() {
//       return this.name;
//    }
// }

// console.log(courses[content]);

// 7. Destructuring, rest===================================
// var array = ["JavaScipt", "CSharp", "Java"];
// var [a, b, c] = array;
// var [d, ...rest] = array; // => rest là mảng;
// console.log(a, b, c);
// console.log(a, rest);

// var courses = {
//    name: "JavaScript",
//    price: 1,
//    image: 'image'
// }

// var {name, price, image, description = "mac dinh"} = courses;
// var {name, ...newObject} = courses;
// console.log(name, price, image, description);
// console.log(newObject);

// function logger(a, ...param) {
//    console.log(param); // ...param => là mảng
// }
// logger(1,2,3,4,5,6,7); // tương tự với object và mảng. { a, ...rest}, [a, ...rest]

// 8. spread-rải==============================================
// var array1 = ['JS', 'Java', 'C#'];
// var array2 = ['ReactJS', 'Agular'];
// var array3 = [...array1, ...array2]; // sử dụng tượng tự cho object / có thể overwrite lại thuộc tính - object. 
// console.log(array3);

// 9. Tagged template literals -> =========================================

// const hightlight = ([first, ...strings], ...values) => {
//    console.log(first);
//    console.log(strings);
//    console.log(values);
//    return values.reduce((arr, current) => {
//       return [...arr,`<span>${current}</span>`, strings.shift()]
//    }, [first])
// }

// var brand = 'f8';
// var course = 'Javascript';

// const html = hightlight`Học lập trình ${course} tại ${brand}!`;
// console.log(html);

// 10. Modules ===========================================================
// import logger from "./logger";//chỉ dùng cho export default
// import { } from "./"// export cái muốn lấy ra không phải default. dùng rest
// import * as constant from "./" // import tất cả constant object cung cấp các method.
// import logger from ""; export default logger; === export {default} from ""; / export {default as logger2} from "";

// console.log("d", logger("hhe", "log"));

// 11. Optional chaining (?.) ===========================================
// Sử dụng khi không chắn chăn key nó có tồn tại hay không.
// Dùng cho index, value, function / obj.getName?.(123);