#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))


void swap(int *a ,int *b){
	int tmp = *a;
	 *a = *b;
	 *b = tmp;
}
// int inf= 1e6;

// int coinChange(int i,int a[],int amt){
//   if(amt==0) return 0;
//   if(i<=0) return inf;

//    int ans =inf;
//    if(amt>=a[i])
//     ans = min(ans,1+coinChange(i,a,amt-a[i]));
   
//    ans = min(ans,coinChange(i-1,a,amt));

// return ans;
// }


//********** Priority_Queue **************
int limit =20;

void maxHepify(int i,int a[]){
  int left = 2*i;
  int right = 2*i+1;
  int largest =i;

  if(left<limit && a[left]>a[i])
    largest = left;

  if(right<limit && a[right]>a[largest])
    largest = right;

  if(largest !=i){
    swap(&a[i],&a[largest]);
    maxHepify(largest,a);
  }    
}

void Bulid(int a[]){
  for (int i =limit/2; i>=0; i--){
    maxHepify(i,a);
  }
}

int top(int a[]){
  int val = a[0];
  swap(&a[0],&a[limit-1]);
  maxHepify(0,a);
  limit--;
return val;  
}

void HeapSort(int a[]){
  Bulid(a);
  int sz=limit;
  for (int i =sz-1; i>=0; i--){
    swap(&a[0],&a[i]);
    limit--;
    maxHepify(0,a);
  }
  limit = sz;
}


//***************************************************

int main(){
 scanf("%d" ,&limit);
 int a[limit];

 for(int i=0;i<limit;i++){
  	scanf("%d" ,&a[i]);
 }							
  // int amt;
  // scanf("%d" ,&amt);

// int ans = coinChange(n-1,a,amt);
// printf("%d",ans);  

 printf("\n");
  Bulid(a);

 for(int i=0;i<limit;i++){
  printf("%d ",a[i]);  
 }
//  int val =top(a);
//  printf("\n%d",val);
 printf("\n");
  
//   HeapSort(a);
//  for(int i=0;i<limit;i++){
//   printf("%d ",a[i]);  
//  }



     









return 0;
}