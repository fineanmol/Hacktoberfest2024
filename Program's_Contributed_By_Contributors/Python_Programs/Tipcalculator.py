# Function to calculate the tip
def tip_calc(tip_perc, bill):
    return tip_perc * bill / 100

# Function to execute the tip calculation logic
def calculate_tip():
    try:
        tip_percentage = float(input("Enter the tip percentage: "))
        bill_amount = float(input("Enter the amount of the bill: "))
        
        if tip_percentage < 0 or bill_amount < 0:
            raise ValueError("Please enter positive values.")

        tip_amount = tip_calc(tip_percentage, bill_amount)
        total_amount = bill_amount + tip_amount

        # Display the results using descriptive sentences without formatting
        print("The calculated tip is: " + str(tip_amount) + " rupees.")
        print("The total amount to be paid, including the tip, is: " + str(total_amount) + " rupees.")
    except ValueError as e:
        print("Input Error: " + str(e))

# Start the tip calculation process
calculate_tip()



