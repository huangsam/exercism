package etl

import (
	"strings"
)

// Transform converts old map format to new map format
func Transform(in map[int][]string) map[string]int {
	out := make(map[string]int)
	for k, v := range in {
		for _, w := range v {
			out[strings.ToLower(w)] = k
		}
	}
	return out
}
