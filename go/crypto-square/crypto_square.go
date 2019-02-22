// Package cryptosquare supports matrix-based encryption
package cryptosquare

import (
	"strings"
	"unicode"
)

type matrix [][]rune

func normalizeText(pt string) string {
	var sb strings.Builder
	for _, r := range pt {
		if unicode.IsNumber(r) || unicode.IsLetter(r) {
			sb.WriteRune(unicode.ToLower(r))
		}
	}
	return sb.String()
}

func getSize(nl int) (r, c int) {
	c = 1
	for {
		if c*c >= nl {
			break
		}
		c++
	}
	if c*(c-1) >= nl {
		r = c - 1
	} else {
		r = c
	}
	return
}

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
	r, c := getSize(len(nt))
	m := buildMatrix(nt, r, c)
	return buildResult(m, r, c)
}
