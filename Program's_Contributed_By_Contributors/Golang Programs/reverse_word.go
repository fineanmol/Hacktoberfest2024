package main

import "strings"

func reverseWords(s string) string {
	l := strings.Split(s, " ")

	result := ""
	for _, word := range l {
		if result == " " {
			continue
		}
		result = word + " " + result
	}

	return strings.TrimSpace(result)
}
