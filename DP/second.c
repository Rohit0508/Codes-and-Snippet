#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

int vec[10][2];
const int inf=-1e6;

void swap(int *a ,int *b){
	int tmp = *a;
	 *a = *b;
	 *b = tmp;
}

//********ACTIVITY SELECTION***************
// sorts accrd. to finish time
void sort(int n1){
	for (int i = 0; i <n1; i++){
		int minind =i;
		for(int j=i+1; j<n1; j++){
			if(vec[minind][1]>vec[j][1]) minind = j;
		}
	   if(minind !=i){
		swap(&vec[i][0],&vec[minind][0]);
		swap(&vec[i][1],&vec[minind][1]);
	  }
	}	
}

//************ ROD CUTTING *****************
int RodCutting(int ind,int n,int len[],int price[],int length){
	if(length==0) return 0;
	if(ind>=n) return inf;

	int ans =0;

	if(length-len[ind]>=0){
	ans = max(ans,price[ind]+ RodCutting(ind,n,len,price,length-len[ind]));
	}
	ans = max(ans,RodCutting(ind+1,n,len,price,length));	

  return ans;	
}

//******** COIN CHANGE **************
int dp[100][100];

int CoinChange(int a[],int n,int sum){
	for (int i = 1; i <=sum; i++){
		dp[0][i]=0;
	}
	for (int i =0; i <=n; i++){
		dp[i][0]=1;
	}

	for (int i = 1; i <=n; i++){
		for(int j=1; j<=sum ;j++){
			if(j-a[i-1]>=0)
				dp[i][j] = dp[i][j-a[i-1]]; // taken
		
			dp[i][j]+= dp[i-1][j]; // not taken
		}
	}

return dp[n][sum];	
}



//*********** MCM*************
int print[100][100];
int Mcm(int n,int a[]){
	int sz = n-1; // because one extra in array

	for (int gap = 0; gap <sz; gap++){
		for(int i=0,j=gap; j<sz ; i++,j++){
			
			if(gap==0) dp[i][j]=0;
			else{
				dp[i][j] = 1e7;	
				for(int k=i ;k<j ;k++){
					int left = dp[i][k];
					int right = dp[k+1][j];
					int mCost = a[i]*a[k+1]*a[j+1];
					int total = left+right+mCost;
					if(total<dp[i][j]){
						dp[i][j] = total;
						print[i][j] =k;
					}
				}
			} 
		}
	}
	
//   for(int i=0;i<sz;i++){
// 	for(int j=0;j<sz;j++)
//   	printf("%d " ,dp[i][j]);
//   	printf("\n ");
//  }	

//   for(int i=0;i<sz;i++){
// 	for(int j=0;j<sz;j++)
//   	printf("%d " ,print[i][j]);
//   	printf("\n ");
//  }		

return dp[0][sz-1]; 	
}

// ****** Printing MCM ***************** 
void printOptimalParens(int i, int j) {
    if (i == j) {
        printf("A%d", i+1);
    } else {
        printf("(");
        printOptimalParens(i, print[i][j]);
        printOptimalParens(print[i][j] + 1, j);
        printf(")");
    }
}





int main(){
 int n1;
//  scanf("%d" ,&n1);

/*
 for(int i=0;i<n1;i++){
  	scanf("%d" ,&vec[i][0]);
 }							
 for(int i=0;i<n1;i++){
  	scanf("%d" ,&vec[i][1]);
 }

 sort(n1);

// *****ACTIVITY SELECTION *****
  for(int i=0;i<10;i++){
  	printf("%d %d\n" ,vec[i][0],vec[i][1]);
 }							
int taken = vec[0][1];
int ans =1;

for (int i = 1; i <n1; i++){
	if(vec[i][0]>=taken){
		ans++;
		taken = vec[i][1];		
	}
}

printf("%d",ans);
*/

// int a[n1],b[n1];
//  for(int i=0;i<n1;i++)
//   	scanf("%d" ,&a[i]);
  
//   for(int i=0;i<n1;i++)
//   	scanf("%d" ,&b[i]);

//   int len;
//    scanf("%d" ,&len); 
 
// printf("%d ",RodCutting(0,n1,a,b,len));

//   int sum;
//    scanf("%d" ,&sum);
// printf("%d ",CoinChange(a,n1,sum));

int p[] = {30, 35, 15, 5, 10, 20, 25} ;
int n = sizeof(p) / sizeof(p[0]) ;

int ans =Mcm(n,p);
printf("%d \n",ans);
printOptimalParens(0,n-2);








return 0;
}