package lsproduct

import (
	"errors"
	"regexp"
)

func spanProduct(sdigits string) int {
	result := 1
	for _, d := range sdigits {
		result *= int(d - '0')
	}
	return result
}

// LargestSeriesProduct returns largest span product
func LargestSeriesProduct(digits string, span int) (int, error) {
	dsize := len(digits)
	if span > dsize {
		return -1, errors.New("span must be smaller than string length")
	} else if span < 0 {
		return -1, errors.New("span must be greater than zero")
	} else if dsize == 0 {
		return 1, nil
	}

	if match, _ := regexp.MatchString("^\\d+$", digits); !match {
		return -1, errors.New("digits input must only contain digits")
	}

	max := spanProduct(digits[0:span])
	for i := 1; i < dsize-span+1; i++ {
		cspan := spanProduct(digits[i : i+span])
		if cspan > max {
			max = cspan
		}
	}
	return max, nil
}
