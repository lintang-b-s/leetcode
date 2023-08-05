/*
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
["h","e","l","l","o"]
  l.              r
["o","l","l","e","h"]
      l.      r
["o","l","l","e","h"]
          lr
          

*/

func reverseString(s []byte)  {
	l, r := 0, len(s)-1
	for (l < r){

		s[l], s[r] = s[r], s[l]
		l++
		r--
	}

}