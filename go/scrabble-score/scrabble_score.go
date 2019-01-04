package scrabble

import "unicode"

var letterScoresCoarse = map[string]int{
	"AEIOULNRST": 1,
	"DG":         2,
	"BCMP":       3,
	"FHVWY":      4,
	"K":          5,
	"JX":         8,
	"QZ":         10,
}

func Score(word string) int {
	letterScoresGranular := make(map[rune]int)
	for key, val := range letterScoresCoarse {
		for _, ch := range key {
			letterScoresGranular[ch] = val
		}
	}
	result := 0
	for _, ch := range word {
		upperCh := unicode.ToUpper(ch)
		result += letterScoresGranular[upperCh]
	}
	return result
}
