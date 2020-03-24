#include <stdio.h>
#include <stdlib.h>

//int union(long* arr1,long* arr2, int n, long* target){
//  for(int i=0;i


int printIntersection(long arr1[], long arr2[], int m, int n, long targ[])
{
  int i = 0, j = 0,count = 0;
  while (i < m && j < n)
  {
    if (arr1[i] < arr2[j])
       i++;
    else if (arr2[j] < arr1[i])
       j++;
    else /* if arr1[i] == arr2[j] */
    {
       targ[count] = arr1[i];
       count++;
       i++;
       j++;
    }
  }
  return count;
}

int getindex(long arr[], long x, int n){
  for(int i=0;i<n;i++){
    if (arr[i]==x)
      return i;
  }
  return -1;
}


int main(){
  int n;
  scanf("%d",&n);
  int arr[n];
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    getchar();
  }
  long sumsforward[n];
  long sumsbackward[n];

  long sum=0;

  for(int i=0;i<n;i++){
    sum += arr[i];
    sumsforward[i] = sum;
  }

  sum = 0;

  for(int i=n-1;i>=0;i--){
    sum += arr[i];
    sumsbackward[n-i-1] = sum;
  }

  long newarr[n];

  int count = printIntersection(sumsforward,sumsbackward,n,n,newarr);
  int q,w,prev=0;

  if (count==0){
    printf("0\n");
  }
  else{
    for(int i=0;i<count;i++){
      q = getindex(sumsforward,newarr[i],n);
      w = n-getindex(sumsbackward,newarr[i],n)-1;
      if (w<=q){
        printf("%d\n",prev);
        exit(0);
      }
      prev = newarr[i];
    }
  }

}

