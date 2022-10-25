placar = str(input()).upper()
aposta = str(input()).upper()

pontos = 0

timeA = placar.split("X")
timeB = aposta.split("X")


if(int(timeA[0]) >= int(timeA[1]) and int(timeB[0]) >= int(timeB[1]) or int(timeA[1]) >= int(timeA[0]) and int(timeB[1]) >= int(timeB[0])):
  pontos += 2

  if(int(timeA[0]) == int(timeB[0]) or int(timeA[1]) == int(timeB[1])):
    pontos += 1

  if(int(timeA[0]) == int(timeB[0]) and int(timeA[1]) == int(timeB[1]) or int(timeA[1]) == int(timeB[1]) and int(timeA[0]) == int(timeB[0])):
    pontos += 3


print(pontos)