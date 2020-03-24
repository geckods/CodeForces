#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string padzero(int x){
	string ans=to_string(x);
	while(ans.size()<4){
		ans='0'+ans;
	}
	return ans;
}

bool mysort(pair<int,int> a, pair<int,int> b){
	return a.second<b.second;
}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    for(int test=0;test<t;test++){
    	int n;
    	cin>>n;

    	vector<pair<int,int> > arr;
    	int x;
    	for(int i=0;i<n;i++){
    		cin>>x;
    		arr.push_back({x,i});
    	}
    	sort(arr.begin(),arr.end());

 		set<int> unused;
 		for(int i=0;i<10;i++){
 			unused.insert(i);
 		}

 		for(int i=0;i<n;i++){
 			if(unused.find(arr[i].first/1000)!=unused.end()){
 				unused.erase(unused.find(arr[i].first/1000));
 			}
 		}

 		// cout<<unused.size()<<endl;

 		int ans=0;
 		for(int i=0;i<n-1;i++){
 			// cout<<arr[i].first<<" "<<arr[i+1]<<endl;
 			if(arr[i].first==arr[i+1].first){
 				ans++;
 				arr[i].first=(arr[i].first%1000)+(*unused.begin())*1000;
 				unused.erase(unused.begin());
 			}
 		}

 		sort(arr.begin(),arr.end(),mysort);

 		cout<<ans<<endl;
 		for(int i=0;i<n;i++){
 			cout<<padzero(arr[i].first)<<endl;
 		}

    }
}