function Validator(options) {

   function validate(inputElement, rule) {
      var errorMessage =  rule.test(inputElement.value);
      var errorElement = inputElement.parentElement.querySelector(options.errorSelector);
      if(errorMessage) {
         errorElement.innerText = errorMessage;
         inputElement.parentElement.classList.add("invalid");
      } else {
         errorElement.innerText = "";
         inputElement.parentElement.classList.remove("invalid");
      }
   }
   var formElement = document.querySelector(options.form);
   if(formElement) {
      options.rules.forEach(rule => {
         var inputElement = document.querySelector(rule.selector);


         if(inputElement) {
            // xử lí blur khỏi input
            inputElement.onblur = function () {
               validate(inputElement, rule);
            }

            // xử lí mỗi khi người dùng nhập
            inputElement.oninput = function () {
              var errorElement = inputElement.parentElement.querySelector(options.errorSelector);
               errorElement.innerText = "";
               inputElement.parentElement.classList.remove("invalid");
            }
         }
      }) 
   }
   
}


// định nghĩ rule 
// 1. 
Validator.isRequired = function (selector) {
   return {
      selector: selector,
      test: function (value) {
         return value.trim() ? undefined : "Vui lòng nhập trường này" // trim loại bỏ dấu cách 2 đầu
      }
   }
}

Validator.isEmail = function (selector) {
   return {
      selector: selector,
      test: function (value) {
         var regex = /^(([^<>()[\]\.,;:\s@\"]+(\.[^<>()[\]\.,;:\s@\"]+)*)|(\".+\"))@(([^<>()[\]\.,;:\s@\"]+\.)+[^<>()[\]\.,;:\s@\"]{2,})$/i;
         return regex.test(value) ? undefined : "Trường này phải là email";
      }
   }
}

Validator.minLength = function (selector, min) {
   return {
      selector: selector,
      test: function (value) {
         return value.length >= min ? undefined : `Vui lòng nhập ${min} ký tự`;
      }
   }
}

Validator.isComfirmed = function (selector, getCofirmValue, message) {
   return {
      selector: selector,
      test: function (value) {
         return value === getCofirmValue() ? undefined : message || "Giá trị nhập vào không đúng";
      }
   }
}