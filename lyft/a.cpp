#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll n,x,y;
  cin>>n;
  cin>>x;
  cin>>y;

  if(x+y <= n+1){
    cout<<"White\n";
  }
  else{
    cout<<"Black\n";
  }
}
