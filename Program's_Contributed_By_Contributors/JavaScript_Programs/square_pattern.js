function box(params) {
    let result = '';
    for (let i = 0; i < params; i++) {
        for (let j = 0; j < params; j++) {
            result += '* ';
        }
        result += '\n';
    }
    return result;
}
console.log(box(10));