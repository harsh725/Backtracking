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
bool queen(int row)
{
    if (row==n)//   base case last row
        return true;

    for(int j=0;j<n;j++)
    {
        if(isafe(row,j))
        {
            board[row][j]=1;
            bool nextqueen=queen(row+1);// Next queens location
            if(nextqueen)               //is it possible to place the queen in next row
                return true;
            board[row][j]=0;
        }

    }
    return false;

}
int main()
{

    cin>>n;


    bool f=queen(0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]==1)
                cout<<"Q ";
            else
                cout<<"_ ";

        }
        cout<<endl;
    }

    return 0;
}
