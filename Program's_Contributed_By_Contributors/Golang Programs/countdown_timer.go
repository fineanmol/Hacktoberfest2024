package main

import (
	"flag"
	"os"
	"fmt"
	"time"
)

type countdown struct {
	t int
	d int
	h int
	m int
	s int
}

func getTimeRemaining(t time.Time) countdown {
	currentTime := time.Now()
	difference := t.Sub(currentTime)

	total := int(difference.Seconds())
	days := int(total / (60 * 60 * 24))
	hours := int(total / (60 * 60) % 24)
	minutes := int(total/60) % 60
	seconds := int(total % 60)

	return countdown{
		t: total,
		d: days,
		h: hours,
		m: minutes,
		s: seconds,
	}
}

func main() {
	deadline := flag.String("deadline", "", "The deadline for the countdown timer in RFC3339 format (e.g. 2019-12-25T15:00:00+01:00)")
	flag.Parse()

	if *deadline == "" {
		flag.PrintDefaults()
		os.Exit(1)
	}

	v, err := time.Parse(time.RFC3339, *deadline)
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}

	for range time.Tick(1 * time.Second) {
		timeRemaining := getTimeRemaining(v)

		if timeRemaining.t <= 0 {
			fmt.Println("Countdown reached!")
			break
		}

		fmt.Printf("Days: %d Hours: %d Minutes: %d Seconds: %d\n", timeRemaining.d, timeRemaining.h, timeRemaining.m, timeRemaining.s)
	}
}