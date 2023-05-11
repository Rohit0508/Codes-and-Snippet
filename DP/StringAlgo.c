#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))


int lps[100];
char t[100];
char str[100];
int n,m;

void KMP_lps(){
    for (int i = 1; i <m; i++){
        int prev = lps[i-1];
        while(prev>0 && t[i]!= t[prev]){
            prev = lps[prev-1];
        }
        if(t[i]==t[prev]) prev++;
        lps[i] = prev;
     }
}

void Search(){
    int i=0,j=0;

    while(n-i>=m-j){
        if(str[i]==t[j]){
            i++;
            j++;
        }
        if(j==m){
            printf("Pattern found at %d\n",i-j);
            j=lps[j-1];
        }
        else if(i<n && str[i]!= t[j]){
            if(j!=0) j = lps[j-1];
            else i=i+1; // leave it
        }
    }
}

int main(){
 printf("Enter the length of the string:\n");    
 scanf("%d",&n);
 printf("Enter the string:\n");    
 scanf("%s",&str);

 printf("Enter the length of the pattern:\n");    
 scanf("%d",&m);
 printf("Enter the pattern:\n");    
 scanf("%s",&t);

 KMP_lps(); // it will generate the lps array
 Search();



return 0;
}