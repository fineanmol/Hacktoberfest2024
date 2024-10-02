package main

import (
	"fmt"
	"os"
	"os/exec"
	"runtime"
)

var clear map[string]func() //create a map for storing clear funcs
var username [5]string
var balance [5]float32
var house [5] int
var hotels [5] int
var value [5] float32
var choice int

func init() {
	clear = make(map[string]func()) //Initialize it
	clear["linux"] = func() {
		cmd := exec.Command("clear") //Linux example, its tested
		cmd.Stdout = os.Stdout
		cmd.Run()
	}
	clear["windows"] = func() {
		cmd := exec.Command("cmd", "/c", "cls") //Windows example, its tested
		cmd.Stdout = os.Stdout
		cmd.Run()
	}
}

func CallClear() {
	value, ok := clear[runtime.GOOS] //runtime.GOOS -> linux, windows, darwin etc.
	if ok {                          //if we defined a clear func for that platform:
		value() //we execute it
	} else { //unsupported platform
		panic("Your platform is unsupported! I can't clear terminal screen :(")
	}
}

func Startup() {
	for count := 1; count <= 4; count++ {
		fmt.Print("Enter the ")
		fmt.Print(count)
		fmt.Println(" Name :")
		fmt.Scanln(&username[count])
		CallClear()
	}
	for count := 1; count <= 4; count++ {
		balance[count] = 1500
	}

}

func PrintBalance() {
	fmt.Println("No.        Name             Balance           House          Hotels          Value")
	fmt.Println("           ")
	for count := 1; count <= 4; count++ {
		fmt.Println("______________________________________________________________________________________________")
		fmt.Println("             ")
		fmt.Print(count)
		fmt.Print("          ")
		fmt.Print(username[count])
		fmt.Print("              ")
		fmt.Print(balance[count])
		fmt.Print("              ")
		fmt.Print(house[count])
		fmt.Print("              ")
		fmt.Print(hotels[count])
		fmt.Print("              ")
		fmt.Print(value[count])
		fmt.Println("              ")
	}
		fmt.Println("______________________________________________________________________________________________")
}

func PrintMenu() {
	fmt.Println("                           ")
	fmt.Println(" Which operation you wanna perform?")
	fmt.Println("                 _______________________________________________________")
	fmt.Println("                           ")
	fmt.Println("               1. Inc/Dec  balance                 5. Birthday Party")
	fmt.Println("                           ")
	fmt.Println("               2. Manage houses                    6. Salaray or gifts")
	fmt.Println("                           ")
	fmt.Println("               3. Transfer Balance                 7. Taxes and fine")
	fmt.Println("                           ")
	fmt.Println("               4. Increase 10%                     8. House repair")
	fmt.Println("                           ")
	fmt.Println("                 _________________________________________________________")
	fmt.Println("                           ")
	//fmt.Println(" 4. It is some one birthday")

	fmt.Scanln(&choice)

}

func PerformAction() {

	switch choice {
	case 1:
		BankTrans()
	case 2:
		Houses()
	case 3:
		NormTrans()
	case 4:
		Inc10()
	case 5:
		BirthDay()
	case 6:
		General(1)
	case 7:
		General(2)
        case 8:
		Repairs()
	default:
		fmt.Println("try again")
		fmt.Scanln()
	}
}

func BankTrans() {
	var amount float32
        var act int
	fmt.Println("                         Increase or decrease")
	fmt.Println("                         _________________________________")
	fmt.Println("                           ")
	fmt.Scanln(&act)
	fmt.Println("                              By how much")
	fmt.Println("                              _________________________________")
	fmt.Println("                           ")
	fmt.Scanln(&amount)
	Modify(act, amount)
}


func Houses(){
        var action int
	var amount float32
        var act int
	fmt.Println("                         What do you wanna do?")
	fmt.Println("                         _________________________________")
	fmt.Println("     ")
	fmt.Println("                         1. Buy a House         2.Sell a House         ")
	fmt.Println("     ")
	fmt.Println("                         3. Buy a Hotel         4.Sell a Hotel         ")
	fmt.Println("     ")
	fmt.Println("                         5. Transfer a House      ")
        fmt.Scanln(&act)
        switch act{
	case 1:
	fmt.Println("                         What is the price?")
        fmt.Scanln(&amount)
        fmt.Println("                         On which person")
	fmt.Println("                         _________________________________")
	fmt.Println("                           ")
	for {
		fmt.Scanln(&action)
		if action > 0 && action < 5 {
			break
		}
	}
		balance[action] = balance[action] - amount
		value[action] = value[action] + amount
                house[action]++
	case 2:
		fmt.Println("                         What is the price?")
        fmt.Scanln(&amount)
        fmt.Println("                                   On which person")
	fmt.Println("                         _________________________________")
	fmt.Println("                           ")
	for {
		fmt.Scanln(&action)
		if action > 0 && action < 5 {
			break
		}
	}
		balance[action] = balance[action] + amount
 		value[action] = value[action] - amount
		house[action]--
        case 3:
		fmt.Println("                         What is the price?")
        fmt.Scanln(&amount)
        fmt.Println("                                   On which person")
	fmt.Println("                         _________________________________")
	fmt.Println("                           ")
	for {
		fmt.Scanln(&action)
		if action > 0 && action < 5 {
			break
		}
	}
		balance[action] = balance[action] - amount
		value[action] = value[action] + amount
                hotels[action]++
	case 4:
		fmt.Println("                         What is the price?")
        fmt.Scanln(&amount)
        fmt.Println("                                   On which person")
	fmt.Println("                         _________________________________")
	fmt.Println("                           ")
	for {
		fmt.Scanln(&action)
		if action > 0 && action < 5 {
			break
		}
	}
		balance[action] = balance[action] + amount
		value[action] = value[action] - amount
	hotels[action]--
	case 5:
		HouseTrans()
	default:
		fmt.Println("                         try again")
		fmt.Scanln()
	}

}


