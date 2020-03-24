#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define maxn 100002
 
typedef struct FenwickTree {
    vector<ll int> bit;  // binary indexed tree
    ll int n;
 
    FenwickTree(ll int n) {
        this->n = n;
        bit.assign(n, 0);
    }
 
    FenwickTree(vector<ll int> a) : FenwickTree(a.size()) {
        for (ll int i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
 
    int sum(ll int r) {
        ll int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
 
    int sum(ll int l, ll int r) {
        return sum(r) - sum(l - 1);
    }
 
    void add(ll int idx, ll int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
}FenwickTree;
 
int main()
{
//     #ifndef ONLINE_JUDGE
//         freopen("input", "r", stdin);
//     	freopen("output", "w", stdout);
// 	#endif
// 	ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
 
    ll int n,k,j;
    cin>>n>>k;
    ll int i;
    vector<ll int> arr;
    ll int x;
    for(i=0;i<n;i++)
    {
        cin>>x;
        arr.push_back(x);
    }
 
    FenwickTree ftree = FenwickTree(arr);
    //ftree.add(1,5);
    //cout<<ftree.sum(1,n-1)<<endl;
    ll int low;
    ll int high;
    ll int mid; 
    ll int prevmid;
    
    ll int index=0;
    ll int newval;
    ll int diff;
 
    for(i=0;i<n;i++)
    {
        low = i;
        high = n-1;
        mid=0;
        prevmid=-1;
        while(1)
        {
            mid=(low+high)/2;
 
            if(prevmid==mid)
            {
                break;
            }
 
            //cout<<ftree.sum(i,mid)<<" "<<k<<endl;
            if(ftree.sum(i,mid)>k)
            {
                high=mid-1;
            }
            else
            {
                low=mid;
            }
 
            prevmid=mid;
            
        }
        // if(ftree.sum(i,mid)>k)
            // mid--;
       
        x = ftree.sum(i,high);
       
        index = (i+x)%n;
        
        newval = (k^x);
        
        diff = newval - ftree.sum(index,index);
        ftree.add(index,diff);
        cout<<"high "<<high<<endl;
        cout<<"i: "<<i<<" X: "<<x<<endl;
        cout<<"i: "<<i<<" index: "<<index<<endl;
        cout<<"i: "<<i<<" newval: "<<newval<<endl;
        cout<<"NEW TREE"<<endl;
        for(j=0;j<n;j++)
        {
            cout<<ftree.sum(j,j)<<" ";
        }
        cout<<endl<<endl;
 
    }
 
    ll int ans = ftree.sum(n-1);
    cout<<ans<<endl;
 
 
}