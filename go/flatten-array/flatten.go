package flatten

// Flatten processes lists with integers and nested lists
func Flatten(in interface{}) (out []interface{}) {
	outSlice := make([]interface{}, 0)

	for _, v := range in.([]interface{}) {
		switch v.(type) {
		case []interface{}:
			flatSlice := Flatten(v)
			outSlice = append(outSlice, flatSlice...)
		case nil:
			continue
		default:
			outSlice = append(outSlice, v)
		}
	}

	return outSlice
}
