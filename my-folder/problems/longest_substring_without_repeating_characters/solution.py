class Solution:

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

    def lengthOfLongestSubstring(self, s):
        if (len(s) <= 1) :
            return len(s)
        l = 0
        r = 0
        length = 1
        hashSet =  {}
        while (l < len(s) and r < len(s)):
            currCharacter= s[r]
            if (currCharacter in hashSet):
                l = max(l, hashSet[currCharacter] + 1)
                hashSet.pop(currCharacter)

            length = max(length, r-l+1)
            hashSet[currCharacter] = r
            r += 1
        return length