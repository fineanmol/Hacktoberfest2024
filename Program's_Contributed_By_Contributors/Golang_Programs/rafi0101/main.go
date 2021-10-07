package main

import (
	"fmt"
	"os"

	"github.com/spf13/pflag"
	"github.com/spf13/viper"
)

func main() {

	pflag.String("message", "Hi, I am the default message :)", "print this message")
	pflag.Int("exitCode", 0, "exit code for this program")

	pflag.Usage = func() {
		fmt.Println("Hacktoberfest prints a provided message")
		pflag.PrintDefaults()
		os.Exit(0)
	}

	pflag.Parse()

	viper.BindPFlags(pflag.CommandLine)

	fmt.Println(viper.GetString("message"))
	os.Exit(viper.GetInt("exitCode"))

}
