const twoSum = (array, target) => {
     const hastable = {};
     for ( let i = 0; i < array.length; i++) {
        let complement = target - array[i];
       
        if ( hashtable.hasOwnProperty(complement)){
          return [hashtable[complement], i]
        }
 
        hashtable[array[i]] = i;   
     };
     
     return null;
};
