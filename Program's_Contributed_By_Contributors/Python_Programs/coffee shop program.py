class Coffee:
        # Constructor
        def __init__(self, name, price):
                self.name = name
                self.price = float(price)
        def check_budget(self, budget):
                # Check if the budget is valid
                if not isinstance(budget, (int, float)):
                        print('Enter float or int')
                        exit()
                if budget < 0: 
                    print('Sorry you don\'t have money') 
                    exit() 
        def get_change(self, budget):
                return budget - self.price
        
        def sell(self, budget):
                self.check_budget(budget)
                if budget >= self.price:
                        print(f'You can buy the {self.name} coffee')
                        if budget == self.price:
                                print('It\'s complete')
                        else:
                                print(f'Here is your change {self.get_change(budget)}$')

                        exit('Thanks for your transaction')
