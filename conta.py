class Conta_banco:
    def __init__(self, numero_conta,nome_cliente, tipo_conta, saldo=0,status_conta=False, limite=0):
        self.numero_conta= numero_conta
        self.saldo=saldo
        self.status_conta=status_conta
        self.nome_cliente=nome_cliente
        self.tipo_conta=tipo_conta
        self.limite=limite

    def depositar (self, valor):
        if self.status_conta == True:
                self.saldo= self.saldo + valor
                print(f'{self.nome_cliente} Seu depósito foi efetuado')
        else:
                print("Impossivel fazer deposito, conta inativa")

    def sacar(self, saque):
        if self.status_conta == True:
                if saque< self.saldo:
                    self.saldo= self.saldo - saque
                    print("Seu saque foi efetuado")
                else:
                     print("impossivel sacar, conta inativa")

    def ativar_conta(self):
        if self.status_conta == True:
            print("Impossivel ativar pois já está ativada")

        else:
            self.status_conta= True
            print("Conta ativada com sucesso!")

    def VerificarSaldo(self):
        if self.status_conta == True:
            print(f"Voce tem dinheiro :) {self.saldo}")

        else:
            print(f"Negativado!")
