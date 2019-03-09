package gigasecond

// import path for the time package from the standard library
import (
	"math"
	"time"
)

const testVersion = 4

// AddGigasecond returns time when someone has lived for 10^9 seconds
func AddGigasecond(t time.Time) time.Time {
	tenToNine := int64(math.Pow(10, 9))
	seconds := time.Duration(tenToNine) * time.Second
	return t.Add(seconds)
}
