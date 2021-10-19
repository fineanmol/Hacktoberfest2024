import React from 'react';
import { StyleSheet, Text, View } from 'react-native';
import { NavigationContainer } from '@react-navigation/native';
import { createStackNavigator } from '@react-navigation/stack';
import chooseLanguage from './screens/chooseLanguage';
import phoneNumberEng from './screens/phoneNumberEng';
import phoneNumberHindi from './screens/phoneNumberHindi';
import welcomePage from './screens/welcomePage';
import LottieView from 'lottie-react-native';

const myStack = createStackNavigator();

class App extends React.Component {
  render() {
    return (
      <NavigationContainer>
        <myStack.Navigator
          screenOptions={{
            headerShown: false
          }}
        >
          <myStack.Screen
            name='welcomePage'
            component={welcomePage}
          />
          <myStack.Screen
            name='chooseLanguage'
            component={chooseLanguage}
          />
          <myStack.Screen
            name='phoneNumberHindi'
            component={phoneNumberHindi}
          />
          <myStack.Screen
            name='phoneNumberEng'
            component={phoneNumberEng}
          />

        </myStack.Navigator>
      </NavigationContainer>
    );
  }
};

const styles = StyleSheet.create({
  mainView:{
    flex:1,
    alignItems:'center',
    justifyContent:'center',
    backgroundColor:'#ffe066',
  },
});

export default App;
