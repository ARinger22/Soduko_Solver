#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, n) for (ll i = a; i < n; i++)
#define ll long long

bool isValid(vector<vector<char> > &A, int l, int j , int i)
{
    for(int k =0; k<9; k++)
    {
        if(A[i][k] == (l+48)) return false;
    }
    for(int k =0; k<9; k++)
    {
        if(A[k][j] == (l+48)) return false;
    }
    
    int row= (i/3)*3;
    int col= (j/3)*3;
    for(int x = 0; x<3 ; x++)
    {
        for(int y =0; y<3; y++)
        {
            if(A[row+x][col+y] == l+48) return false;
        }
    }
    
    return true;
}

bool solve(vector<vector<char> > &A, int n, int i , int j )
{
    if(i == 8 && j == 9) return true;
    
    if(i != 8 && j == 9) {i++; j=0;}
    
    if(A[i][j] != '.') {if(solve(A,n,i,++j)) return true; else {j--;return false;}}
    else
    {
        for(int k =1; k <= 9; k++)
        {
            if(isValid(A,k,j,i))
            {
                A[i][j] = k+48;
                if(solve(A,n,i,++j)) return true;
                j--;
                A[i][j] = '.';
            }
        }
        return false;
    }
    
}

void solveSudoku(vector<vector<char> > &A) {
    solve(A,9,0,0);
    loop(i,0,9)
    {
        loop(j,0,9)
        {
            cout<<A[i][j];
        }
        cout<<"\n";
    }
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    vector<vector<char>> A(9);
    loop(i,0,9)
    {
        loop(j,0,9)
        {
            char c;cin>>c;
            A[i].push_back(c);
        }
    }
    solveSudoku(A);
}
