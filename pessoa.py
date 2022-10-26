class Pessoa:
    def __init__(self, nome, peso, idade, comendo = False, dormindo=False , falando=False):
        self.nome = nome
        self.peso=peso
        self.idade=idade
        self.comendo=comendo
        self.dormindo=dormindo
        self.falando=falando
#Começou a comer
    def comer(self):

        if self.dormindo == True or self.comendo == True or self.falando == True:
            print(f'Ele não pode comer, pois está dormindo, falando ou comendo.')

#Foi comer
        else:
            print(f'{self.nome} Ele foi comer.')



    def parar_de_comer(self):
        if self.comendo == True:
            print(f'{self.nome} Parou de comer')
            self.comendo = True

        else:
            print(f' {self.nome} Não pode parar de comer pois já está comendo')



    def dormir(self):
        if self.dormindo == True:
            print(f'{self.nome} está dormindo')

        else:
            self.dormindo = True
            print(f'{self.nome} está indo dormir')


    def parar_de_dormir(self):
        if self.dormindo == False:
            print(f'{self.nome} não está dormindo no momento')

        else:
            self.dormindo = False
            print(f'{self.nome} parou de dormir')



    def falar(self):
        if self.falando == True or self.dormindo == True or self.comendo== True:
            print("sara não pode falar porque está falando, dormindo ou comendo ")

        else:
            print("Sara está falando")
