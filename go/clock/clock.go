// Package clock has operations for Clock struct
package clock

import "fmt"

const testVersion = 4

// Clock is a struct for clock values
type Clock struct {
	h int
	m int
}

func adjustTime(hours, minutes int) (int, int) {
	if minutes >= 60 {
		hours += int(minutes / 60)
		minutes %= 60
	} else if minutes < 0 {
		hours += int(minutes/60) - 1
		minutes %= 60
		minutes += 60
	}
	hours %= 24
	if hours < 0 {
		hours += 24
	}
	return hours, minutes
}

// New returns a new Clock value
func New(hour, minute int) Clock {
	cHours, cMinutes := adjustTime(hour, minute)
	return Clock{
		h: cHours,
		m: cMinutes,
	}
}

func (c Clock) String() string {
	cHours, cMinutes := adjustTime(c.h, c.m)
	return fmt.Sprintf("%02d:%02d", cHours, cMinutes)
}

// Add adds minutes to clock value
func (c Clock) Add(minutes int) Clock {
	cHours, cMinutes := adjustTime(c.h, c.m+minutes)
	c.h, c.m = cHours, cMinutes
	return c
}
