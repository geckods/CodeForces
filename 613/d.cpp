#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int minval(vector<int> asd, int x){
	if(asd.size()==0){
		return 0;
	}

	if(x==0){
		for(int i=0;i<asd.size()-1;i++){
			if((asd[i]&1)!=(asd[i+1]&1)){
				return 1;
			}
		}
		return 0;
	}
	else{
		vector<int> z;
		vector<int> o;
		for(int i=0;i<asd.size();i++){
			if(asd[i]&(1<<x)){
				o.push_back(asd[i]);
			}
			else{
				z.push_back(asd[i]);
			}
		}

		// cerr<<o.size()<<" "<<z.size()<<endl;
		int one=minval(o,x-1);
		int two=minval(z,x-1);
		cerr<<x<<" "<<one<<" "<<two<<" "<<asd.size()<<endl;
		return min(max((1<<x)+one,two),max((1<<x)+two,one));
	}
}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> arr;
    int x;
    for(int i=0;i<n;i++){
    	cin>>x;
	    arr.push_back(x);
    }

    cout<<minval(arr,30)<<endl;

}
