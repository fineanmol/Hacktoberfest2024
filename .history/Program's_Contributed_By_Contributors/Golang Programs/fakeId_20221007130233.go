#Script to generate fake id written in Go
package main

import (
	"fmt"
	"strings"
	"net/http"
	"encoding/json"
	"io/ioutil"
)

const URL = "https://api.namefake.com/"

func check(e error) {
	if e != nil {
		panic(e)
	}
}

func main() {
	type Identity struct {
		Name        string  `json:"name"`
		Address     string  `json:"address"`
		Latitude    float64 `json:"latitude"`
		Longitude   float64 `json:"longitude"`
		MaidenName  string  `json:"maiden_name"`
		BirthData   string  `json:"birth_data"`
		PhoneH      string  `json:"phone_h"`
		PhoneW      string  `json:"phone_w"`
		EmailU      string  `json:"email_u"`
		EmailD      string  `json:"email_d"`
		Username    string  `json:"username"`
		Password    string  `json:"password"`
		Domain      string  `json:"domain"`
		Useragent   string  `json:"useragent"`
		Ipv4        string  `json:"ipv4"`
		Macaddress  string  `json:"macaddress"`
		Plasticcard string  `json:"plasticcard"`
		Cardexpir   string  `json:"cardexpir"`
		Bonus       int     `json:"bonus"`
		Company     string  `json:"company"`
		Color       string  `json:"color"`
		UUID        string  `json:"uuid"`
		Height      int     `json:"height"`
		Weight      float64 `json:"weight"`
		Blood       string  `json:"blood"`
		Eye         string  `json:"eye"`
		Hair        string  `json:"hair"`
		Pict        string  `json:"pict"`
		URL         string  `json:"url"`
		Sport       string  `json:"sport"`
		Ipv4URL     string  `json:"ipv4_url"`
		EmailURL    string  `json:"email_url"`
		DomainURL   string  `json:"domain_url"`
	}

	var id Identity

	resp, err := http.Get(URL)
	check(err)

	content, err := ioutil.ReadAll(resp.Body)
	check(err)

	defer resp.Body.Close()

	json.Unmarshal([]byte(content), &id)

	fmt.Printf("Name\t\t: %s\n", id.Name)
	fmt.Printf("Username\t: %s\n", id.Username)
	fmt.Printf("Password\t: %s\n", id.Password)
	fmt.Printf("Address\t\t: %s\n", strings.Replace(id.Address, "\n", " ", 1))
	fmt.Printf("Birth Date\t: %s\n", id.BirthData)
	fmt.Printf("Email\t\t: %s\n", id.EmailU + "@" + id.EmailD)
	fmt.Printf("Phone Number\t: %s\n", id.PhoneW)
}