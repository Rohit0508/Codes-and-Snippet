#include<stdlib.h>
#define N 4
int nqueen[N][N] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};
void print_sol(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",nqueen[i][j]);
        }
        printf("\n");
    }
}
int isSafe(int x,int y){
    for(int i=0;i<N;i++){
        if(nqueen[i][y]==1) return 0;
    }
    for(int j=0;j<N;j++){
        if(nqueen[x][j]==1) return 0;
    }
    for(int i=0;i<N;i++){
        if(x+i<N&&y+i<N){
            if(nqueen[x+i][y+i]==1) return 0;
        }    
    }
    for(int i=0;i<N;i++){
        if(x+i<N&&y-i>=0){
            if(nqueen[x+i][y-i]==1) return 0;
        } 
    }
    for(int i=0;i<N;i++){
        if(x-i>=0&&y+i<N){
            if(nqueen[x-i][y+i]==1) return 0;
        } 
    }
    for(int i=0;i<N;i++){
        if(x-i>=0&&y-i>=0){
            if(nqueen[x-i][y-i]==1) return 0;
        } 
    }
    return 1;
}
void  solve_nqueen(int row){
    if(row==N){
        print_sol();
        return;   
    }
    for(int i=0;i<N;i++){
        if(isSafe(row, i)){
            nqueen[row][i]=1;
            solve_nqueen(row+1);
            nqueen[row][i]=0;
        }
    }
}
int main(){
    
    solve_nqueen(0);
    return 0;
}