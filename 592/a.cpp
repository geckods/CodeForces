#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);

  	int t;
  	cin>>t;

  	for(int test=0;test<t;test++){
  		int a,b,c,d,k;
  		cin>>a>>b>>c>>d>>k;

  		int pen = ceil(((double)a)/c);
  		int penc = ceil(((double)b)/d);

  		if(pen+penc>k){
  			cout<<-1<<endl;
  		}
  		else{
  			cout<<pen<<" "<<penc<<endl;
  		}
  	}

}
