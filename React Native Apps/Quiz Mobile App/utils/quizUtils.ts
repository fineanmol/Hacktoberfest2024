// utils/quizUtils.ts

// Using an algorithm to shuffle the options
// Algorithm source: https://stackoverflow.com/questions/2450954/how-to-randomize-shuffle-a-javascript-array
// Credit: Durstenfeld shuffle,
export const shuffleArray = (array: any[]) => {
  for (let i = array.length - 1; i > 0; i--) {
    const j = Math.floor(Math.random() * (i + 1));
    const temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
};

// Function to handle the logic for skipping a question
export const handleSkipQuestion = (
  currentQuestion: number,
  questions: Question[],
  setCurrentQuestion: (value: React.SetStateAction<number>) => void,
  setAnswered: (value: React.SetStateAction<boolean>) => void,
) => {
  if (currentQuestion !== questions.length - 1) {
    setCurrentQuestion(currentQuestion + 1);
    setAnswered(false); // Reset answered status for the next question
  }
};

// Function to handle the logic for selecting an option
export const handleSelectedOption = (
  option: string,
  answered: boolean,
  setAnswered: (value: React.SetStateAction<boolean>) => void,
  questions: Question[],
  currentQuestion: number,
  setCurrentQuestion: (value: React.SetStateAction<number>) => void,
  setScore: (value: React.SetStateAction<number>) => void,
  score: number,
  navigation: any,
) => {
  if (!answered) {
    setAnswered(true);
    const decodedSelectedOption = decodeURIComponent(option);
    const decodedCorrectAnswer = decodeURIComponent(
      questions[currentQuestion].correct_answer,
    );

    if (decodedSelectedOption === decodedCorrectAnswer) {
      console.log('Correct answer');
      setScore(score + 10);
    } else {
      console.log('Wrong answer');
    }

    // Skip to the next question
    setTimeout(() => {
      handleSkipQuestion(
        currentQuestion,
        questions,
        setCurrentQuestion,
        setAnswered,
      );
      if (currentQuestion === questions.length - 1) {
        console.log('Total Scores:', score); // Log the total score
        navigation.navigate('Results', {score: score});
      }
    }, 1000);
  }
};

// Define the Question interface here if it's not already defined.
interface Question {
  question: string;
  correct_answer: string;
  incorrect_answers: string[];
}
