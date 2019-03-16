package listops

type binFunc func(x, y int) int

type predFunc func(n int) bool

type unaryFunc func(x int) int

// IntList is a list of integers
type IntList []int

// Length returns the length of the IntList
func (il IntList) Length() int {
	return len(il)
}

// Foldl returns the folded output from the left
func (il IntList) Foldl(fn binFunc, n int) int {
	result := n
	for i := 0; i < il.Length(); i++ {
		result = fn(result, il[i])
	}
	return result
}

// Foldr returns the folded output from the right
func (il IntList) Foldr(fn binFunc, n int) int {
	result := n
	for i := il.Length() - 1; i >= 0; i-- {
		result = fn(il[i], result)
	}
	return result
}

// Filter returns the filtered output
func (il IntList) Filter(fn predFunc) IntList {
	result := IntList{}
	for _, i := range il {
		if ok := fn(i); ok {
			result = append(result, i)
		}
	}
	return result
}

// Map returns the modified list
func (il IntList) Map(fn unaryFunc) IntList {
	result := IntList{}
	for _, i := range il {
		result = append(result, fn(i))
	}
	return result
}

// Reverse returns the reversed list
func (il IntList) Reverse() IntList {
	result := IntList{}
	for i := il.Length() - 1; i >= 0; i-- {
		result = append(result, il[i])
	}
	return result
}

// Append returns the combined list
func (il IntList) Append(sil IntList) IntList {
	result := il
	for _, s := range sil {
		result = append(result, s)
	}
	return result
}

// Concat returns the aggregate list
func (il IntList) Concat(col []IntList) IntList {
	result := il
	for _, cl := range col {
		result = result.Append(cl)
	}
	return result
}
