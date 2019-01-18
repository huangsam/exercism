package letter

// FreqMap records the frequency of each rune in a given text.
type FreqMap map[rune]int

// Frequency counts the frequency of each rune in a given text and returns this
// data as a FreqMap.
func Frequency(s string) FreqMap {
	m := FreqMap{}
	for _, r := range s {
		m[r]++
	}
	return m
}

func (a *FreqMap) update(b FreqMap) {
	for bKey, bVal := range b {
		val, ok := (*a)[bKey]
		if ok {
			(*a)[bKey] += bVal
		} else {
			(*a)[bKey] = val + bVal
		}
	}
}

func worker(ch chan FreqMap, s string) {
	ch <- Frequency(s)
}

// ConcurrentFrequency runs map-reduce to generate final FreqMap
func ConcurrentFrequency(inputs []string) FreqMap {
	result := FreqMap{}
	ch := make(chan FreqMap)
	defer close(ch)
	for _, words := range inputs {
		go func(s string) {
			ch <- Frequency(s)
		}(words)
	}
	for i := 0; i < len(inputs); i++ {
		for k, v := range <-ch {
			result[k] += v
		}
	}
	return result
}
