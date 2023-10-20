import React, {useEffect, useState} from 'react';
import {StyleSheet, Text, View, TouchableOpacity} from 'react-native';
import {fetchQuizData} from '../network/QuizApi';
import {Vibration} from 'react-native';
import {shuffleArray, handleSelectedOption} from '../utils/quizUtils';
import LottieView from 'lottie-react-native';
import {useRoute} from '@react-navigation/native';

interface Question {
  question: string;
  correct_answer: string;
  incorrect_answers: string[];
}

export default function Quiz({navigation}: {navigation: any}) {
  const [questions, setQuestions] = useState<Question[]>([]);
  const [currentQuestion, setCurrentQuestion] = useState(0);
  const [options, setOptions] = useState<string[]>([]);
  const [score, setScore] = useState(0);
  const [answered, setAnswered] = useState(false);
  const [loading, setLoading] = useState(true);
  const [selectedOption, setSelectedOption] = useState<string | null>(null);
  const [isCorrect, setIsCorrect] = useState<boolean | null>(null);

  const route = useRoute(); // Get the route object

  useEffect(() => {
    getQuiz();
  }, []);

  const getQuiz = async () => {
    try {
      setLoading(true);
      const routeParams = route.params as {difficulty?: string};
      const difficulty = routeParams?.difficulty;
      if (difficulty) {
        const quizData = await fetchQuizData(difficulty);
        setQuestions(quizData);
      } else {
        console.error('Difficulty not provided.');
      }
      setLoading(false);
    } catch (error) {
      console.error('Error fetching quiz data:', error);
      setLoading(false);
    }
  };

  const generateOptionsAndShuffle = () => {
    if (questions.length > 0) {
      let _options = [
        ...questions[currentQuestion].incorrect_answers,
        questions[currentQuestion].correct_answer,
      ];
      shuffleArray(_options);
      setOptions(_options);
    }
  };

  const handleOptionSelection = (option: string) => {
    if (!answered) {
      const isOptionCorrect =
        option === questions[currentQuestion].correct_answer;
      setSelectedOption(option);
      setIsCorrect(isOptionCorrect);

      if (!isOptionCorrect) {
        Vibration.vibrate(500);
      }

      handleSelectedOption(
        option,
        answered,
        setAnswered,
        questions,
        currentQuestion,
        setCurrentQuestion,
        setScore,
        score,
        navigation,
      );
    }
  };

  useEffect(() => {
    generateOptionsAndShuffle();
  }, [currentQuestion]);

  const moveToNextQuestion = () => {
    if (currentQuestion < questions.length - 1) {
      setCurrentQuestion(currentQuestion + 1);
      setAnswered(false);
    } else if (questions.length === 0) {
      console.error('No questions found.');
      navigation.navigate('Home');
    } else {
      navigation.navigate('Results', {score: score});
    }
  };

  useEffect(() => {
    generateOptionsAndShuffle();
  }, [questions]);

  return (
    <View style={styles.container}>
      <TouchableOpacity
        onPress={() => {
          navigation.navigate('Home');
        }}>
        <Text style={styles.backButton}>&#8592;</Text>
      </TouchableOpacity>

      {loading ? (
        <View style={styles.loadingContainer}>
          <LottieView
            style={{
              width: 300,
              height: 300,
            }}
            source={require('../assets/loading.json')}
            autoPlay
            loop
          />
          <Text style={{fontSize: 13, color: '#000'}}>
            Loading... Please wait a moment
          </Text>
        </View>
      ) : questions.length > 0 ? (
        <View style={styles.parent}>
          {/* Display the current question number and total questions */}
          <View style={styles.questionCount}>
            <Text style={styles.questionCountText}>
              Q:{currentQuestion + 1} of {questions.length}
            </Text>
          </View>

          <View style={styles.top}>
            <Text style={styles.question}>
              {decodeURIComponent(questions[currentQuestion].question)}
            </Text>
          </View>

          <View style={styles.options}>
            {options.map((option, index) => (
              <TouchableOpacity
                onPress={() => handleOptionSelection(option)}
                key={index}
                style={[
                  styles.optionButton,
                  selectedOption === option && {
                    backgroundColor: isCorrect ? '#03C988' : 'red',
                  },
                ]}
                disabled={answered}>
                <Text style={styles.option}>{decodeURIComponent(option)}</Text>
              </TouchableOpacity>
            ))}
          </View>
          <View style={styles.bottom}>
            <View style={styles.nextButtonContainer}>
              <TouchableOpacity
                style={styles.button}
                onPress={moveToNextQuestion}
                disabled={answered}>
                <Text style={styles.buttonText}>Next</Text>
              </TouchableOpacity>
            </View>
          </View>
        </View>
      ) : (
        <View style={styles.noQuestionsContainer}>
          <LottieView
            style={{
              width: 200,
              height: 200,
            }}
            source={require('../assets/notfound.json')}
            autoPlay
            loop
          />
          <Text style={styles.noQuestionsText}>
            No questions available 😞,Please check your internet connection.
          </Text>
          <TouchableOpacity onPress={getQuiz}>
            <Text
              style={{
                fontSize: 20,
                color: '#000',
                textAlign: 'center',
                marginTop: 40,
                marginBottom: 20,
              }}>
              Refresh 🔃
            </Text>
          </TouchableOpacity>
        </View>
      )}
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    paddingTop: 40,
    paddingHorizontal: 20,
    height: '100%',
  },
  backButton: {
    fontSize: 20,
    color: '#000',
    textAlign: 'left',
    marginTop: 10,
    marginBottom: 20,
  },
  loadingContainer: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
  },
  parent: {
    height: '100%',
  },
  questionCount: {
    backgroundColor: '#1A759F',
    borderTopRightRadius: 16,
    borderBottomRightRadius: 16,
    paddingHorizontal: 12,
    paddingVertical: 6,
    alignSelf: 'flex-start',
    marginBottom: 4,
  },
  questionCountText: {
    fontSize: 16,
    color: 'white',
    fontWeight: 'bold',
  },
  top: {
    marginVertical: 16,
  },
  options: {
    marginVertical: 16,
    flex: 1,
  },
  bottom: {
    marginBottom: 20,
    paddingVertical: 16,
    justifyContent: 'space-between',
    flexDirection: 'row',
    alignItems: 'center',
  },
  button: {
    backgroundColor: '#1A759F',
    padding: 12,
    paddingHorizontal: 16,
    borderRadius: 16,
    alignItems: 'center',
    marginBottom: 45,
  },
  buttonText: {
    fontSize: 18,
    fontWeight: '600',
    color: 'white',
  },
  question: {
    fontSize: 22,
    color: '#000',
    textAlign: 'justify',
    letterSpacing: -1,
  },
  option: {
    fontSize: 18,
    color: 'white',
    fontWeight: '400',
  },
  optionButton: {
    paddingVertical: 12,
    marginVertical: 6,
    backgroundColor: '#1A759F',
    paddingHorizontal: 12,
    borderRadius: 12,
  },
  noQuestionsContainer: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
  },
  noQuestionsText: {
    fontSize: 15,
    textAlign: 'center',
    color: '#000',
  },
  nextButtonContainer: {
    position: 'absolute',
    bottom: 0,
    right: 0,
    marginBottom: 45,
    marginRight: 20,
  },
});
