//when equal pick cheapest
// otherwise scale prices of max party by 2


#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

long long maxofarr(long long arr[],long long x,long long *ma){

  long long max=arr[0];
  long long maxind = 0;

  for(long long i=0;i<x;i++){
    if (arr[i]>=max){
      max = arr[i];
      *ma = max;
      maxind = i;
    }
  }

  return maxind;
}

long long minofarr(long long arr[],long long votearray[][2],long long x,long long *mi,long long maxparty){

  long long min=arr[0];
  *mi = min;
  long long minind = 0;
  long long flag=0;
  for(long long i=0;i<x;i++){
    if (arr[i]<=min){
      min = arr[i];
      *mi = min;
      minind = i;
    }
//    else if (arr[i]==min && votearray[i][0]==maxparty){
//      minind = i;
//    }
  }

  return minind;
}

int main(){
  long long n,m;
  scanf("%I64d",&n);
  getchar();
  scanf("%I64d",&m);
  getchar();


  long long arr[n][2];
  
  for(long long i=0;i<n;i++){
//    printf("H");
    scanf("%I64d",&arr[i][0]);
    arr[i][0]--;
//    printf("%I64d",arr[i][0]);
    getchar();
    scanf("%I64d",&arr[i][1]);
    getchar();
  }
//  printf("%I64d %I64d",n,m);
//  printf("HI");

  long long votearray[m];
 
  for(long long i=0;i<m;i++){
    votearray[i] = 0;
  }

  for(long long i=0;i<n;i++){
    votearray[arr[i][0]]++;
  }

  long long *ma = malloc(sizeof(long long));
  long long *mi = malloc(sizeof(long long));
  long long minind;
  long long costs[n];
  long long currmax;
  long long ans = 0;
 

  while((currmax=maxofarr(votearray,m,ma)) != 0 && votearray[0]<=1500){
    //for(long long i=0;i<m;i++){
    //  printf("%I64d ",votearray[i]);
    //}
    //putchar('\n');
    if(*ma != votearray[0]){
      for(long long i=0;i<n;i++){
        if (arr[i][0] == 0){
          costs[i] = LLONG_MAX;
          continue;
        }
        if (arr[i][0] == currmax){
          costs[i] = (arr[i][1]/2);
//          if(arr[i][1]%2==1) costs[i]++;
        }
        else{
          costs[i] = arr[i][1];
        }
      }
      
      minind = minofarr(costs,arr,n,mi,currmax);
      ans += (*mi);

      if (arr[minind][0] == currmax){
        ans += (*mi);
      }
      

      votearray[0]++;
      votearray[arr[minind][0]]--;
      arr[minind][0] = 0;
    }

    else{
      for(long long i=0;i<n;i++){
        if (arr[i][0] == 0){
          costs[i] = LLONG_MAX;
          continue;
        }
        costs[i] = arr[i][1];
      }
    
      
      minind = minofarr(costs,arr,n,mi,currmax);
      ans += (*mi);


      votearray[0]++;
      votearray[arr[minind][0]]--;
      arr[minind][0] = 0;

    }
  }
  //for(long long i=0;i<m;i++){
  //  printf("%I64d ",votearray[i]);
  //}
  printf("%I64d\n",ans);
}
