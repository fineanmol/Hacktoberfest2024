import React from 'react';
import {StyleSheet,Text,View,Dimensions,TextInput} from 'react-native';
import {Card} from 'react-native-shadow-cards';

var height = Dimensions.get('window').height;
var width = Dimensions.get('window').width;

class phoneNumberEng extends React.Component{
    render(){
     return(
        <View style={styles.mainView}>
            <Text style={{fontFamily:'TitilliumWeb-Light',color:'#993333',fontSize:24,marginBottom:30,color:'red'}}>Your Phone Number</Text>
            <Card style={styles.phoneCard}>
                <Text style={{color:'red',fontWeight:'300'}}>+91</Text>
                <TextInput
                    style={styles.input}
                    placeholder="enter phone no."
                    placeholderTextColor='#ff6666'
                    keyboardType="numeric"
                    selectionColor='red'
                />
            </Card>
        </View>
     );
    }
}

const styles = StyleSheet.create({
    mainView:{
      flex:1,
      alignItems:'center',
      justifyContent:'center',
    },
    phoneCard:{
        height:height/13,
        width:width/2,
        backgroundColor:'white',
        marginBottom:20,
        alignItems:'center',
        justifyContent:'flex-start',
        padding:10,
        flexDirection:'row',
      },
      input: {
        height: 40,
        margin: 12,
        padding: 10,
        fontWeight:'300',
        color:'red'
      },
  });

export default phoneNumberEng;