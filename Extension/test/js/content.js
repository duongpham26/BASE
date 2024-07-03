// Duong Pham cua Bích Duy 

let id = document.querySelector(".room-code").innerText;
let url = `https://api.quizit.online/quizizz/answers?pin=${id}`;
let answers = [];
fetch(url)
    .then(function (response) {
        return response.json(); 
    })
    .then(function (ans) {
        answers = ans.data.answers
    })

function answerQuiz() {
    const questionElement = document.querySelector('.question-text-color p'); // Điều chỉnh selector nếu cần
    if (!questionElement) {
        // console.log('Không tìm thấy phần tử chứa câu hỏi.');
        return;
    }

    const questionText = questionElement.innerText.replace(/<\/?[^>]+(>|$)/g, "");

    const correctAnswer = answers.find(q => q.question.text.replace(/<\/?[^>]+(>|$)/g, "") === questionText);

    if (!correctAnswer) {
        // console.log('Không tìm thấy câu trả lời cho câu hỏi:', questionText);
        return;
    }

    const answerElements = document.querySelectorAll('#optionText .text-container div p'); 
    for (let answerElement of answerElements) {
        const answerText = answerElement.innerHTML.replace(/<\/?[^>]+(>|$)/g, "").trim(); 
        if (answerText === correctAnswer.answers[0].text.replace(/<\/?[^>]+(>|$)/g, "").trim()) {
            answerElement.click();
            // console.log('Đã chọn câu trả lời:', correctAnswer.answers[0].text);
            break;
        }
    }
}

const target = document.querySelector(".text-sm");
const target1 = document.querySelector(".app-header-container");
const config = { childList: true, subtree: true, characterData: true };

const callback = function (mutationsList, observer) {
    for (let mutation of mutationsList) {
        if (mutation.type === 'childList') {
            console.log('Child list has changed.');
        } else if (mutation.type === 'characterData') {
            console.log('Character data has changed.');
        }
        let setInter = setInterval(function () {
            answerQuiz();
        }, 50)

        setTimeout(function () {
            clearInterval(setInter);
        }, 5000);
    }
};

const observer = new MutationObserver(callback);
observer.observe(target1, config);




