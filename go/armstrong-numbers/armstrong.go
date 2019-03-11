package armstrong

import (
	"math"
)

// IsNumber checks whether input is an Armstrong number
func IsNumber(input int) bool {
	power := 0
	digits := []int{}
	temp := input
	for temp > 0 {
		digits = append(digits, temp%10)
		power++
		temp /= 10
	}
	sum := 0
	for _, v := range digits {
		sum += int(math.Pow(float64(v), float64(power)))
	}
	return sum == input
}
