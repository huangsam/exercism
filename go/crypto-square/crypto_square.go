package cryptosquare

import (
	"math"
	"strings"
	"unicode"
)

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

func Encode(pt string) string {
	// Step 1: Normalize characters
	var sb strings.Builder
	for _, r := range pt {
		if unicode.IsNumber(r) || unicode.IsLetter(r) {
			sb.WriteRune(unicode.ToLower(r))
		}
	}
	nt := sb.String()

	// Step 2: Build matrix
	r, c := getDimensions(len(nt))

	// Step 3: Build matrix
	m := make([][]rune, r)
	for i := 0; i < r; i++ {
		m[i] = make([]rune, c)
	}

	// Step 4: Fill matrix
	for i, nr := range nt {
		m[i/c][i%c] = nr
	}

	// Step 5: Build inverted string
	sb.Reset()
	var nb strings.Builder
	for i := 0; i < c; i++ {
		nb.Reset()
		for j := 0; j < r; j++ {
			curr := m[j][i]
			if curr == 0 {
				nb.WriteRune(' ')
			} else {
				nb.WriteRune(curr)
			}
		}
		sb.WriteString(nb.String())
		if i != c-1 {
			sb.WriteRune(' ')
		}
	}
	it := sb.String()

	return it
}
