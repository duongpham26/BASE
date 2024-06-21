/** HTML DOM
 * 1. Element: ID, class, tag, CSS selector, HTML collection
 * 2. Attribute: 
 * 3. Text: innerText, textContent
 * 4. innertHTML, OuterHTML: thêm element và một element
 */

// var headingNode = document.getElementById("heading");
// console.log(heading); // dev tool tự hiểu và trả về tag (heading)
// console.log({ element: heading });

// var headingElementsClass = document.getElementsByClassName("heading"); //=> trả về collection
// // HTML collection
// console.log(headingElementsClass); // trả về giống mảng nhưng không có phương thức map, reduce,...

// // getElementByTagName => trả về collection

// CSS selector
// var selector = document.querySelector('.heading');
// var selectors = document.querySelectorAll('.heading'); // => trả về Nodelist
// console.log(selectors);

// //HMTL collection
// var htmlcolection2 = document.forms["form-1"]; // => trả về html collection
// // var htmlcolection3 = document.anchors; // => trả về html collection
// console.log(htmlcolection1);// var htmlcolection1 = document.forms; // => trả về html collection


// // thêm
// // một node có thể thay thếu node cha document 
// var listNode = document.querySelector('.list');
// var elementsLi = listNode.getElementsByTagName("li");
// // console.log(elementsLi);

//==================================
// 2. Attribute

// // seter -> set trực tiếp giá trị 
// var headingH1 = document.querySelector("h1");
// headingH1.className = "headinhadd";

// // dùng method
// headingH1.setAttribute('class', 'class-setAtribute');
// // console.log(headingH1);

// // lấy ra attribute
// console.log(headingH1.getAttribute('class'));

// // .attribute
// headingH1.title = "title";
// // console.log(headingH1.title);


// 3. text ===================================
// geter/seter
// innerText: thuộc tích của element node
// textContent: thuộc tích cả text-node và element-node

// var headingh1 = document.querySelector('h1');
// console.log(headingh1.innerText);
// console.log(headingh1.textContent);
// headingh1.innerText = "HTML DOM EDIT";
// console.log(headingh1.innerText);

// 4. thêm element ==========================
// property (thuộc tích của element)
// outerHTML -> thao tác trên element đang được lấy ra và ghi đè nếu seter element;

// var boxElement = document.querySelector('.box');
// boxElement.innerHTML  = '<h1 title="heading">hehe</h1>';
// console.log(boxElement.innerHTML);


// NODE PROPERTY ===================================

// CSS DOM =========================================
// // - Viết heo camelCase 
// var boxElement = document.querySelector('.box');
// var boxElement2 = document.querySelector('.box2');
// var textNode = boxElement.textContent;
// console.log({textNode});
// boxElement.style.width = '100px';
// boxElement.style.height = '100px';
// boxElement.style.backgroundColor = 'red';

// // viết nhiều thuộc tính cùng lúc.
// Object.assign(boxElement.style, {
//    width: '200px',
//    height: '100px',
//    backgroundColor: 'green',
//    color: "red",
// })
// geter

//CLASSLISH PROPERTY ====================================
// add, contains, remove, toggle

// var divElement = document.querySelectorAll('div');
// divElement.forEach((d) => {
//    d.classList.toggle(".s");
// })
// console.log(divElement);


// =========================================================
// DOM EVENT =============================================
// Attrivute EVENT=======================================
// - viết vào thẻ như attribute của thẻ 
// onclick this -> trả về element node 
// - Sự kiện nổi bọt-> có thể chăn sự kiện nổi bọt.


// assign event using the element node===================
// var h1Element = document.querySelectorAll('h1');
// h1Element.forEach(ele => {
//    ele.onclick = (e) => {
//       console.log(e.target);
//    }
// })
// h1Element.onclick = (event) => {
//    console.log(event.target);
// }
// console.log(h1Element);

// example ===============================================
// keyup , kedown, onchange, onclick 
// var inputText = document.querySelector('input[type="text"]');
// var inputCheck = document.querySelector('input[type="checkbox"]');

// var selectElement = document.querySelector('select');
// inputText.oninput = (e) => {
//    console.log(e.target.value);
// } 
// inputCheck.onchange = (e) => {
//    console.log(e.target.checked);
// } 
// selectElement.onchange = (e) => {
//    console.log(e.target.value);
// }

// document.onkeydown = (e) => {
//    console.log(e.target.value);
// }

//==========================================
// 1. preventDefault 
// 2. stopPropagation => e.stopPropagation();


// var inputText = document.querySelector('input[type="text"]');
// var ulElement = document.querySelector('ul');

// ulElement.onmousedown = (e) => {
//    e.preventDefault();
// }
// ulElement.onclick = (e) => {
//    console.log(e.target.value)
// }


// EVENT LISTEN =============================
// 1. xử lí nhiều việc khi một event xảy ra 
// 2. Lắng nghe / hủy bỏ lắng nghe (gỡ bỏ thêm event trong trường hợp cụ mà không muốn liên tục lắng nghe)
