package series

// All gets every n-digit pattern
func All(n int, digits string) []string {
	var result []string
	if n > len(digits) {
		return result
	}
	for i := n; i <= len(digits); i++ {
		result = append(result, digits[(i-n):i])
	}
	return result
}

// UnsafeFirst gets the first n-digit pattern
func UnsafeFirst(n int, digits string) string {
	return digits[0:n]
}

// First gets the first n-digit pattern if it exists
func First(n int, digits string) (first string, ok bool) {
	if n > len(digits) {
		return "", false
	}
	return UnsafeFirst(n, digits), true
}
