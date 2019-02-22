package cryptosquare

import (
	"math"
	"strings"
	"unicode"
)

type Matrix [][]rune

// Step 1: Normalize characters
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

// Step 3: Build matrix data
func buildMatrix(nt string, r int, c int) Matrix {
	m := make(Matrix, r)
	for i := 0; i < r; i++ {
		m[i] = make([]rune, c)
	}
	for i, nr := range nt {
		m[i/c][i%c] = nr
	}
	return m
}

// Step 4: Build inverted result
func buildResult(m Matrix, r int, c int) string {
	var sb strings.Builder
	var nb strings.Builder
	for i := 0; i < c; i++ {
		for j := 0; j < r; j++ {
			curr := m[j][i]
			if curr == 0 {
				nb.WriteRune(' ')
			} else {
				nb.WriteRune(curr)
			}
		}
		sb.WriteString(nb.String())
		nb.Reset()
		if i != c-1 {
			sb.WriteRune(' ')
		}
	}
	return sb.String()
}

func Encode(pt string) string {
	nt := normalizeText(pt)
	r, c := getDimensions(len(nt))
	m := buildMatrix(nt, r, c)
	return buildResult(m, r, c)
}
