import React from 'react';
import {StyleSheet,Text,View,Dimensions,TextInput, Pressable} from 'react-native';
import LottieView from 'lottie-react-native';
import {Card} from 'react-native-shadow-cards';

var height = Dimensions.get('window').height;
var width = Dimensions.get('window').width;

class welcomePage extends React.Component{
    render(){
     return(
         <View style={styles.mainView}>
             <View style={{height:150,width:400}}>
             <LottieView
                source={require('../assets/38613-namaste.json')}
                autoPlay
                loop
             />
          </View>
          <Pressable onPress={() => this.props.navigation.navigate('chooseLanguage')}>
              <Card style={styles.cardStyle}>
              <Text style={styles.textStyle}>Let's Start</Text>
              </Card>
          </Pressable>
         </View>
     );
    }
}


    const styles = StyleSheet.create({
        mainView:{
            flex:1,
            alignItems:'center',
            justifyContent:'center',
            backgroundColor:'#ffe066',
          },
          cardStyle:{
              height:height/21,
              width:width/5,
              backgroundColor:'white',
              marginTop:80,
              borderRadius:15,
              borderColor:'red',
              borderWidth:1.5,  
              alignItems:'center',
              justifyContent:'center',
          },
          textStyle:{
            fontSize:10,
            color:'red',
            fontFamily:'TitilliumWeb-Light',
          },

      });
    
    export default welcomePage;