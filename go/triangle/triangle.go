package triangle

import "math"

// Kind is an integer
type Kind int

// Define enum of integers
const (
	NaT = 0 // not a triangle
	Equ = 1 // equilateral
	Iso = 2 // isosceles
	Sca = 3 // scalene
	Deg = 4 // degenerate
)

// KindFromSides will return the correct Kind
func KindFromSides(a, b, c float64) Kind {
	switch {
	case isInvalid(a, b, c):
		return NaT
	case isEquilateral(a, b, c):
		return Equ
	case isIsosceles(a, b, c):
		return Iso
	default:
		return Sca
	}
}

func isInvalid(a, b, c float64) bool {
	if a <= 0 || b <= 0 || c <= 0 {
		return true
	} else if a+b < c || b+c < a || c+a < b {
		return true
	} else if math.IsNaN(a + b + c) {
		return true
	} else if math.IsInf(a+b+c, 0) {
		return true
	}
	return false
}

func isEquilateral(a, b, c float64) bool {
	return a == b && b == c
}

func isIsosceles(a, b, c float64) bool {
	return a == b || b == c || c == a
}
