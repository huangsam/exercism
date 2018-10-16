// Package hamming implements hamming distance
package hamming

import "fmt"

const testVersion = 6

// Distance returns Hamming distance between two strings of equal length
func Distance(a, b string) (int, error) {
	if len(a) != len(b) {
		return -1, fmt.Errorf("Two strings of unequal length")
	}
	distance := 0
	for i := 0; i < len(a); i++ {
		if a[i] != b[i] {
			distance += 1
		}
	}
	return distance, nil
}
