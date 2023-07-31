class Solution:
    """
    iterasi graph nya dari kiri ->kanan dan atas-> bawah. 
    tambah count battleshipnya
     jika dan hanya  jika elemen yg diiterasi bukan '.' dan 
     elemen disebelah kiri bukan 'X' dan
     elemen yang disebelah atas nya bukan 'X'

    """
    def countBattleships(self, board: List[List[str]]) -> int:
        m = len(board)
        n = len(board[0])
        count = 0
        for i in range(0,m):
            for j in range(0, n ) :
                if (board[i][j] == '.' ): continue
                if ( i>0  and board[i-1][j] == 'X'): continue
                if (j >0 and board[i][j-1] == 'X'): continue
                count += 1
        return count