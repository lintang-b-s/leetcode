
/*
    buat dua pointer, iterasi keduanya.  buat sum :=0
    jika nilai prices pointer kanan lebih besar dari nilai prices pointer kiri, tambahkan sum dg selisih nilai dua pointer


*/

func maxProfit(prices []int) int {
    
    sum := 0
    for i:=1; i < len(prices) ; i++{
        if (prices[i] > prices[i-1]) {
            
            sum += prices[i] - prices[i-1]
        }

    }
    return sum
}