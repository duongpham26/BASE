/** HTML DOM
 * 1. Element: ID, class, tag, CSS selector, HTML collection
 * 2. Attribute: 
 * 3. Text: innerText, textContent
 * 4. innertHTML, OuterHTML: thêm element và một element
 */

// var headingNode = document.getElementById("heading");
// // console.log(heading); // dev tool tự hiểu và trả về tag (heading)
// // console.log({ element: heading });

// var headingElementsClass = document.getElementsByClassName("heading"); //=> trả về collection
// // HTML collection
// //console.log(headingElementsClass); // trả về giống mảng nhưng không có phương thức map, reduce,...

// // getElementByTagName => trả về collection

// // CSS selector
// var selector = document.querySelector('.heading');
// var selectors = document.querySelectorAll('.heading'); // => trả về Nodelist
// // console.log(selectors);

// //HMTL collection
// var htmlcolection1 = document.forms; // => trả về html collection
// var htmlcolection2 = document.forms["form-1"]; // => trả về html collection
// // var htmlcolection3 = document.anchors; // => trả về html collection
// console.log(htmlcolection1);

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

var boxElement = document.querySelector('.box');
boxElement.innerHTML  = '<h1 title="heading">hehe</h1>';
console.log(boxElement.innerHTML);


