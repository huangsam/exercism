package bob

// Hey receives a remark and returns a response.
func Hey(remark string) string {
	lastUpper := -1
	lastLower := -1
	lastNumber := -1
	lastQuestion := -1

	for i := 0; i < len(remark); i++ {
		if 'A' <= remark[i] && remark[i] <= 'Z' {
			lastUpper = i
		} else if 'a' <= remark[i] && remark[i] <= 'z' {
			lastLower = i
		} else if '0' <= remark[i] && remark[i] <= '9' {
			lastNumber = i
		} else if remark[i] == '?' {
			lastQuestion = i
		}
	}

	lastAlphaNum := maxThree(lastUpper, lastLower, lastNumber)

	isAsking := lastQuestion > lastAlphaNum
	isYelling := lastUpper > -1 && lastLower == -1
	isSilent := lastAlphaNum == -1

	switch {
	case isAsking && isYelling:
		return "Calm down, I know what I'm doing!"
	case isAsking:
		return "Sure."
	case isYelling:
		return "Whoa, chill out!"
	case isSilent:
		return "Fine. Be that way!"
	default:
		return "Whatever."
	}
}

// Get the maximum of three integers
func maxThree(a int, b int, c int) int {
	if a >= b && a >= c {
		return a
	}
	if b >= c && b >= a {
		return b
	}
	return c
}
