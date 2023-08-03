func judgeCircle(moves string) bool {
    x , y , n := 0, 0, len(moves)
    for i:= 0 ; i< n; i++ {
        if moves[i] == 'U'{
            y += 1
        } else if (moves[i] == 'D') {
            y -=1
        } else if (moves[i] == 'R') {
            x += 1
        }else {
            x -= 1
        }
    }
    if (x == 0 && y == 0) {
        return true
    }
    return false
}