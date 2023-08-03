import "fmt"

/*
"""
a:0
    {a: 0, b: 1, c: 2 }
    {   c: 2, a:3 , b:4}

    a b c a b
    lr
    a b c a b
    l   r           length = 3
    a b c a b
      l   r         length = 3
    a b c a b
        l   r       length = 3
    a b c a b
        l     r     length = 3


desc: buat pointer left dan right, buat hash table isinya char yg ditunjuk r dan indexnya. right pointer buat search, gerakin r ke kanan ,
cari panjang substring dg max(longest, l-r+1)
jika pointer r  ada dihash table , set l ke index char l di hash ditambah 1. ganti index l di table dg r terbaru.
set elemen di table dg char yg ditunjjuk r dan indexnya.
tambah r dg 1
"""
*/

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func lengthOfLongestSubstring(s string) int {
	l, r, longest := 0, 0, 0
	n := len(s)
	sMap := make(map[string]int)
	for (l < n) && (r < n) {

		_, found := sMap[string(s[r])]
		currentCharacterR := string(s[r])
		if found {
			l = max(l, sMap[currentCharacterR]+1)

		}
		sMap[currentCharacterR] = r
		longest = max(longest, r-l+1)
		r++
	}
	return longest

}
