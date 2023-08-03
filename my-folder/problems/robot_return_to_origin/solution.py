class Solution:
    def judgeCircle(self, moves: str) -> bool:
        n = len(moves)
        x , y=0, 0
        for i in range(0, n):
            if moves[i] == "U":
                y +=1 
            if moves[i] == "D":
                y -=1
            if moves[i] == "L":
                x -=1
            if moves[i] == "R":
                x += 1
        
        if (x == 0 and y == 0) :
            return True
        else:
            return False
