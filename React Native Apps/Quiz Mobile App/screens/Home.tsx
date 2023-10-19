import React, {useState} from 'react';
import {
  StyleSheet,
  Text,
  View,
  Image,
  TouchableOpacity,
  Alert,
} from 'react-native';
import Title from '../components/Title';
import LottieView from 'lottie-react-native';
import {NavigationProp} from '@react-navigation/native';

export default function Home({navigation}: {navigation: NavigationProp<any>}) {
  const [selectedDifficulty, setSelectedDifficulty] = useState<string | null>(
    null,
  );

  const handleStartQuiz = () => {
    if (selectedDifficulty) {
      navigation.navigate('Quiz', {difficulty: selectedDifficulty});
    } else {
      Alert.alert('Please select a difficulty level');
    }
  };

  return (
    <View style={styles.container}>
      <Title title="Brain Teaser" />
      <View style={styles.bannerContainer}>
        <LottieView
          style={{
            width: 300,
            height: 300,
          }}
          source={require('../assets/question.json')}
          autoPlay
          loop
        />
        <Text style={styles.dificultyText}>
          Please select a difficulty level:{' '}
        </Text>
      </View>
      <View style={styles.difficultyButtons}>
        <TouchableOpacity
          style={[
            styles.button,
            selectedDifficulty === 'easy' && styles.selectedButton,
          ]}
          onPress={() => setSelectedDifficulty('easy')}>
          <Text style={styles.buttonText}>Easy</Text>
        </TouchableOpacity>
        <TouchableOpacity
          style={[
            styles.button,
            selectedDifficulty === 'medium' && styles.selectedButton,
          ]}
          onPress={() => setSelectedDifficulty('medium')}>
          <Text style={styles.buttonText}>Medium</Text>
        </TouchableOpacity>
        <TouchableOpacity
          style={[
            styles.button,
            selectedDifficulty === 'hard' && styles.selectedButton,
          ]}
          onPress={() => setSelectedDifficulty('hard')}>
          <Text style={styles.buttonText}>Hard</Text>
        </TouchableOpacity>
      </View>
      <TouchableOpacity style={styles.startButton} onPress={handleStartQuiz}>
        <Text style={styles.startButtonText}>Start!</Text>
      </TouchableOpacity>
    </View>
  );
}

const styles = StyleSheet.create({
  banner: {
    height: 300,
    width: 300,
  },
  bannerContainer: {
    alignItems: 'center',
    justifyContent: 'center',
    flex: 1,
  },
  container: {
    paddingTop: 40,
    paddingHorizontal: 20,
    height: '100%',
  },
  difficultyButtons: {
    flexDirection: 'row',
    justifyContent: 'space-between',
    marginBottom: 20,
  },
  button: {
    flex: 1,
    alignItems: 'center',
    backgroundColor: '#1A759F',
    padding: 10,
    borderRadius: 16,
    marginRight: 10,
  },
  selectedButton: {
    backgroundColor: '#03C988',
  },
  buttonText: {
    color: 'white',
    fontSize: 15,
    fontWeight: '600',
  },
  startButton: {
    width: '100%',
    alignItems: 'center',
    backgroundColor: '#1A759F',
    padding: 16,
    borderRadius: 16,
    marginBottom: 30,
  },
  startButtonText: {
    color: 'white',
    fontSize: 24,
    fontWeight: '600',
  },
  dificultyText: {
    fontSize: 20,
    fontWeight: '300',
    color: '#000',
    textAlign: 'center',
    marginTop: 15,
    marginBottom: 50,
  },
});
