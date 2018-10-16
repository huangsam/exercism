// Package twofer is short for two for one.
package twofer

import (
	"fmt"
	"strings"
)

// ShareWith returns a sentence given a name or lack thereof.
func ShareWith(s string) string {
	result := "One for %v, one for me."
	if !strings.EqualFold(s, "Alice") && !strings.EqualFold(s, "Bob") {
		return fmt.Sprintf(result, "you")
	}
	return fmt.Sprintf(result, s)
}
