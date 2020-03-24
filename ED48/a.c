#include <stdio.h>

int main(){
  int n,m;
  scanf("%d",&n);getchar();scanf("%d",&m);
  int arr[n];

  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }

  int counter=0;
  int daycount=0;

  for(int i=0;i<n;i++){
    daycount=arr[i]/m;
    counter+=arr[i]%m;
    
    if (counter>=m){
      daycount++;
      counter%=m;
    }
    printf("%d ",daycount);
  }
  putchar('\n');
}
