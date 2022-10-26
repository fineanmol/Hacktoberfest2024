operacao = input("Digite a operacao desejada (soma, sub, mult, div): ")
numero1 = input("Digite o primeiro número: ")
numero2 = input("Digite o segundo número: ")

if operacao == "soma":
	resultado = int(numero1) + int(numero2)
if operacao == "sub":
	resultado = int(numero1) - int(numero2)
if operacao == "mult":
	resultado = int(numero1) * int(numero2)
if operacao == "div":
	resultado = int(numero1) / int(numero2)
else:
	resultado = "Operação não suportada"
    
print("O resultado da operação é: " + str(resultado))
