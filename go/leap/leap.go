// Package leap is one step towards humanity
package leap

const testVersion = 3

// IsLeapYear checks if input is leap year or not
func IsLeapYear(year int) bool {
	// Write some code here to pass the test suite.
	if year % 4 != 0 {
		return false
	} else if year % 100 == 0 && year % 400 != 0 {
		return false
	}
	return true
}
