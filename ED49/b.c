#include <stdio.h>

int main(){
  long long n,q;
  long long x,y;
  long long ind,ans;

  scanf("%lld %lld",&n,&q);
  getchar();
  
  long long arr[q][2];

  for(int i=0;i<q;i++){
    scanf("%lld %lld",&arr[i][0],&arr[i][1]);
    getchar();
  }

  for(int i=0;i<q;i++){
    x = arr[i][0]-1;
    y = arr[i][1]-1;
    ind = x*n+y;

    if(n%2==1){
      if(ind%2==0){
        ans = ind/2+1;
      }
      else{
        ans = (n*n+2+ind)/2;
      }
    }
    else{
      if((x+y)%2==0){
        if (x%2==0){
          ans = ind/2+1;
        }
        else{
          ans = (ind+1)/2;
        }
      }
      else{
        if(x%2==0){
          ans = (ind+1)/2+n*n/2;
        }
        else{
          ans = (ind+n*n+2)/2;
        }
      }
    }
    printf("%lld\n",ans);
  }
}

