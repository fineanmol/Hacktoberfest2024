package main

func main() {
	// Set the time to a specific value.
	t := time.Date(2023, 10, 11, 15, 39, 22, 0, time.UTC)

	// Set the time to a specific timezone.
	t = t.In(time.FixedZone("Asia/Jakarta", 7*60*60))

	// Set the time to the current time.
	t = time.Now()
}