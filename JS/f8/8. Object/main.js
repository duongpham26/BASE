// OJECT TRONG JAVASCRIPT

var emailKey = 'email';
var myInfo = {
    name: 'Duong Pham',
    age: 18,
    address: 'HCM',
    'my-phone': 12,
    [emailKey]: 'duongpham@gmail.com',
};
console.log(myInfo['my-phone']);

// function --> phương thức
// orthers --> thuốc tính/property
// vi phạm thì để trong dấu ngoặc kép, đơn;

/** 2. Object constructor
 *
 */
function User(firstName, lastName, avatar) {
    this.firstName = firstName;
    this.lastName = lastName;
    this.avatar = avatar;
    this.getName = function () {
        return `${this.firstName} ${this.lastName}`;
    };
}

var author = new User('Son', 'Dang', 'Avatar1');
var user = new User('Duong', 'Pham', 'avatar2'); // đối tượng user và author
//tạo thêm
author.title = '123';
user.comment = '456';
console.log(author.constructor == User); // kiểm tra constructor
console.log(author.getName());

/** 3. Oject prototype - Basic
 *      1. Prototype là gì?
 *          Nguyên mẫu để tạo nên một đối tượng. Như nguyên liệu tạo ngồi nhà.
 *      2. Sử dụng khi nào
 */

User.prototype.className = 'F8'; // thêm thuộc tính
User.prototype.getClassName = function () {
    return this.className;
};
// ==> không truyền vào từ new constructor, bắt buộc dùng this. trong hàm tạo

console.log(user.className);
console.log(author.getClassName());

/** 4. Đối tượng data */
var data1 = Date(); // trả về string
var date = new Date(); // trả về đối tượng
var month = date.getMonth() + 1;
var year = date.getFullYear();

console.log(year);

/** 5. Math oject
 *      - Math.PI
 *      - Math.round()
 *      - Math.abs()
 *      - Math.ceil()
 *      - Math.floor()
 *      - Math.random() --> 0 - nhỏ hơn 1
 *      - Math.min()
 *      - Math.max()
 */

var random = Math.floor(Math.random() * 100);
console.log(Math);
