#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//THINGS TO REMEMBER
//ENDL is slow, '\n' is fast
//Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    while(t--){
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll arr[26];
        memset(arr,0,sizeof(arr));


        vector<char> myVec;

        for(int i=0;i<n;i++){
            myVec.push_back(s[i]);
            arr[s[i]-'a']++;
        }
        sort(myVec.begin(), myVec.end());

        int lastchar=myVec[n-1]-'a';

        ll haveToDist=k;

        if(myVec[k-1]!=myVec[0]){
            cout<<myVec[k-1]<<endl;
        }
        else{
            // arr[myVec[0]]-=k;
            cout<<myVec[0];
            if(myVec[k]-'a'==lastchar){
                for(int i=0;i<ceil(((double)(n-k))/k);i++){
                    cout<<myVec[k];
                }
            }
            else{
                for(int i=k;i<n;i++){
                    cout<<myVec[i];
                }               
            }
            cout<<"\n";
        }



        // cout<<endl;
    }
}