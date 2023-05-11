#include<stdio.h>
int main(){
int arr[]={50,25,10,5,1};
int n;
printf("enter the value of money:");
scanf("%d",&n);

int c=0;
int j;
int arr1[500];
int i=0;
for(j=0;j<5;j++){
while(n/arr[j]>0){
arr1[i++]=arr[j];
c++;
n=n-arr[j];
}
}
printf("the coin changes is:%d\n",c);
for(int i=0;i<c;i++){
printf("%d ",arr1[i]);
}
return 0;
}
