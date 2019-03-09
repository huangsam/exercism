package strand

import (
	"strings"
)

// ToRNA converts DNA sequence to RNA sequence
func ToRNA(dna string) string {
	var builder strings.Builder
	transform := map[rune]rune{
		'C': 'G',
		'G': 'C',
		'T': 'A',
		'A': 'U',
	}
	for _, v := range dna {
		builder.WriteRune(transform[v])
	}
	return builder.String()
}
