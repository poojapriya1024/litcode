#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>>& board) 
{   
    vector<unordered_set<char>> rows;
    vector<unordered_set<char>> cols;
    vector<unordered_set<char>> subGrid;
    
    for(int x=0;x<9;x++)
    {   
        for(int y=0;y<9;y++)
        {
            char curr = board[x][y];
            
            //check for unique rows
            if(rows[x].find(curr) != rows[x].end())
                return false;
            rows[x].insert(curr);
            
            //check for unique column
            if(cols[y].find(curr) != cols[y].end())
                return false;
            cols[y].insert(curr);
            
            //check for unique subgrids
            int gridIndex = (x / 3 ) * 3 + (y / 3);
            if(subGrid[gridIndex].find(curr) != subGrid[gridIndex].end())
                return false;
            subGrid[gridIndex].insert(curr);
        }
    }
    
    return true;
}
int main() 
{
    //get the size and input board 
    int size;
    vector<vector<char>> board(9);
    
    cin>>size;
    
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            cin>>board[i][j];
            
    }
    
    if(isValid(board))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
        
    return 0;
}