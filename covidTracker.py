                                        #Code To Track The Covid19 Using Python

for i in range(0,100):
    print(" ")
    # importing covid module
    from covid import Covid
    print("Covid Tracker")
    cv = Covid()


    active = cv.get_total_active_cases()
    recovered = cv.get_total_recovered()
    death = cv.get_total_deaths()
    confirmed = cv.get_total_confirmed_cases()
    print("1) World Count")
    print("2) Active Cases")
    print("3) Confirmed Cases")
    print("4) Recovered Cases")
    print("5) Decreased")
    print("6) Get Covid Updates By country names")


    choice = input("Enter the number of your choice :")

    if choice == '1':
        print("Active Cases :",active,"\nConfirmed Cases :",confirmed,"\nRecovered Cases :",recovered,"\nDecreased :",death)
    elif choice == '2':
        print("Active Cases: ",active)
    elif choice == '3':
        print("Confirmed Cases :",confirmed)
    elif choice == '4':
        print("Recovered Cases :",recovered)
    elif choice == '5':
        print("Decreases: ",death)
    elif choice == '6':
        str = i =  input("Enter the Country Name : ")
        cname = cv.get_status_by_country_name(i)
        print(cname)
    else:
        print("Invalid Input")
