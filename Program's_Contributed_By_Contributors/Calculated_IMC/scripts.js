const inputHeight = document.getElementById('input-height')

const inputWeight = document.getElementById('input-weight')

const txtResult = document.getElementById('txt-result')

const btnClear =  document.getElementById('btn-clear');

const btnCalculator =  document.getElementById('btn-calculator');

btnClear.addEventListener('click', function (){
  inputHeight.value = '';
  inputWeight.value = '';
  txtResult.innerText = ''
})

btnCalculator.addEventListener('click', function (){
  let height = Number(inputHeight.value);
  let weight = Number(inputWeight.value);
  
  const result = weight / Math.pow(height,2);

  let categorie = BMICategories(result)

  txtResult.innerText = `${result.toFixed(2)} -  ${categorie}`
})

function BMICategories(weight){
  if(weight < 18.5) return 'Underweight '

  if(weight >= 18.5 && weight < 24.9) return 'Normal weight '

  if(weight >= 25 && weight < 29.9) return 'Overweight'

  return 'Obesity' 
}