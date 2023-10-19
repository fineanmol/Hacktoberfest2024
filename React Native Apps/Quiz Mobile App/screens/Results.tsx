import {StyleSheet, Text, View, TouchableOpacity} from 'react-native';
import React from 'react';
import {useRoute} from '@react-navigation/native';
import Title from '../components/Title';
import LottieView from 'lottie-react-native';

export default function Results({navigation}: {navigation: any}) {
  // Access the params object
  const params = useRoute().params as {score: number}; // Use type assertion

  // Extract the score from the params object
  const score = params?.score || 0;

  // Define the animation source based on the score
  let animationSource = require('../assets/sadblue.json'); // Default to sad animation

  if (score >= 50) {
    animationSource = require('../assets/price.json'); // Use price animation if score is 50 or above
  }

  return (
    <View style={styles.container}>
      <TouchableOpacity
        onPress={() => {
          navigation.navigate('Home');
        }}>
        {/* adding back btn html icon */}
        <Text style={styles.backButton}>&#8592;</Text>
      </TouchableOpacity>
      <Title title="Results" />
      <View style={styles.bannerContainer}>
        <LottieView
          style={{
            width: 300,
            height: 300,
          }}
          source={animationSource} // Use the determined animation source
          autoPlay
          loop
        />
        <View>
          {/* Display the score using a Text component */}
          <Text style={styles.scoreText}>Total Score: {score}</Text>
        </View>
      </View>
      <TouchableOpacity
        style={styles.button}
        onPress={() => {
          navigation.navigate('Home');
        }}>
        <Text style={styles.buttonText}>Home</Text>
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
  button: {
    width: '100%',
    alignItems: 'center',
    backgroundColor: '#1A759F',
    padding: 16,
    borderRadius: 16,
    marginBottom: 30,
  },
  buttonText: {
    color: 'white',
    fontSize: 24,
    fontWeight: '600',
  },
  scoreText: {
    fontSize: 24,
    fontWeight: '600',
    marginBottom: 20,
    color: '#000',
  },
  backButton: {
    fontSize: 20,
    color: '#000',
    textAlign: 'left',
  },
});
