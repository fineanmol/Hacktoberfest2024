class capitalizeFirstLetter {

    static capitalizeFirstLetter(value) {
        return value.replace(/(\b\w)/gi,function(m){return m.toUpperCase()})
    }
    
}

module.exports = capitalizeFirstLetter;
