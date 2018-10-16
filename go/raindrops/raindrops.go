package raindrops

import (
    "strconv"
)

const testVersion = 3

// Convert converts integer into string
func Convert(x int) string {
    result := ""
    if x % 3 == 0 {
        result += "Pling"
    }
    if x % 5 == 0 {
        result += "Plang"
    }
    if x % 7 == 0 {
        result += "Plong"
    }
    if result == "" {
        return strconv.Itoa(x)
    } else {
        return result
    }
}

// Don't forget the test program has a benchmark too.
// How fast does your Convert convert?
