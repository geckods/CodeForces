#include <stdio.h>

int longestincseq(int arr[], int n){
  int seqarr[n];
  int temp;
  seqarr[0]=1;
  int max;
  for(int i=1;i<n;i++){
    max = 1;
    for(int j=0;j<i;j++){
      if (arr[i]>arr[j]){
        temp = seqarr[j]+1;
        if (temp>max){
          max = temp;
        }
      }
    }
    seqarr[i] = max;
  }

  int newmax=seqarr[0];
  for(int i=1;i<n;i++){
//    printf("%d--",seqarr[i]);
    if (seqarr[i]>newmax)newmax = seqarr[i];
  }

  return newmax;
}

int longestdecseq(int arr[], int n){
  int seqarr[n];
  int temp;
  seqarr[0]=1;
  int max;
  for(int i=1;i<n;i++){
    max = 1;
    for(int j=0;j<i;j++){
      if (arr[i]<arr[j]){
        temp = seqarr[j]+1;
        if (temp>max){
          max = temp;
        }
      }
    }
    
    seqarr[i] = max;
  }

  int newmax=seqarr[0];
  for(int i=1;i<n;i++){
    if (seqarr[i]>newmax)newmax = seqarr[i];
  }

  return newmax;
}

      
/*
int main(){
  int x = 100;
  for(
  printf("%d %d\n",longestincseq(arr,x),longestdecseq(arr,x));
}
*/


int main(){
  int n;
  scanf("%d",&n);
  int arr[n];
  int z=1;
  while(z**2<n){
    z++;
  }
  z--;
  
  int no = n/z;

  int a = 0;
  for(int i=no*z+1;i<=n;i++){
    arr[a] = i;
    a++;
  }

  for(int i=0;i<(n-no*z+1);i++){
    for(int j=i;j>0;
}  

  