func HouseTrans() {
	var action [2]int
	var amount float32
	fmt.Println("                         From")
	fmt.Println("                              _________________________________")
	fmt.Println("                           ")
	for {
		fmt.Scanln(&action[0])
		if action[0] > 0 && action[0] < 5 {
			break
		}
	}
	fmt.Println("                           ")
	fmt.Println("                         To")
	fmt.Println("                         _________________________________")
	fmt.Println("                           ")
	for {
		fmt.Scanln(&action[1])
		if action[1] > 0 && action[1] < 5 {
			break
		}
	}
	fmt.Println("                           ")
	fmt.Println("                              By how much")
	fmt.Println("                         _________________________________")
	fmt.Println("                           ")
	fmt.Scanln(&amount)
	balance[action[0]] = balance[action[0]] + amount
	balance[action[1]] = balance[action[1]] - amount
		value[action[0]] = value[action[0]] - amount
		value[action[1]] = value[action[1]] + amount
        house[action[1]]++
        house[action[0]]--
}



func NormTrans() {
	var action [2]int
	var amount float32
	fmt.Println("                         From")
	fmt.Println("                         _________________________________")
	fmt.Println("                           ")
	for {
		fmt.Scanln(&action[0])
		if action[0] > 0 && action[0] < 5 {
			break
		}
	}
	fmt.Println("                           ")
	fmt.Println("                         To")
	fmt.Println("                         _________________________________")
	fmt.Println("                           ")
	for {
		fmt.Scanln(&action[1])
		if action[1] > 0 && action[1] < 5 {
			break
		}
	}
	fmt.Println("                           ")
	fmt.Println("                         By how much")
	fmt.Println("                         _________________________________")
	fmt.Println("                           ")
	fmt.Scanln(&amount)
	balance[action[0]] = balance[action[0]] - amount
	balance[action[1]] = balance[action[1]] + amount
}




func Inc10() {
	var action int
	fmt.Println("                         On which person")
	fmt.Println("                         _________________________________")
	fmt.Println("                           ")
	for {
		fmt.Scanln(&action)
		if action > 0 && action < 5 {
			break
		}
	}
	balance[action] = balance[action] * 1.1
}

func General(act int) {
	var amount float32
	var action int
	fmt.Println("                         Which Amount?")
	fmt.Println("                         _________________________________")
	fmt.Println("     ")
	fmt.Println("                         1. $10         2.$15         3.$20")
	fmt.Println("     ")
	fmt.Println("                         4. $50         5.$100        6.$150")
	fmt.Println("     ")
	fmt.Println("                         7. $200")
	fmt.Println("     ")
	fmt.Scanln(&action)
	switch action {
	case 1:
		amount = 10
	case 2:
		amount = 15
	case 3:
		amount = 20
	case 4:
		amount = 50
	case 5:
		amount = 100
	case 6:
		amount = 150
	case 7:
		amount = 200
	default:
		fmt.Println("                         try again")
		fmt.Scanln()
	}

	Modify(act, amount)
}

func BirthDay() {
	var action int
	fmt.Println("                         Whose birthday is it?")
	fmt.Println("                         _________________________________")
	fmt.Println("                           ")
	for {
		fmt.Scanln(&action)
		if action > 0 && action < 5 {
			break
		}
	}
	for count := 1; count <= 4; count++ {
		balance[count] = balance[count] - 10
	}
	balance[action] = balance[action] + 40
}

func Modify(act int, amount float32) {
	var action int
	fmt.Println("                         On which person")
	fmt.Println("                         _________________________________")
	fmt.Println("                           ")
	for {
		fmt.Scanln(&action)
		if action > 0 && action < 5 {
			break
		}
	}

	if act == 1 {
		balance[action] = balance[action] + amount
	} else if act == 2 {
		balance[action] = balance[action] - amount
	} else {
		fmt.Println("try again!")
	}
}


func Repairs(){
        var action int
        var amount int
	var houses[5] int
        var hotels[5] int
	fmt.Println("                         Which type of repairs ?")
	fmt.Println("                         ________________________________")
 	fmt.Println("                           ")
	fmt.Println("                         1. major           2.minor")
        fmt.Println("                           ")
	fmt.Scanln(&action)
        fmt.Println("                         Houses ?")
	fmt.Println("                         ________________________________")
 	fmt.Println("                           ")
	fmt.Scanln(&houses[0])
        fmt.Println("                         Hotels ?")
	fmt.Println("                         ________________________________")
 	fmt.Println("                           ")
	fmt.Scanln(&hotels[0])
        switch action {
	case 1:
	amount = (houses[0]*40) + (hotels[0]*115)
	case 2:
	amount = (houses[0]*25) + (hotels[0]*100)
	default:
		fmt.Println("                         try again")
		fmt.Scanln()
	}
        Modify(2,float32(amount))


}

func main() {

	Startup()
	for count := 0; count <= 1111; count++ {
		CallClear()
		PrintBalance()
		PrintMenu()
		PerformAction()
	}

}
