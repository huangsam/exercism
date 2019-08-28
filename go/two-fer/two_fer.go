package twofer

import (
	"fmt"
)

// ShareWith returns a sentence given a name or lack thereof.
func ShareWith(s string) string {
	var noun string
	if len(s) == 0 {
		noun = "you"
	} else {
		noun = s
	}
	return fmt.Sprintf("One for %v, one for me.", noun)
}
