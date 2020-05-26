package armstrong

import (
	"math"
)

// IsNumber checks whether input is an Armstrong number
func IsNumber(input int) bool {
	digits := int(math.Log10(float64(input)) + 1.0)
	sum := 0.0
	for left := input; left > 0; left /= 10 {
		sum += math.Pow(float64(left%10), float64(digits))
	}
	return int(sum) == input
}
