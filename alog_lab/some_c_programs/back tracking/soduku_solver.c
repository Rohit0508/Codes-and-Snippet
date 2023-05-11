#include<stdlib.h>
#define N 9
int soduku[N][N] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};
void print_sol(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",soduku[i][j]);
        }
        printf("\n");
    }
}
int isSafe(int x,int y,int digit){
    for(int i=0;i<9;i++){
        if(soduku[i][y]==digit) return 0;
    }
    for(int j=0;j<9;j++){
        if(soduku[x][j]==digit) return 0;
    }
    for(int i=0;i<9;i++){
        if(soduku[3*(x/3)+i/3][3*(y/3)+i%3]==digit) return 0;
    }
    return 1;
}
int  solve_soduku(){
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(soduku[i][j]==0){
                for(int k=1;k<=9;k++){
                    if(isSafe(i,j,k)){
                        soduku[i][j]=k;
                        if(solve_soduku()) {
                            print_sol();
                            return 1;
                        }
                        else soduku[i][j]=0;
                    }
                }
                return 0;  
            }
            
        }
    }
    return 1;
}
int main(){
    
    solve_soduku();
    return 0;
}