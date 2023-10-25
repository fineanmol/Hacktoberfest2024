MENU = {
    "espresso": {
        "ingredients": {
            "water": 50,
            "coffee": 18,
        },
        "cost": 1.5,
    },
    "latte": {
        "ingredients": {
            "water": 200,
            "milk": 150,
            "coffee": 24,
        },
        "cost": 2.5,
    },
    "cappuccino": {
        "ingredients": {
            "water": 250,
            "milk": 100,
            "coffee": 24,
        },
        "cost": 3.0,
    }
}
profit = 0
resources = {
    "water": 300,
    "milk": 200,
    "coffee": 100,
}

def is_resource_sufficient(order_ingredients):
    for item in order_ingredients:
        if order_ingredients[item] >= resources[item]:
            print(f"Sorry there is no enough {item}")
            return False
    return True

def process_coins():
    """"Return total calculated from coins inserted"""
    print("Please insert coins")
    total = int(input("How many quarters?: ")) * 0.25
    total += int(input("How many dime?: ")) * 0.1
    total += int(input("How many nickels?: ")) * 0.05
    total += int(input("How many pennies?: ")) * 0.01
    return total


def is_transaction_succesful(money_recieved,cost_of_drink):
    """"return true when enough money is given"""
    if money_recieved > cost_of_drink:
        change = round(money_recieved - cost_of_drink,2)
        print(f"Here is {change} these much money as change")

        global profit
        profit += cost_of_drink
        return True
    else:
        print("Sorry thats not enough money,Money refunded")
        return False


def make_coffee(drink_name,order_ingrediants):
    for item in order_ingrediants:
        resources[item] -= order_ingrediants[item]
        print(f"here is your {drink_name} ☕ . enjoy !")


is_on = True

while is_on:
    choice = input("what would you like? (espresso/latte/cappuccino)")
    if choice == "off":
        is_on = False
    elif choice == "report":
        print(f"water : {resources['water'] }ml")
        print(f"milk : {resources['milk'] }ml")
        print(f"coffee : {resources['coffee'] }g")
        print(f"Money : {profit}$")
    else:
        drink = MENU[choice]
        if is_resource_sufficient(drink["ingredients"]):
            payment = process_coins()
            if is_transaction_succesful(payment,drink["cost"]):
                make_coffee(choice,drink["ingredients"])
