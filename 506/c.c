#include <stdio.h>
#include <limits.h>

typedef long long int ll;

int main(){
  int n;
  scanf("%d",&n);
  
  ll segments[n][2];

  ll maxli=0,minri=LLONG_MAX,secmaxli=0,secminri=LLONG_MAX;
  ll li,ri;

  int maxliind=0,minriind=0,secmaxliind=0,secminriind=0;

  for(int i=0;i<n;i++){
    scanf("%I64d",&li);

    if (li>maxli){
      secmaxli = maxli;
      secmaxliind = maxliind;

      maxli = li;
      maxliind = i;
    }
    else if (li>secmaxli){
      secmaxli = li;
      secmaxliind = i;
    }
    getchar();

    scanf("%I64d",&ri);

    if (ri<minri){
      secminri = minri;
      secminriind = minriind;

      minri = ri;
      minriind = i;
    }
    else if (ri<secminri){
      secminri = ri;
      secminriind = i;
    }
    getchar();

  }

  ll ans;

  if(maxliind == minriind){
    ans = secminri-secmaxli;
  }
  else{
    if (minri-secmaxli>secminri-maxli){
      ans = minri-secmaxli;
    }
    else {
      ans = secminri-maxli;
    }
  }

  ans = (ans>=0)?ans:0;
//  printf("maxli:%d-%d secmaxli:%d-%d minri:%d-%d secminri:%d-%d\n",maxli,maxliind,secmaxli,secmaxliind,minri,minriind,secminri,secminriind);
  printf("%I64d\n",ans);
}
