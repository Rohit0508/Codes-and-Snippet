#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a ,const void* b){
	return (*(int*)a - *(int*)b);
} 

void swap(int *a ,int *b){
	int tmp = *a;
	 *a = *b;
	 *b = tmp;
}

/*
// *******QuickSort***************
int partition(int a[],int l,int r){
	int i=l,j=l;
	int pivot = a[r];
	while(i<r){
		if(a[i]<= a[r]){
			swap(&a[j],&a[i]);
			j++;
		}		
	   i++;	
	}
swap(&a[r],&a[j]);
return j;
}

void QuickSort(int a[],int l,int r){
	if(l<r){
		int q =partition(a,l,r);
		QuickSort(a,l,q-1);
		QuickSort(a,q+1,r);
	}
} 


//************** ith Order Statics***************
int ithOrderStatics(int a[],int k,int l,int r){
	if(l<r){
		int pivot =partition(a,l,r);
		int j = pivot-l+1;
		if(k==j) return a[pivot];
		if(k<j) return ithOrderStatics(a,k,l,pivot-1);
		else return ithOrderStatics(a,k-j,pivot+1,r);
	}		
}

*/





int main(){
 int n;
 scanf("%d" ,&n);
 int a[n];
 for(int i=0;i<n;i++){
  	scanf("%d" ,&a[i]);
 }

 int b[n];
 for(int i=0;i<n;i++){
  	scanf("%d" ,&b[i]);
 }							

//  qsort(a,n,sizeof(int),cmp); 
// QuickSort(a,0,n-1);			
//  for(int i=0;i<n;i++){
// 	int k= ithOrderStatics(a,i+1,0,n-1);
//   	printf("%d\n" ,k);
//  }







return 0;
}