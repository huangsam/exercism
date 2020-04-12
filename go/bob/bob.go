package bob

// Hey receives a remark and returns a response.
func Hey(remark string) string {
	lastQuestion := -1
	lastUpper := -1
	lastLower := -1
	lastNumber := -1

	for i := 0; i < len(remark); i++ {
		if 'a' <= remark[i] && remark[i] <= 'z' {
			lastLower = i
		} else if 'A' <= remark[i] && remark[i] <= 'Z' {
			lastUpper = i
		} else if remark[i] == '?' {
			lastQuestion = i
		} else if '0' <= remark[i] && remark[i] <= '9' {
			lastNumber = i
		}
	}

	charsAfterQuestion := lastQuestion <= lastUpper ||
		lastQuestion <= lastLower ||
		lastQuestion <= lastNumber

	isYelling := lastUpper > -1 && lastLower == -1
	saidSomething := lastUpper > -1 || lastLower > -1 || lastNumber > -1

	if lastQuestion > -1 {
		if isYelling {
			return "Calm down, I know what I'm doing!"
		} else if !charsAfterQuestion {
			return "Sure."
		}
	} else if isYelling {
		return "Whoa, chill out!"
	} else if !saidSomething {
		return "Fine. Be that way!"
	}
	return "Whatever."
}
