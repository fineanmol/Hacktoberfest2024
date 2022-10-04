#PESQUISA SEQUENCIAL

l= [15, 10 ,599, 3, 4, 68, 33, 22, 32, 55] #lista de valores

s= int(input("Digite o valor de busca: "))

ok= False

x=0
while x < len(l):
    if l[x] == s:
        ok = True
        break
    x += 1
if ok:
    print(f"{s} encontrado na posição {x}")
else:
    print(f"{s} não encontrado")