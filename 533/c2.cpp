#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll P = 1000000007; 

ll genzero(ll a,ll b,ll c,ll n,ll arr[][3]);
ll genone(ll a,ll b,ll c,ll n,ll arr[][3]);
ll gentwo(ll a,ll b,ll c,ll n,ll arr[][3]);


ll genzero(ll a,ll b,ll c,ll n,ll arr[][3]){
    if(n==1){
        return a;
    }

    ll ans = arr[n][0];
    if(ans!=-1) return ans;

    ans = genzero(a,b,c,n-1,arr)*a+genone(a,b,c,n-1,arr)*c+gentwo(a,b,c,n-1,arr)*b;
    ans = ans%P;
    arr[n][0]=ans;
    return ans;
}

ll genone(ll a,ll b,ll c,ll n,ll arr[][3]){
    if(n==1){
        return b;
    }

    ll ans = arr[n][1];
    if(ans!=-1) return ans;

    ans = genzero(a,b,c,n-1,arr)*b+genone(a,b,c,n-1,arr)*a+gentwo(a,b,c,n-1,arr)*c;
    ans = ans%P;
    arr[n][1]=ans;
    return ans;
}

ll gentwo(ll a,ll b,ll c,ll n,ll arr[][3]){
    if(n==1){
        return c;
    }

    ll ans = arr[n][2];
    if(ans!=-1) return ans;

    ans = genzero(a,b,c,n-1,arr)*c+genone(a,b,c,n-1,arr)*b+gentwo(a,b,c,n-1,arr)*a;
    ans = ans%P;
    arr[n][2]=ans;
    return ans;
}

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    ll a,b,c;

    ll n,l,r;
    cin>>n>>l>>r;

    ll nextthreepow = l;
    while(nextthreepow%3!=0) nextthreepow++;

    ll prevthreepow = r;
    while(prevthreepow%3!=0) prevthreepow--;

    a = (prevthreepow-nextthreepow)/3 + 1;
    b = a-1;
    if(l==nextthreepow-2) b++;
    if(r>prevthreepow) b++;

    c = a-1;
    if(l<nextthreepow) c++;
    if(r==prevthreepow+2)c++;

    ll arr[n+1][3];
    arr[0][0]=a;
    arr[0][1]=b;
    arr[0][2]=c;
    for(ll i=1;i<=n;i++){
        arr[i][0]=-1;
        arr[i][1]=-1;
        arr[i][2]=-1;
    }

//    cout<<a<<" "<<b<<" "<<c<<endl;
    for(ll i=1;i<n;i++){
        genzero(a,b,c,i,arr);
        genone(a,b,c,i,arr);
        gentwo(a,b,c,i,arr);
//        cout<<i<<endl;
//        cout<<genzero(a,b,c,i,arr)<<endl;
//        cout<<genone(a,b,c,i,arr)<<endl;
//        cout<<gentwo(a,b,c,i,arr)<<endl;
//        cout<<endl;
    }
//    cout<<arr[2][1]<<endl;
//   cout<<genzero(a,b,c,n-1,arr)*a+genone(a,b,c,n-1,arr)*c+gentwo(a,b,c,n-1,arr)*b<<endl;
    cout<<genzero(a,b,c,n,arr)<<endl;

}
