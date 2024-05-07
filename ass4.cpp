// 1st Approach :Branch and Bound
// #include <bits/stdc++.h>
// using namespace std;
// int n;
// class nqueen
// {
// public:
//     void print(vector<vector<int>> &board)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (board[i][j] == 1)
//                 {
//                     cout << "Q"
//                          << " ";
//                 }
//                 else
//                 {
//                     cout << "0"
//                          << " ";
//                 }
//             }
//             cout << endl;
//         }
//     }

//     bool safe(int c, int r, vector<bool> &row, vector<bool> &left, vector<bool> &right)
//     {
//         if (row[r] == true || left[r + c] == true || right[c - r + n - 1] == true)
//         {
//             return false;
//         }
//         return true;
//     }

//     bool solve(vector<vector<int>> &board, int c, vector<bool> &row, vector<bool> &left, vector<bool> &right)
//     {
//         if (c >= n) //all queens are placed
//         {
//             return true;
//         }

//         for (int i = 0; i < n; i++)
//         {
//             if (safe(c, i, row, left, right))
//             {
//                 row[i]=true;
//                 left[i+c]=true;
//                 right[c-i+n-1]=true;
//                 board[i][c]=1;

//                 if(solve(board,c+1,row,left,right))
//                 {
//                     return true;
//                 }

//                 // backtracking
//                 row[i]=false;
//                 left[i+c]=false;
//                 right[c-i+n-1]=false;
//                 board[i][c]=0;
//             }
//         }
//         return false;
//     }
// };
// int main()
// {
//     nqueen q;
//     cout<<"Enter the no of rows :"<<endl;
//     cin>>n;
//     vector<vector<int>> board(n,vector<int>(n,0));
//     vector<bool> row(n,false);
//     vector<bool> left(2*n-1,false); // left diagonals
//     vector<bool> right(2*n-1,false); // right diagonals
//     bool ans=q.solve(board,0,row,left,right);
//     if(ans)
//     {
//         q.print(board);
//     }
//     else
//     {
//         cout<<"Not possible"<<endl;
//     }
//     return 0;
// }

// 2nd Approach : Backtracking
#include <bits/stdc++.h>
using namespace std;
int n;
class nqueen
{
public:
    void print(vector<vector<int>> &board)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                {
                    cout << "Q"
                         << " ";
                }
                else
                {
                    cout << "0"
                         << " ";
                }
            }
            cout << endl;
        }
    }

    bool safe(vector<vector<int>> &board, int row, int col)
    {
        int i, j;
        // checking left side of the row
        for (int i = 0; i < col; i++)
        {
            if (board[row][i])
            {
                return false;
            }
        }

        // checking upper diagonal of the left side
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j])
            {
                return false;
            }
        }

        // checking lower diagonal of the left side
        for (int i = row, j = col; i < n && j >= 0; i++, j--)
        {
            if (board[i][j])
            {
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<int>> &board, int col)
    {
        if (col >= n) // all queens are placed
        {
            return true;
        }

        for(int i=0;i<n;i++)
        {
            if(safe(board,i,col))
            {
                board[i][col]=1;
                if(solve(board,col+1))
                {
                    return true;
                }
                //backtracking
                board[i][col]=0;
            }
        }
        return false;
    }
};
int main()
{
    nqueen q;
    cout << "Enter the no of rows :" << endl;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    bool ans=q.solve(board,0);
    if(ans==true)
    {
        q.print(board);
    }
    else
    {
        cout<<"Solution Not found"<<endl;
    }
    return 0;
}