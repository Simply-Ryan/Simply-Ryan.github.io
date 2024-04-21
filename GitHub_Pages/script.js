document.addEventListener("DOMContentLoaded", function() {
    const mcqQuestions = 2;
    const inputQuestions = 1;
    // const totalQuestions = mcqQuestions + inputQuestions;
    const answers = ["2008", "Airplanes", "Canada"];

    function handleMCQClick(i, j) {
        return function() {
            const currentIncorrect = document.body.querySelectorAll(`.incorrect${i}`);
            currentIncorrect.forEach(element => {
                element.style.backgroundColor = "red";
            });
            document.querySelector(`#feedback${i}`).innerHTML = "Incorrect...";
            highlightCorrectAnswer(i);
            removeMCQEventListeners(i);
        }
    }

    function handleMCQCorrectClick(i) {
        return function() {
            const currentCorrect = document.body.querySelector(`.correct${i}`);
            currentCorrect.style.backgroundColor = "green";
            document.querySelector(`#feedback${i}`).innerHTML = "Correct!";
            removeMCQEventListeners(i);
        }
    }

    function removeMCQEventListeners(i) {
        const currentIncorrect = document.body.querySelectorAll(`.incorrect${i}`);
        currentIncorrect.forEach(element => {
            element.removeEventListener("click", handleMCQClick(i));
        });
    }

    function highlightCorrectAnswer(i) {
        const correctElement = document.body.querySelector(`.correct${i}`);
        correctElement.style.backgroundColor = "green";
    }

    for (let i = 1; i <= mcqQuestions; i++) {
        const currentCorrect = document.body.querySelector(`.correct${i}`);
        const currentIncorrect = document.body.querySelectorAll(`.incorrect${i}`);

        for (let j = 0; j < currentIncorrect.length; j++) {
            currentIncorrect[j].addEventListener("click", handleMCQClick(i, j));
        }
        
        currentCorrect.addEventListener("click", handleMCQCorrectClick(i));
    }

    function handleConfirmClick(i) {
        return function() {
            const inputValue = document.body.querySelector(`#input${mcqQuestions + i}`).value.toLowerCase();
            const correctAnswer = answers[mcqQuestions + i - 1].toLowerCase();
            const inputElement = document.body.querySelector(`#input${mcqQuestions + i}`);
            const feedbackElement = document.body.querySelector(`#feedback${mcqQuestions + i}`);

            if (inputValue === correctAnswer) {
                inputElement.style.backgroundColor = "green";
                feedbackElement.innerHTML = "Correct!";
            } else {
                inputElement.style.backgroundColor = "red";
                feedbackElement.innerHTML = `Incorrect... Answer was: ${answers[mcqQuestions + i - 1]}`;
                highlightCorrectAnswer(mcqQuestions + i);
                removeInputEventListener(mcqQuestions + i);
            }
        }
    }

    function removeInputEventListener(i) {
        const confirmButton = document.body.querySelector(`#confirm${i}`);
        confirmButton.removeEventListener("click", handleConfirmClick(i));
    }

    for (let i = 1; i <= inputQuestions; i++) {
        document.body.querySelector(`#confirm${mcqQuestions + i}`).addEventListener("click", handleConfirmClick(i));
    }

    document.body.querySelector(".reveal_answers").addEventListener("click", function() {
        for (let i = 1; i <= mcqQuestions; i++) {
            const incorrects = document.body.querySelectorAll(`.incorrect${i}`);
            incorrects.forEach(element => {
                element.style.backgroundColor = "";
            });
            document.body.querySelector(`.correct${i}`).style.backgroundColor = "yellow";
            document.body.querySelector(`#feedback${i}`).innerHTML = "Answer revealed.";
        }

        for (let i = 1; i <= inputQuestions; i++) {
            document.body.querySelector(`#input${mcqQuestions + i}`).style.backgroundColor = "yellow";
            document.body.querySelector(`#feedback${mcqQuestions + i}`).innerHTML = `Answer: ${answers[mcqQuestions + i - 1]}`;
        }
    });
});
