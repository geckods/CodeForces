#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n,m;
  cin>>n;
  cin>>m;


  ll people[n+m];
  int taxi[n+m];

  for(int i=0;i<n+m;i++){
    cin>>people[i];
  }

  for(int i=0;i<n+m;i++){
    cin>>taxi[i];
  }

  ll taxilookup[m][2];
  taxilookup[0][0] = 0;
  
  ll start = 0;
  ll prevtaxi = 0;
  ll mid;
  int taxicount = 0;
/*
  for(int i=0;i<n+m;i++){
    cout<<taxi[i]<<" ";
  }
  cout<<endl;
*/

  for(int i=0;i<n+m;i++){
    if(taxi[i]==1){
      if(taxicount!=0){
        mid = (people[i]+prevtaxi)/2;
//        cout<<i<<" "<<taxicount<<" "<<mid<<endl;
        taxilookup[taxicount-1][1] = mid;
        taxilookup[taxicount][0] = mid+1;
      }
      taxicount++;
      prevtaxi = people[i];
    }
//    cout<<i<<" "<<taxi[i]<<" "<<taxicount<<endl;
  }
  taxilookup[m-1][1] = people[n+m-1]+1;

  ll taxicountarr[m];
  for(int i=0;i<m;i++){
    taxicountarr[i] = 0;
  }

  int taxino = 0;
  for(int i=0;i<n+m;i++){
    if(taxi[i]==0){
      while(people[i]>taxilookup[taxino][1]) taxino++;
      taxicountarr[taxino]++;
    }
  }

/*
  for(int i=0;i<m;i++){
    cout<<taxilookup[i][0]<<" "<<taxilookup[i][1]<<endl;
  }
*/

  for(int i=0;i<m;i++){
    cout<<taxicountarr[i]<<" ";
  }
  cout<<endl;
}
