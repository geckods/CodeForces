#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void soe(int n) 
{ 
    bool prime[n+1];
    int ans[n+1];
    memset(prime, true, sizeof(prime)); 
    memset(ans, 0, sizeof(ans));

    int k=1;
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        {
            // cout<<"HI"<<endl;
            for (int i=p; i<=n; i += p){
                if(i>p) prime[i] = false; 
                ans[i]=k;
            }
            k++;
        } 
    }

    for(int i=2;i<=n;i++){
        if(ans[i]==0){
            ans[i]=k++;
        }
    }

    for(int i=2;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    soe(n);
}
