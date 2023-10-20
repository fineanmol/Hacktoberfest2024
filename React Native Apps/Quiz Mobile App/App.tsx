import React from 'react';
import {NavigationContainer} from '@react-navigation/native';
import {createNativeStackNavigator} from '@react-navigation/native-stack';
import Home from './screens/Home';
import Quiz from './screens/Quiz';
import Results from './screens/Results';

const Stack = createNativeStackNavigator();

export default function App() {
  return (
    <NavigationContainer>
      <Stack.Navigator>
        <Stack.Screen
          name="Home"
          component={Home}
          options={{headerShown: false}}
        />
        <Stack.Screen
          name="Quiz"
          component={Quiz}
          options={{headerShown: false}}
        />
        <Stack.Screen
          name="Results"
          component={Results}
          options={{headerShown: false}}
        />
      </Stack.Navigator>
    </NavigationContainer>
  );
}

// const styles = StyleSheet.create({
//   container: {
//     paddingTop: 40,
//     paddingHorizontal: 16,
//   },
// });
