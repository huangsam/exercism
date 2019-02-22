// Package cryptosquare supports matrix-based encryption
package cryptosquare

import (
	"math"
	"strings"
	"unicode"
)

type matrix [][]rune

// Step 1: Normalize plaintext input
func normalizeText(pt string) string {
	var sb strings.Builder
	for _, r := range pt {
		if unicode.IsNumber(r) || unicode.IsLetter(r) {
			sb.WriteRune(unicode.ToLower(r))
		}
	}
	return sb.String()
}

// Step 2: Get matrix rows and columns
func getDimensions(nl int) (int, int) {
	nsq := math.Sqrt(float64(nl))
	r := int(math.Floor(nsq))
	c := int(math.Ceil(nsq))

	for {
		if r*c < nl {
			r++
		}
		if r*c < nl {
			c++
		}
		if r*c >= nl {
			break
		}
	}

	return r, c
}

// Step 3: Build matrix with normalized content
func buildMatrix(nt string, r int, c int) matrix {
	m := make(matrix, r)
	for i := 0; i < r; i++ {
		m[i] = make([]rune, c)
	}
	for i, nr := range nt {
		m[i/c][i%c] = nr
	}
	return m
}

// Step 4: Build ciphertext output as result
func buildResult(m matrix, r int, c int) string {
	var sb strings.Builder
	padded := []string{}
	for i := 0; i < c; i++ {
		for j := 0; j < r; j++ {
			curr := m[j][i]
			if curr == 0 {
				sb.WriteRune(' ')
			} else {
				sb.WriteRune(curr)
			}
		}
		padded = append(padded, sb.String())
		sb.Reset()
	}
	return strings.Join(padded, " ")
}

// Encode converts plaintext to ciphertext
func Encode(pt string) string {
	nt := normalizeText(pt)
	r, c := getDimensions(len(nt))
	m := buildMatrix(nt, r, c)
	return buildResult(m, r, c)
}
