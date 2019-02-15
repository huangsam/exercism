package flatten

// Flatten processes lists with integers and nested lists
func Flatten(in interface{}) (out []interface{}) {
	result := make([]interface{}, 0)

	for _, v := range in.([]interface{}) {
		switch v.(type) {
		case []interface{}:
			result = append(result, Flatten(v)...)
		case nil:
			continue
		default:
			result = append(result, v)
		}
	}

	return result
}
