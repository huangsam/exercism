// Package pangram has a pangram checker
package pangram

import (
	"unicode"
)

// IsPangram returns whether the input is a pangram
func IsPangram(in string) bool {
	chars := make(map[rune]bool)
	for _, v := range in {
		newV := unicode.ToLower(v)
		chars[newV] = true
	}
	for c := 'a'; c <= 'z'; c++ {
		if _, ok := chars[c]; !ok {
			return false
		}
	}
	return true
}
