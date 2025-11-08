class Quiz {
    constructor(questions) {
        this.questions = questions;
        this.currentQuestionIndex = 0;
        this.score = 0;
    }

    getCurrentQuestion() {
        return this.questions[this.currentQuestionIndex];
    }

    checkAnswer(selectedIndex) {
        let isCorrect=selectedIndex==this.questions[this.currentQuestionIndex].correctAnswer;
        if(isCorrect){ this.score+=1; }
        return isCorrect;
    }

    nextQuestion() {
        this.currentQuestionIndex++;
    }

    isFinished() {
        return this.currentQuestionIndex >= this.questions.length;
    }

    // TODO: Add method to shuffle questions
    // shuffleQuestions() { }
    
    // TODO: Add method to filter by category
    // filterByCategory(category) { }
    
    // TODO: Add method to filter by difficulty
    // filterByDifficulty(difficulty) { }
    
    // TODO: Add timer methods
    // startTimer() { }
    // stopTimer() { }
    // getTimeRemaining() { }
}
