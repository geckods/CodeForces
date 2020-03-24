#include <stdio.h>
#include <limits.h>
typedef long long ll;

int main(){
  ll n;
  scanf("%lld",&n);

  ll arr[n];
  ll ans=0;
  ll max=LLONG_MIN;
  ll min=LLONG_MAX;

  for(int i=0;i<n;i++){
    scanf("%lld",&arr[i]);
    if(arr[i]>max) max=arr[i];
    if(arr[i]<min) min=arr[i];
  }

  int hasseenmax=0;
  int hasseenmin=0;

  for(int i=0;i<n;i++){
    if((!hasseenmax)&(arr[i]==max)){
      ans+=max;
      hasseenmax=1;
      continue;
    }

    if((!hasseenmin)&(arr[i]==min)){
      ans-=min;
      hasseenmin=1;
      continue;
    }

    if(arr[i]>0){
      ans += arr[i];
    }
    else{
      ans -= arr[i];
    }
  }

  printf("%lld\n",ans);
}
    

