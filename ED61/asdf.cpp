#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define MOD2 100000000
#define ll long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(v) v.begin(),v.end()
ll mod=MOD;

using namespace std;
long long int fast_exp(long long int base,long long int ex) {
    long long int res=1;
    while(ex>0) {
       if(ex%2==1) res=(res*base)%mod;
       base=(base*base)%mod;
       ex/=2;
    }
    return res%mod;
}
long long int gcd(long long int a, long long int b)
{
    if(b==0)return a;
     return gcd(b,a%b);
}


int main()
{

    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,q;
    cin>>n>>q;
   ll pa[n+1];
   memset(pa,0,sizeof(pa));
   ll ans=0;
   ll lq[q]; ll rq[q];
   for(int i=0;i<q;i++)
   {
       cin>>lq[i]>>rq[i];
       pa[lq[i]]++;
       if(rq[i]!=n)pa[rq[i]+1]--;
   }
   for(int i=2;i<=n;i++)
    pa[i]+=pa[i-1];
   ll co[n+1];
   memset(co,0,sizeof(co));
   ll cs[n+1];
   memset(cs,0,sizeof(cs));
   ll tot=0;
   for(int i=1;i<=n;i++)
   {
       co[i]=co[i-1];
       if(pa[i]==1)co[i]++;
       cs[i]=cs[i-1];
       if(pa[i]==2)cs[i]++;
       if(pa[i])tot++;
   }
   ll ma=0;
   for(int i=0;i<q;i++)
   {
       for(int j=i+1;j<q;j++)
       {
           ll r=co[rq[i]]-co[lq[i]-1];
               r+=co[rq[j]]-co[lq[j]-1];
                ll l=max(lq[i],lq[j]);
               ll dr=min(rq[i],rq[j]);
               if(l<=dr)
               r+=cs[dr]-cs[l-1];
               ll ans=tot-r;
           ma=max(ans,ma);

       }
   }
    cout<<ma;


   return 0;
}