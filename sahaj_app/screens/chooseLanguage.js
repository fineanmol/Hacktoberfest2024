import { NavigationContainer } from '@react-navigation/native';
import React from 'react';
import { StyleSheet, Text, View, Dimensions, Pressable,} from 'react-native';
import { Card } from 'react-native-shadow-cards';

var height = Dimensions.get('window').height;
var width = Dimensions.get('window').width;

class chooseLanguage extends React.Component {
  render() {
    return (
      <View style={styles.mainView}>
        <Text style={{ fontFamily: 'TitilliumWeb-Light', color: '#993333', fontSize: 25, marginBottom: 30, color: 'red' }}>Choose Language</Text>
        <Pressable onPress={() => this.props.navigation.navigate('phoneNumberEng')}>
        <Card style={styles.englishCard}>
          <Text style={{ fontFamily: 'TitilliumWeb-Light', color: 'red', fontSize: 14, }}>English</Text>
        </Card>
        </Pressable>
        <Pressable onPress={() => this.props.navigation.navigate('phoneNumberHindi')}>
        <Card style={styles.hindiCard}>
          <Text style={{ fontFamily: 'Arjun Normal', color: 'red', fontSize: 16 }}>fganh</Text>
        </Card>
        </Pressable>
      </View>
    );
  }
};


const styles = StyleSheet.create({
  mainView: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  englishCard: {
    height: height / 13,
    width: width / 2,
    backgroundColor: 'white',
    marginBottom: 20,
    alignItems: 'center',
    justifyContent: 'center',
  },
  hindiCard: {
    height: height / 13,
    width: width / 2,
    backgroundColor: 'white',
    marginBottom: 20,
    alignItems: 'center',
    justifyContent: 'center',
    paddingTop: 10,
  },
});

export default chooseLanguage;
