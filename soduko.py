row = []

def isValid(row,sz,j,i):
    for k in range(0,9):
        if(row[i][k] == chr(sz+48)): return False
    for k in range(0,9):
        if(row[k][j] == chr(sz+48)): return False
    rw = (i//3)*3
    cl = (j//3)*3
    for x in range(3):
        for y in range(3):
            if(row[rw+x][cl+y] == chr(sz+48)): return False
    return True


def solve(row,sz,i,j):
    if(i == 8 and j == 9):
        return True
    if(i != 8 and j == 9) :
        i += 1
        j = 0
    if(row[i][j] != '.'):
        j += 1 
        if(solve(row,sz,i,j)): return True
        else: return False
    else:
        for k in range(1,10):
            if(isValid(row,k,j,i)):
                row[i][j] = chr(k+48)
                # print(row[i][j])
                j += 1
                if(solve(row,sz,i,j)): return True
                j -= 1
                row[i][j] = '.'
        return False


def solveSoduko(row):
    solve(row,9,0,0)
    for i in range(9):
        for j in range(9):
            print(row[i][j],end="")
        print()


def main():
    col = []
    s = input()
    for i in range(81):
        if(i%9 == 0 and i != 0): 
            row.append(col)
            col = []
        col.append(s[i])
    row.append(col)
    solveSoduko(row)

main()