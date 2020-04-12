package isogram

import "unicode"

// IsIsogram shows whether word is an isogram
func IsIsogram(word string) bool {
	seen := make(map[rune]int)
	for _, ch := range word {
		if ch == '-' || ch == ' ' {
			continue
		}
		newCh := unicode.ToLower(ch)
		if _, ok := seen[newCh]; ok {
			seen[newCh] += 1
		} else {
			seen[newCh] = 1
		}
	}
	for _, count := range seen {
		if count > 1 {
			return false
		}
	}
	return true
}
