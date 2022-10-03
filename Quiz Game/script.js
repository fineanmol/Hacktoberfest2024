const quizData = [
    {
        question: "Which of the following country won Football world Cup maximum times?",
        a: "Brazil",
        b: "France",
        c: "Argentina",
        d: "England",
        correct: "a",
    },
    {
        question: "When JavaScript was created",
        a: "1987",
        b: "1995",
        c: "1999",
        d: "1991",
        correct: "b",
    },
    {
        question: "Which palyer has the longest career in cricket",
        a: " Wilfred Rhodes",
        b: "Sachin Tendulkar",
        c: "Shahid Afridi",
        d: "Ricky Pointing",
        correct: "a",
    },
    {
        question: "when was first computer invented",
        a: "1822",
        b: "1834",
        c: "1827",
        d: "none of the above",
        correct: "a",
    },
    {
        question: "In which year did Austrailia win its first world cup",
        a: "1987",
        b: "1988",
        c: "1990",
        d: "1986",
        correct: "a",
    },


];

const quiz= document.getElementById('quiz')
const answerEls = document.querySelectorAll('.answer')
const questionEl = document.getElementById('question')
const a_text = document.getElementById('a_text')
const b_text = document.getElementById('b_text')
const c_text = document.getElementById('c_text')
const d_text = document.getElementById('d_text')
const submitBtn = document.getElementById('submit')


let currentQuiz = 0
let score = 0

loadQuiz()

function loadQuiz() {

    deselectAnswers()

    const currentQuizData = quizData[currentQuiz]

    questionEl.innerText = currentQuizData.question
    a_text.innerText = currentQuizData.a
    b_text.innerText = currentQuizData.b
    c_text.innerText = currentQuizData.c
    d_text.innerText = currentQuizData.d
}

function deselectAnswers() {
    answerEls.forEach(answerEl => answerEl.checked = false)
}

function getSelected() {
    let answer
    answerEls.forEach(answerEl => {
        if(answerEl.checked) {
            answer = answerEl.id
        }
    })
    return answer
}


submitBtn.addEventListener('click', () => {
    const answer = getSelected()
    if(answer) {
       if(answer === quizData[currentQuiz].correct) {
           score++
       }

       currentQuiz++

       if(currentQuiz < quizData.length) {
           loadQuiz()
       } else {
           quiz.innerHTML = `
           <h2>You answered ${score}/${quizData.length} questions correctly</h2>
           <button onclick="location.reload()">Reload</button>
           `
       }
    }
})