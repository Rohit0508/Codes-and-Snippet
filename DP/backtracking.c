#include<stdio.h>
#include<stdlib.h>

// ************* N-Queen ***************
int board[8][8];
int isSafe(int row,int col,int n){
    // col
    for (int i = 0; i <row; i++){
        if(board[i][col]==1) return 0;
    }
    // left diagonal
   for(int i=row,j=col; i>=0&& j>=0 ; i--,j--){
    if(board[i][j]==1) return 0;
   }

    // right diagonal
   for(int i=row,j=col; i>=0&& j<n ; i--,j++){
    if(board[i][j]==1) return 0;
   }

return 1; 
} 

int Nqueen(int row,int n){
    if(row>=n) return 1;

    for(int col=0; col<n; col++){
        if(isSafe(row,col,n)){
            board[row][col]=1;
            if(Nqueen(row+1,n)) return 1;
            board[row][col]=0;
        }

    }
return 0;    
}

void printSolution() {
    for (int i = 0; i <8; i++) {
        for (int j = 0; j <8; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}
//*******************************************************************

// SUDOKU
int grid[30][30];

int isvalid(int row,int col,int c){
    for (int i = 0; i <9; i++){
        if(grid[i][col]==c) return 0;
        if(grid[row][i]==c) return 0;

        int ix= 3*(row/3) + i/3;
        int iy= 3*(col/3) + i%3;
        if(grid[ix][iy]==c) return 0; // for internal 3*3 grid
    }
return 1;    
}

int Sudoku(int row,int col,int n){
    if(row==n-1 && col==n) return 1;
    if(col==n){
        row++;
        col=0;
    }

    if(grid[row][col]>0) return Sudoku(row,col+1,n);

   for (int i = 1; i <=n; i++){
        if(isvalid(row,col,i)){
           grid[row][col] = i;
           if(Sudoku(row,col+1,n)) return 1;
           grid[row][col]=0; 
        }
    } 
  return 0;  
}


void printSudoku(int n) {
    for (int i = 0; i <n; i++) {
        for (int j = 0; j <n; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}


int main(){
 int n;
//  scanf("%d" ,&n);
//  int a[n];
//  for(int i=0;i<n;i++){
//   	scanf("%d" ,&a[i]);
//  }

//  int b[n];
//  for(int i=0;i<n;i++){
//   	scanf("%d" ,&b[i]);
//  }							

// Nqueen(0,8);
// printSolution();

Sudoku(0,0,20);
printSudoku(20);



return 0;
}