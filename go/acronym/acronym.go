// Package acronym converts full string into acronym
package acronym

import "strings"

// Abbreviate receives a full string and returns an acronym.
func Abbreviate(s string) string {
	var sb strings.Builder
	spaceTokens := strings.Split(s, " ")
	for _, spaceToken := range spaceTokens {
		if spaceToken == "-" {
			continue
		}
		dashTokens := strings.Split(spaceToken, "-")
		if len(dashTokens) == 0 {
			sb.WriteByte(spaceToken[0])
		} else {
			for _, dashToken := range dashTokens {
				sb.WriteByte(dashToken[0])
			}
		}
	}
	return strings.ToUpper(sb.String())
}
