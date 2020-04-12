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

	isAsking := lastQuestion > lastUpper && lastQuestion > lastLower && lastQuestion > lastNumber
	isYelling := lastUpper > -1 && lastLower == -1
	isSilent := lastUpper == -1 && lastLower == -1 && lastNumber == -1

	if isAsking {
		if isYelling {
			return "Calm down, I know what I'm doing!"
		}
		return "Sure."
	} else if isYelling {
		return "Whoa, chill out!"
	} else if isSilent {
		return "Fine. Be that way!"
	}
	return "Whatever."
}
