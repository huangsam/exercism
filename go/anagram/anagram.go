// Package anagram provides routines for anagram detection
package anagram

import (
	"bytes"
	"strings"
	"unicode"
)

func getBitMap(word string) []byte {
	bitMap := make([]byte, 26)
	for _, r := range word {
		if unicode.IsLetter(r) {
			bitMap[r-'a'] += 1
		}
	}
	return bitMap
}

// Detect identifies candidates which are anagrams of a subject
func Detect(subject string, candidates []string) []string {
	result := []string{}
	sLower := strings.ToLower(subject)
	sBitMap := getBitMap(sLower)
	for _, c := range candidates {
		cLower := strings.ToLower(c)
		if sLower != cLower {
			cBitMap := getBitMap(cLower)
			if bytes.Equal(sBitMap, cBitMap) {
				result = append(result, c)
			}
		}
	}
	return result
}
