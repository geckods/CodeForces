#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//THINGS TO REMEMBER
//ENDL is slow, '\n' is fast
//Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN

ll getAns(ll x, ll axb, ll arr[], ll c){
    ll ans=c*(x/axb) + arr[x%axb];
    // for(int i=0;i<=x%axb;i++){
    //     if(arr[i])ans++;
    // }
    return ans;
}


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
        ll a,b,q;
        cin>>a>>b>>q;
        
        if(a<b){
            swap(a,b);
        }

        ll count=0;
        // bool arr[a*b];
        ll axb=a*b;
        ll cumArr[axb];
        cumArr[0]=0;
        for(int i=1;i<axb;i++){
            cumArr[i]=cumArr[i-1];
            if((i%a)%b != (i%b)%a){
                cumArr[i]++;
                count++;
            }
            else{
            }
        }

        ll quer[q][2];
        for(int i=0;i<q;i++){
            cin>>quer[i][0]>>quer[i][1];
            cout<<getAns(quer[i][1],axb,cumArr,count)-getAns(quer[i][0]-1,axb,cumArr,count)<<' ';
        }
        cout<<endl;

    }
}