package accumulate

// Accumulate transforms a slice of string data
func Accumulate(in []string, converter func(string) string) []string {
	var out []string
	for _, v := range in {
		out = append(out, converter(v))
	}
	return out
}
