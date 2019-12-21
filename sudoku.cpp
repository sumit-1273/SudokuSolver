#include <bits/stdc++.h>
using namespace std;

//the sudoku
vector<vector<int>> grid(9,vector<int>(9,0));

void printGrid();

bool isSafe(int n, int row, int col){
    
    //checking in the row and columns if no. is present
    for(int i=0;i<9;i++){
        if(grid[i][col] == n) return false;
        if(grid[row][i] == n) return false;
    }
    
    int rw = row - row%3;
    int cl = col - col%3;
    
    //checking in the present 3x3 square if no. is present
    for(int i=rw;i<rw+3;i++){
        for(int j=cl;j<cl+3;j++){
            if(grid[i][j] == n) return false;
        }
    }
    //if no. is valid
    return true;
}

bool sudokuSolver(){    
    int row = -1,col = -1;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(grid[i][j] == 0){
                row = i;
                col = j;
                i = j = 9;
            }
        }
    }
    
    if(row == -1 && col == -1) return true;
    for(int m=1;m<=9;m++){
       if(isSafe(m,row,col)){
          grid[row][col] = m;
          if(sudokuSolver()){
              return true; 
          }
          else{
              grid[row][col] = 0;
          }
        }
    }
    return false;
}

void printGrid(){
    for(int i=0;i<9;i++){
	   for(int j=0;j<9;j++){
	      cout<<grid[i][j]<<" ";
	   }
	 cout<<endl;
	}
}

int main() {
	//code
	int t,count;
	cin>>t;
	while(t--){
	    for(int i=0;i<9;i++){
	        for(int j=0;j<9;j++){
	            cin>>grid[i][j];
	        }
	    }
	    if(sudokuSolver()){
	       printGrid();
	       cout<<endl;
	    }
	    else cout<<-1<<endl;
	}
	return 0;
}
