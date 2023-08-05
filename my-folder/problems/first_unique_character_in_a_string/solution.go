/*
"leetcode"
{l: 0}
{l: 0, e: 1}
{l: 0, e: -1}
{l: 0, e: -1, t: 3}
{l: 0, e: -1, t: 3, c:4}
{l: 0, e: -1, t: 3, c:4, o:5}
{l: 0, e: -1, t: 3, c:4, o:5, d:6}
{l: 0, e: -1, t: 3, c:4, o:5, d:6}




*/

/*
"leetcode" = s
{l: 0} s[0]
{l: 0, e: 1}
{l: 0, e: -1}
{l: 0, e: -1, t: 3}
{l: 0, e: -1, t: 3, c:4}
{l: 0, e: -1, t: 3, c:4, o:5}
{l: 0, e: -1, t: 3, c:4, o:5, d:6}
{l: 0, e: -1, t: 3, c:4, o:5, d:6}
*/
func firstUniqChar(s string) int {
	charMap := make(map[string]int)
	for i := 0; i < len(s); i++ {
		ss := string(s[i])
		if _, found := charMap[ss]; found {
			charMap[ss] = -1
		} else {
			charMap[ss] = i
		}
	}

	min := math.MaxInt
	for _, val := range charMap {
		if val < min && val > -1 {
			min = val
		}
	}

	if min == math.MaxInt {
		return -1
	} else {
		return min
	}

}