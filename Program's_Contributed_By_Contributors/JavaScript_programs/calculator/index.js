const display = document.querySelector('.display')

const calculator = {
    displayArray: []
}

const isOperator = i => i === '%' || i === 'X' || i === '/' || i === '+' || i === '-' ? true : false
const isFunc = i => i === 'C' || i === 'AC' ? true : false
const emptyElementsAtEnd = (a, b) => a === undefined ? -1 : 0


/* Configuration */

function numberSetOnClick() {
    const inputNumber = document.querySelectorAll('.number')
    inputNumber.forEach( numKey => {
        numKey.onclick = () => {
            numberHandler(numKey.innerHTML)
        }
        numKey.onmousedown = () => numKey.style['box-shadow'] = 'none'
        numKey.onmouseup = () => numKey.style['box-shadow'] = '5px 5px 15px 1px #333'
    })
}

function funcSetOnClick() {
    const inputFunction = document.querySelectorAll('.func')
    inputFunction.forEach( func => {
        func.onclick = () => {
            funcHandler(func.innerHTML)
        }
        func.onmousedown = () => func.style['box-shadow'] = 'none'
        func.onmouseup = () => func.style['box-shadow'] = '5px 5px 15px 1px #333'
    })
}

function operationSetOnClick() {
    const inputOperation = document.querySelectorAll('.operation')
    inputOperation.forEach( op => {
        op.onclick = () => {
            operationHandler(op.innerHTML)
        }
        op.onmousedown = () => op.style['box-shadow'] = 'none'
        op.onmouseup = () => op.style['box-shadow'] = '5px 5px 15px 1px rgb(51, 51, 51, 0.5)'
    })
}

function keySetOnPress() {
    const keyboardKeys= [...document.querySelector('.keyboard').children]
    document.onkeydown = event => {
        let key = event.key
        if(key === '*') key = 'X'
        if(key === 'Enter') key = '='

        if(!isNaN(key) || key === '.') {
            numberHandler(key)
        } else if(isFunc(key)) {
            funcHandler(key)
        } else if(isOperator(key) || key === '=' || key === 'Enter') {
            operationHandler(key)
        }

        keyboardKeys.forEach( el => {
            if(el.innerHTML === key) {
                el.style['box-shadow'] = 'none'
            }
        })
    }

    document.onkeyup = event => {
        let key = event.key
        if(key === '*') key = 'X'
        if(key === 'Enter') key = '='
        keyboardKeys.forEach( el => {
            if(el.innerHTML === key) {
                if(isOperator(key) || key === '=' || key === 'Enter') {
                    el.style['box-shadow'] = '5px 5px 15px 1px rgb(51, 51, 51, 0.5)'
                } else {
                    el.style['box-shadow'] = '5px 5px 15px 1px #333'
                } 
            }
        })
    }
}

/* View */

function funcHandler(type) {
    if(type === 'AC') resetCalculator()
    else displayThis('')
}

function resetCalculator() {
    calculator.displayArray = []
    displayThis('')
}

function displayThis(value) {
    display.innerHTML = `${value}`
}

function resetAndDisplay(value) {
    calculator.displayArray = [value]
    displayThis(value)
}

function updateDisplay() {
    const toBeDisplayed = calculator.displayArray.reduce((prev, curr) => prev.concat(curr), '')
    display.innerHTML = toBeDisplayed
}

/* Logic */

function numberHandler(num) {
    calculator.displayArray.push(num)
    updateDisplay()
}

function operationHandler(operation) {
    const arr = calculator.displayArray
    if(operation !== '=' && operation !== '%') {
        const lastIndex = arr.length-2
        if(isOperator(arr[lastIndex])) {
            arr[lastIndex] = operation
        } else {
            arr.push(' ')
            arr.push(operation)
            arr.push(' ')
        }
        updateDisplay()
    } else if(operation === '%') {
        const percentage = calculatePercentage(arr)
        updateDisplay()
    } else {
        calculate()
    }
}

function calculate() {
    let stringArray = calculator.displayArray.toString()
    stringArray = stringArray.replaceAll(',', '')
    const arrayToCalculate = stringArray.split(' ')
    try {
        const result = calcRecursive(arrayToCalculate)
        if(isNaN(result)) {
            resetCalculator()
            displayThis('Error!')
        } else {
            resetAndDisplay(result)
        }
    } catch (error) {
        displayThis('Error!')   
    }
}

function calcRecursive(arr) {
    do {
        if(arr.includes('/') || arr.includes('X')) {
            calculateDivisionAndMultiplication(arr)
        } else if(arr.includes('+') || arr.includes('-')) {
            calculatePlusAndMinus(arr)
        }
    } while(arr.length > 1)
    return arr[0]
}

function calculateDivisionAndMultiplication(arr) {
    if (arr.includes('/')) {
        calculateDivision(arr)
    } else {
        calculateMultiplication(arr)
    }
}

function calculatePlusAndMinus(arr) {
    if (arr.includes('+')) {
        calculatePlus(arr)
    } else {
        calculateMinus(arr)
    }
}

function calculateDivision(arr) {
    let opPosition = arr.indexOf('/')
    if (opPosition) {
        const value = arr[opPosition-1] / arr[opPosition+1]
        arr[opPosition-1] = value
        removeEmptySpacesArray(arr, opPosition)
    }
}

function calculateMultiplication(arr) {
    let opPosition = arr.indexOf('X')
    if (opPosition) {
        const value = arr[opPosition-1] * arr[opPosition+1]
        arr[opPosition-1] = value
        removeEmptySpacesArray(arr, opPosition)
    }
}

function calculatePlus(arr) {
    let opPosition = arr.indexOf('+')
    if (opPosition) {
        const value = parseInt(arr[opPosition-1], 10) + parseInt(arr[opPosition+1], 10)
        arr[opPosition-1] = value
        removeEmptySpacesArray(arr, opPosition)
    }
}

function calculateMinus(arr) {
    let opPosition = arr.indexOf('-')
    if (opPosition) {
        const value = arr[opPosition-1] - arr[opPosition+1]
        arr[opPosition-1] = value
        removeEmptySpacesArray(arr, opPosition)
    }
}

function removeEmptySpacesArray(arr, opPosition) {
        delete arr[opPosition]
        delete arr[opPosition+1]
        arr = arr.sort(emptyElementsAtEnd)
        arr.pop()
        arr.pop()
}

function calculatePercentage(arr) {
    if(arr.length > 0) {
        let stringArray = arr.toString()
        stringArray = stringArray.replaceAll(',', '')
        const arrayToCalculate = stringArray.split(' ')

        const value = arrayToCalculate[arrayToCalculate.length-1] / 100
        for(let i = 0; i < arrayToCalculate[arrayToCalculate.length-1].length; i++) {
            arr.pop()
        }
        const stringValue = value.toString()
        const valueArray = [...stringValue]
        valueArray.forEach( char => {
            arr.push(char)
        })
    }
}


function main() {
    numberSetOnClick()
    funcSetOnClick()
    operationSetOnClick()
    keySetOnPress()
}

main()