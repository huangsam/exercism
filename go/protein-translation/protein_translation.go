package protein

import (
	"errors"
)

// ErrStop signals that the scan stopped
var ErrStop = errors.New("scan stopped")

// ErrInvalidBase signals that an invalid codon was found
var ErrInvalidBase = errors.New("invalid base")

var codonMapping = map[string]string{
	"AUG": "Methionine",
	"UUU": "Phenylalanine",
	"UUC": "Phenylalanine",
	"UUA": "Leucine",
	"UUG": "Leucine",
	"UCU": "Serine",
	"UCC": "Serine",
	"UCA": "Serine",
	"UCG": "Serine",
	"UAU": "Tyrosine",
	"UAC": "Tyrosine",
	"UGU": "Cysteine",
	"UGC": "Cysteine",
	"UGG": "Tryptophan",
	"UAA": "",
	"UAG": "",
	"UGA": "",
}

// FromCodon returns a translation and error
func FromCodon(input string) (string, error) {
	if val, ok := codonMapping[input]; ok {
		if val == "" {
			return val, ErrStop
		}
		return val, nil
	}
	return "", ErrInvalidBase
}

// FromRNA returns a translation list and error
func FromRNA(input string) ([]string, error) {
	result := []string{}
	for i := 0; i < len(input); i += 3 {
		tval, terr := FromCodon(input[i : i+3])
		if terr == nil {
			result = append(result, tval)
		} else if terr == ErrStop {
			break
		} else {
			return result, terr
		}
	}
	return result, nil
}
