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

    int n,k,m;
    cin>>n>>k>>m;

    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    sort(arr,arr+n);


    ll totsum=0;
    for(int i=0;i<n;i++){
    	totsum+=arr[i];
    }

    ll cumulative[n];
    ll cum=0;
    for(int i=0;i<n;i++){
    	cumulative[i]=cum;//how much you remove by deleting i dudes
    	cum+=arr[i];
    }

    double maxave=0;
    for(int i=0;i<n;i++){

    	if(i>m) break;

    	ll sum=totsum;
    	int count = n;

    	//delete the first i dudes
    	sum-=cumulative[i];
    	count-=i;

    	//distribute the rest of your moves amongst the other guys
    	ll additions = min((ll)m-i,(ll)(n-i)*k);

//    	if(n==100000 && m==52)
//    	cout<<i<<" "<<sum<<" "<<count<<" "<<additions<<" "<<m-i<<endl;

    	double ave = (sum+additions)/(double)count;
    	if(ave>maxave) maxave=ave;
    }

    cout.precision(17);
    cout<<maxave<<endl;

}