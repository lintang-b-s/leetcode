
/*
iterasi graph nya dari kiri ->kanan dan atas-> bawah.
tambah count battleshipnya
jika dan hanya  jika elemen yg diiterasi bukan '.' dan
elemen disebelah kiri bukan 'X' dan
elemen yang disebelah atas nya bukan 'X'

*/

func countBattleships(board [][]byte) int {

	count := 0
	for i := range board {
		for j := range board[0] {
			if board[i][j] == '.' {
				continue
			}
			if i > 0 && board[i-1][j] == 'X' {
				continue
			}
			if j > 0 && board[i][j-1] == 'X' {
				continue
			}
			count++
		}
	}
	return count
}