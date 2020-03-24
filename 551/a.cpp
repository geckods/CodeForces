#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,t;
    cin>>n>>t;

    int s[n];
    int d[n];

    for(int i=0;i<n;i++){
    	cin>>s[i]>>d[i];
    }

    int minind = -1;
    int min = INT_MAX;

    int thecurr;
    for(int i=0;i<n;i++){
    	if(s[i]>=t) thecurr = s[i]-t;
    	else{
    		thecurr = (s[i]+ceil((t-s[i])/(double)d[i])*d[i])-t;
    	}

//    	cout<<i<<" "<<thecurr<<" "<<s[i]+ceil((t-s[i])/(double)d[i])*d[i]<<endl;

    	if(thecurr<min){
    		min = thecurr;
    		minind = i;
    	}
    }
    cout<<minind+1<<endl;

}
