// Package wordcount has counting utilities
package wordcount

import (
	"strings"
	"unicode"
)

// Frequency is a primitive for storing word hits
type Frequency map[string]int

// WordCount calculates frequency from a string of words
func WordCount(in string) Frequency {
	var builder strings.Builder
	for _, c := range in {
		if unicode.IsLetter(c) || unicode.IsNumber(c) || c == '\'' {
			builder.WriteRune(unicode.ToLower(c))
		} else {
			builder.WriteRune(' ')
		}
	}
	result := make(Frequency)
	for _, v := range strings.Fields(builder.String()) {
		newV := strings.Trim(v, "'")
		if _, ok := result[newV]; !ok {
			result[newV] = 1
		} else {
			result[newV]++
		}
	}
	return result
}
