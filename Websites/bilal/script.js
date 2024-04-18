document.addEventListener('DOMContentLoaded', function() {
    const body = document.body;
    const correct = body.querySelector('.bon');
    const incorrect = body.querySelectorAll('.mauvais');
    const feedback = body.querySelector('.feedback');

    // Correct answer click
    correct.addEventListener('click', function() {
        correct.style.backgroundColor = 'green';
        feedback.innerHTML = 'Bonne réponse !';
    });

    // Wrong answer click
    for (let i = 0; i < incorrect.length; i++)
    {
        incorrect[i].addEventListener('click', function() {
            incorrect[i].style.backgroundColor = 'red';
            feedback.innerHTML = 'Tu es le mec le plus bête du monde !!!';
        });
    }
})