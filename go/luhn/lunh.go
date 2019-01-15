package luhn

func Valid(content string) bool {
	digits := []int{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
		1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
	}
	found := 0
	sum := 0
	for i := len(content) - 1; i >= 0; i-- {
		ch := content[i]
		if ch == ' ' {
			continue
		}
		if ch < '0' || ch > '9' {
			return false
		}
		found += 1
		offset := int(ch - '0')
		key := offset
		if found%2 == 0 {
			key *= 2
		}
		sum += digits[key]
	}
	return found > 1 && sum%10 == 0
}
