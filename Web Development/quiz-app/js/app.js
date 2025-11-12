// app.js - Main application logic

let currentQuiz;
let questions = [];

// let restart_btn = document.querySelector("#restart-btn");
// restart_btn.addEventListener("click",() => {
    
// })
// Initialize app when DOM is loaded
document.addEventListener('DOMContentLoaded', () => {
    loadQuestions();
    setupEventListeners();
});

// Set up event listeners
function setupEventListeners() {
    document.getElementById('start-btn').addEventListener('click', startQuiz);
    document.getElementById('restart-btn').addEventListener('click', restartQuiz);
}

// Load questions from JSON file
async function loadQuestions() {
    const response = await fetch('data/questions.json');
    questions = await response.json();
    console.log('Questions loaded successfully');
}

// Start the quiz
function startQuiz() {
    
    if(questions.length==0){
        alert("There are no questions here");
        return;
    }
    // Create new quiz instance
    currentQuiz = new Quiz(questions);
    
    // Hide welcome screen and show quiz screen
    document.getElementById('welcome-screen').classList.add('hidden');
    document.getElementById('quiz-screen').classList.remove('hidden');
    
    // Display first question
    displayQuestion();
}

// Display current question
function displayQuestion() {
    const question = currentQuiz.getCurrentQuestion();
    
    // Update question number
    document.getElementById('question-number').textContent = 
        `Question ${currentQuiz.currentQuestionIndex + 1}/${currentQuiz.questions.length}`;
    
    // Update score
    document.getElementById('score').textContent = `Score: ${currentQuiz.score}`;
    
    // Display question text
    document.getElementById('question').textContent = question.question;
    
    // Display options
    const optionsContainer = document.getElementById('options');
    
    question.options.forEach((option, index) => {
        const button = document.createElement('button');
        button.className = 'option-btn';
        button.textContent = option;
        button.addEventListener('click', () => selectAnswer(index));
        optionsContainer.appendChild(button);
    });
}

// Handle answer selection
function selectAnswer(selectedIndex) {
    const isCorrect = currentQuiz.checkAnswer(selectedIndex);
    
    // Basic feedback (no animation yet - room for improvement)
    const buttons = document.querySelectorAll('.option-btn');
    buttons[selectedIndex].style.backgroundColor = isCorrect ? '#28a745' : '#dc3545';
    
    // Disable all buttons after selection
    buttons.forEach(btn => btn.disabled = true);
    
    // Move to next question after a short delay
    currq = currentQuiz.getCurrentQuestion();
    const timeout = 0;
    if(currq["difficulty"]==="easy"){
        timeout = 1000
    }else if(currq["difficulty"]==="medium"){
        timeout = 1200
    } else {
        timeout = 1500
    }
    setTimeout(() => {
        currentQuiz.nextQuestion();
        
        if (currentQuiz.isFinished()) {
            showResults();
        } else {
            displayQuestion();
        }
    }, timeout);
}

// Show results screen
function showResults() {
    // Hide quiz screen and show results screen
    document.getElementById('quiz-screen').classList.add('hidden');
    document.getElementById('results-screen').classList.remove('hidden');
    
    // Display final score
    const percentage = Math.round((currentQuiz.score / currentQuiz.questions.length) * 100);
    document.getElementById('final-score').textContent = 
        `Your Score: ${currentQuiz.score}/${currentQuiz.questions.length} (${percentage}%)`;
    
    // TODO: Save high score to localStorage (not implemented yet)
    // TODO: Show detailed statistics (not implemented yet)
}

// Restart quiz
function restartQuiz() {
    // Hide results screen and show welcome screen

    if(confirm("Are you sure you want to restart?")){
        document.getElementById('results-screen').classList.add('hidden');
        document.getElementById('welcome-screen').classList.remove('hidden');
        
        // Reset quiz
        currentQuiz = null;
    }
}
    document.getElementById('results-screen').classList.add('hidden');
    document.getElementById('welcome-screen').classList.remove('hidden');
    
    // Reset quiz
    currentQuiz = null;
}

