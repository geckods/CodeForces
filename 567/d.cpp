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


   	ll n,m,q;
   	cin>>n>>m>>q;

   	int chosencount[m];
   	for(int i=0;i<m;i++){
   		chosencount[i]=0;
   	}

   	int x;
   	for(int i=0;i<n;i++){
   		cin>>x;
   		x--;
   		chosencount[x]++;
   	}

   	