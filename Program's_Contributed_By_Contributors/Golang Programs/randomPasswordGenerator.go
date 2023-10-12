package main

import (
	"crypto/rand"
	"encoding/base64"
	"fmt"
)

func generateRandomPassword(length int) (string, error) {
	if length <= 0 {
		return "", fmt.Errorf("Password length must be greater than 0")
	}

	randomBytes := make([]byte, length)

	_, err := rand.Read(randomBytes)
	if err != nil {
		return "", err
	}

	password := base64.StdEncoding.EncodeToString(randomBytes)
	password = password[:length]

	return password, nil
}

func main() {
	passwordLength := 12 // You can change this to your desired password length
	password, err := generateRandomPassword(passwordLength)
	if err != nil {
		fmt.Println("Error:", err)
	} else {
		fmt.Println("Generated Password:", password)
	}
}
