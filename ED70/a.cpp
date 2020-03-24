#include <bits/stdc++.h>
using namespace std;

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
   		string x,y;
   		cin>>x;
   		cin>>y;

   		reverse(x.begin(),x.end());
   		reverse(y.begin(),y.end());

   		int i=0;
   		while(y[i]=='0')i++;
   		int j=i;
   		while(x[j]=='0')j++;
   		cout<<j-i<<endl;
   	}
}
