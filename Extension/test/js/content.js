




const answers = [{"answers":[{"text":"<p>7</p>"}],"question":{"text":"<p>Có mấy bước lập kế hoạch ?</p>"},"type":"MCQ","_id":"6684df8f7f00fd12bbdc3e3f"},{"answers":[{"text":"<p>Là một bản thiết kế cho việc xác định phương pháp và cách thức thực hiện chiến lược Marketing trực tuyến.</p>"}],"question":{"text":"<p>Kế hoạch Marketing trực tuyến là ?</p>"},"type":"MCQ","_id":"6684df8f7f00fd75b8dc3e40"},{"answers":[{"text":"<p>Kế hoạch hình thành từ thực tế các tác nghiệp và đề xuất công ty thực hiện, xuất phát từ ý tưởng bất chợt kế hoạch mang tính thời sự cao.</p>"}],"question":{"text":"<p>Kế hoạch NAPKIN là gì ?</p>"},"type":"MCQ","_id":"6684df8f7f00fd091adc3e41"},{"answers":[{"text":"<p>Maketing Opportunity Analists</p>"}],"question":{"text":"<p>MOA là gì ?</p>"},"type":"MCQ","_id":"6684df8f7f00fdb30fdc3e42"},{"answers":[{"text":"<p>Giúp cho việc dự đoán lợi nhuận, tìm ra lợi thế cạnh tranh có được trong thị trường trực tuyến.</p>"}],"question":{"text":"<p>Mục đích của phân khúc thị trường ?</p>"},"type":"MCQ","_id":"6684df8f7f00fda58ddc3e43"},{"answers":[{"text":"<p>Mục tiêu của kế hoạch</p>"}],"question":{"text":"<p>Bước 3 trong 7 bước lập kế hoạch là gì ?</p>"},"type":"MCQ","_id":"6684df8f7f00fd6400dc3e44"},{"answers":[{"text":"<p>Nêu các nhiệm vụ, có thể do lường, giới hạn thời gian.</p>"}],"question":{"text":"<p>Một mục tiêu trong một kế hoạch Marketing trực tuyến phải thỏa mãn các yêu cầu</p>"},"type":"MCQ","_id":"6684df8f7f00fd48b5dc3e45"},{"answers":[{"text":"<p>A,B,C đều đúng</p>"}],"question":{"text":"<p>Nhiệm vụ của chiến lược Marketing trực tuyến là ?</p>"},"type":"MCQ","_id":"6684df8f7f00fd2759dc3e46"},{"answers":[{"text":"<p>A,B,C đều đúng</p>"}],"question":{"text":"<p>Chi phí trực tuyến bao gồm ?</p>"},"type":"MCQ","_id":"6684df8f7f00fd6f78dc3e47"},{"answers":[{"text":"<p>Đánh giá khả năng thành công của kế hoạch</p>"}],"question":{"text":"<p>Đo lương tính khả thi của kế hoạch là nhiệm vụ của bước mấy ?</p>"},"type":"MCQ","_id":"6684df8f7f00fda297dc3e48"}]
function answerQuiz() {
   // Tìm phần tử chứa câu hỏi hiện tại
   const questionElement = document.querySelector('.question-text-color p'); // Điều chỉnh selector nếu cần
   if (!questionElement) {
       console.log('Không tìm thấy phần tử chứa câu hỏi.');
       return;
   }

   // Lấy nội dung câu hỏi hiện tại
   const questionText = questionElement.innerText.replace(/<\/?[^>]+(>|$)/g, ""); // Loại bỏ các thẻ HTML

   // Tìm câu trả lời đúng trong danh sách
   const correctAnswer = answers.find(q => q.question.text.replace(/<\/?[^>]+(>|$)/g, "") === questionText);

   if (!correctAnswer) {
       console.log('Không tìm thấy câu trả lời cho câu hỏi:', questionText);
       return;
   }

   // Tìm các phần tử chứa câu trả lời và chọn câu trả lời đúng
   const answerElements = document.querySelectorAll('#optionText .text-container div p'); // Điều chỉnh selector nếu cần
   for (let answerElement of answerElements) {
       const answerText = answerElement.innerHTML.replace(/<\/?[^>]+(>|$)/g, "").trim(); // Loại bỏ các thẻ HTML và khoảng trắng
       if (answerText === correctAnswer.answers[0].text.replace(/<\/?[^>]+(>|$)/g, "").trim()) {
           answerElement.click();
           console.log('Đã chọn câu trả lời:', correctAnswer.answers[0].text);
           break;
       }
   }
}


const target = document.querySelector(".text-sm");

// Cấu hình các tùy chọn cho observer
const config = { childList: true, subtree: true, characterData: true };

// Callback function sẽ được gọi khi có sự thay đổi
const callback = function(mutationsList, observer) {
    for (let mutation of mutationsList) {
        if (mutation.type === 'childList') {
            console.log('Child list has changed.');
        } else if (mutation.type === 'characterData') {
            console.log('Character data has changed.');
        }
         setTimeout(function() {
            answerQuiz();
         }, 4500);
    }
};

// Tạo một thể hiện của MutationObserver với callback function đã xác định
const observer = new MutationObserver(callback);

// Bắt đầu theo dõi phần tử với các cấu hình đã xác định
// observer.observe(target, config);

