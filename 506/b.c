#include <stdio.h>
typedef long long ll;

int main(){
  int n;
  scanf("%d",&n);

  ll arr[n];
  for(int i=0;i<n;i++){
    scanf("%lld",&arr[i]);
  }

  int longestcount = 1,count=1;

  for(int i=1;i<n;i++){
    if (2*arr[i-1]<arr[i]){
      if (count>longestcount) longestcount = count;
      count = 1;
    }
    else{
      count++;
    }
  }
  if (count>longestcount) longestcount = count;


  printf("%d\n",longestcount);
}
