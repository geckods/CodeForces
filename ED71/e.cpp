#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

	// #ifndef ONLINE_JUDGE
 //    	freopen("input", "r", stdin);
 //    	freopen("output", "w", stdout);
	// #endif
	// ios_base::sync_with_stdio(false);
   	// cin.tie(NULL);

   	vector<int> myVec;

   	for(int i=1;i<101;i++){
   		int asd=0;
   		for(int j=0;j<14;j++){
   			asd+=(i/(int)pow(2,j)%2)*pow(2,2*j);
   		}
   		myVec.push_back(asd);
   	}
   	cout<<"?"<<" ";
   	for(int i=0;i<myVec.size();i++){
   		cout<<myVec[i]<<" ";
   	}
   	fflush(stdout);
   	int x;
   	cin>>x;//has even bits from left

   	int ans=0;
   	x/=2;
   	for(int j=0;j<7;j++){
   		ans+=pow(2,(2*j)+1)*(x%2);
   		x/=4;
   	}

   	myVec.clear();
   	for(int i=1;i<101;i++){
   		int asd=0;
   		for(int j=0;j<14;j++){
   			asd+=(i/(int)pow(2,j)%2)*pow(2,2*j+1);
   		}
   		myVec.push_back(asd);
   	}
   	cout<<"?"<<" ";
   	for(int i=0;i<myVec.size();i++){
   		cout<<myVec[i]<<" ";
   	}
   	fflush(stdout);
   	cin>>x;

   	// x/=2;
   	for(int j=0;j<7;j++){
   		ans+=pow(2,(2*j))*(x%2);
   		x/=4;
   	}
   	cout<<"!"<<" "<<ans<<endl;
   	fflush(stdout);
   	return 0;
}