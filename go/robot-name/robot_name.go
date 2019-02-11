// Package robotname implements robot entity
package robotname

import (
	"math/rand"
	"strings"
)

// Robot holds a name attribute
type Robot struct {
	name string
}

// Name returns robot name if it exists or sets it otherwise
func (r *Robot) Name() (string, error) {
	if r.name == "" {
		r.Reset()
	}
	return r.name, nil
}

// Reset resets robot name to a random string
func (r *Robot) Reset() {
	r.name = randomName()
}

func randomName() string {
	var sb strings.Builder
	sb.WriteRune(randomLetter())
	sb.WriteRune(randomLetter())
	sb.WriteRune(randomNumber())
	sb.WriteRune(randomNumber())
	sb.WriteRune(randomNumber())
	return sb.String()
}

var letterRunes = []rune("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
var numberRunes = []rune("1234567890")

func randomLetter() rune {
	return letterRunes[rand.Intn(len(letterRunes))]
}

func randomNumber() rune {
	return numberRunes[rand.Intn(len(numberRunes))]
}
