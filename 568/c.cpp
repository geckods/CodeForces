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

    int n,m;
    cin>>n>>m;

    int sum=0;
    int times[n];
    for(int i=0;i<n;i++){
    	cin>>times[i];
    	sum+=times[i];
    }

    vector<int> myVec;

    int sumtillnow=0;

    int occur[101];
    memset(occur,0,sizeof(occur));

    for(int i=0;i<n;i++){
        if(i==0 || sumtillnow+times[i]<m){
            cout<<0<<" ";
        }
        else{
            int toremove = sumtillnow-(m-times[i]);
            int asd=0;
            int ans=0;
            for(int j=100;j>=1;j--){
                // cout<<j<<" ";
                if(asd+occur[j]*j<toremove){
                    asd+=occur[j]*j;
                    ans+=occur[j];
                }
                else{
                    ans+=ceil((toremove-asd)/(double)j);
                    break;
                }
            }
            cout<<ans<<" ";
        }
        sumtillnow+=times[i];
        occur[times[i]]++;
    }
}