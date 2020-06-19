#include <iostream>
#include<bits/stdc++.h>
int board[10][10]={0};
int n;
using namespace std;
bool isafe(int row,int col)
{
    int i=row,j=col;
    // Check all left diagonal
    while(i>=0 && j>=0)
    {

        if(board[i][j]==1)
            return false;
        i--;
        j--;
    }
    i=row;j=col;
    // Check all right diagonal
    while(i>=0 && j<n)
    {

        if(board[i][j]==1)
            return false;
        i--;
        j++;
    }
    // checking if that column already has a queen or not
    while(row>=0)
    {
        if(board[row][col]==1)
            return false;
        row--;
    }
    return true;

}

int queen(int row)
{
    if (row==n)//   base case last row
    {

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==1)
                    cout<<"Q ";
                else
                    cout<<"_ ";

            }
            cout<<"\n";

        }
    cout<<"\n\n\n";
    return 1;
    }
        int c=0;
    for(int j=0;j<n;j++)
    {
        if(isafe(row,j))
        {
            board[row][j]=1;
            c+= queen(row+1);// Next queens location
            board[row][j]=0;
        }

    }
    return c;

}
int main()
{

    cin>>n;

    int a=queen(0);
     cout<<a;
    return 0;
}
