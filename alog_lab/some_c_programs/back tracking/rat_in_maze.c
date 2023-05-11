#include<stdio.h>
#define N 4
int maze[N][N]={{1,0,0,0},{1,1,0,1},{0,1,0,0},{1,1,1,1}};
int sol[N][N];
void print_sol(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(maze[i][j]==-1)
            printf("2 ");
            else printf("0 ");
        }
        printf("\n");
    }
}
int issafe(int x,int y){
    if(x>=0&&y>=0&&x<N&&y<N&&maze[x][y]==1){
        return 1;
    }
    return 0;
}
void solve_backtrack(int x,int y){
    if(x==N-1&&y==N-1){
        printf("One Way to reach is \n");
        maze[x][y]=-1;
        print_sol();
        return;
    }
    int a=maze[x][y];
    maze[x][y]=-1;
    int i[4]={0,0,1,-1};
    int j[4]={1,-1,0,0};
    for(int k=0;k<4;k++){
        int newx=x+i[k];
        int newy=y+j[k];
        if(issafe(newx, newy)){
            solve_backtrack(newx, newy);
        }
    }
    maze[x][y]=a;
    
}
int main(){
    
    solve_backtrack(0,0);
    
    return 0;
}
