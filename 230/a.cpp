#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	string s;
   	cin>>s;

   	int occ[256];
   	for(int i=0;i<256;i++){
   		occ[i]=0;
   	}

   	for(int i=0;i<s.size();i++){
   		occ[s[i]]++;
   	}

   	cout<<min(min(min((occ['n']-1)/2,occ['e']/3),occ['i']),occ['t'])<<endl;

}
