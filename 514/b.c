#include <stdio.h>
typedef long long ll;

int main(){
  ll n,m;
 
  scanf("%lld",&n);
  getchar();
  scanf("%lld",&m);
  getchar();

  ll arr[n][m];
  ll newarr[n][m];

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      newarr[i][j] = 0;
    }
  }
  int firstindex,secondindex,canput; 

  for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
      arr[i][j] = (getchar() == '#');
    }
    getchar();
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if (i==0 || j==0 || i==(n-1) || j==(m-1)) newarr[i][j] = 1;
      
      if(arr[i][j]==0){
        for(int q=-1; q<2;q++){
          for(int w=-1;w<2;w++){
            firstindex = i+q;
            secondindex = j+w;
            
            if ((q==0 && w==0)|| firstindex<0 || firstindex>(n-1) || secondindex<0 || secondindex>(m-1)) continue;
            newarr[firstindex][secondindex] = 1;
          }
        }
      }
    }
  }

/*
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      printf("%lld ",arr[i][j]);
    }
    putchar('\n');
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      printf("%lld ",newarr[i][j]);
    }
    putchar('\n');
  }
*/
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(arr[i][j]==1){
        canput = 0;
        for(int q=-1; q<2;q++){
          for(int w=-1;w<2;w++){
            firstindex = i+q;
            secondindex = j+w;
            
            if ((q==0 && w==0)|| firstindex<0 || firstindex>(n-1) || secondindex<0 || secondindex>(m-1)) continue;

            if (newarr[firstindex][secondindex]==0){
              canput = 1;
              break;
            }
          }
          if (canput) break;
        }

        if (!canput){
          printf("NO\n");
          return 0;
        }
      }
    }
  }

  printf("YES\n");
}
        
