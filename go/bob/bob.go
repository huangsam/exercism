// Package bob contains the Hey API.
package bob

import "strings"

// Hey receives a remark and returns a response.
func Hey(remark string) string {
    questionMark := false
    upperCaseFound := false
    lowerCaseFound := false
    numbersFound := false
    charsAfterQuestion := false

    for i := 0; i < len(remark); i++ {
        if 'a' <= remark[i] && remark[i] <= 'z' {
            lowerCaseFound = true
        } else if 'A' <= remark[i] && remark[i] <= 'Z' {
            upperCaseFound = true
        } else if remark[i] == '?' {
            questionMark = true
        } else if '0' <= remark[i] && remark[i] <= '9' {
            numbersFound = true
        }
    }

    if questionMark == true {
        newRemark := strings.TrimSpace(remark)
        if newRemark[len(newRemark) - 1] != '?' {
            charsAfterQuestion = true
        }
    }

    isYelling := upperCaseFound && !lowerCaseFound
    saidSomething := upperCaseFound || lowerCaseFound || numbersFound

    if questionMark {
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
