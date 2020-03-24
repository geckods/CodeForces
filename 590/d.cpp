#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	string s;
   	cin>>s;

   	int n=s.length();

   	int q;
   	cin>>q;

   	vector<unordered_map<char,int, custom_hash> > myVec;

   	int csq=ceil(sqrt(n));

   	for(int i=0;i<n;i+=csq){
   		int j=min(i+csq,n);
   		unordered_map<char,int, custom_hash> miniSet;
   		for(int z=i;z<j;z++){
   			miniSet[s[z]]++;
   		}
   		myVec.push_back(miniSet);
   	}

   	// cout<<myVec.size()<<endl;

   	int x;
   	int pos;
   	char z;
   	int l,r;
   	for(int quer=0;quer<q;quer++){
   		cin>>x;
   		if(x==1){
   			cin>>pos;
   			cin>>z;
   			pos--;
   			myVec[pos/csq][s[pos]]--;
   			myVec[pos/csq][z]++;
   			s[pos]=z;
   		}
   		else{
   			cin>>l>>r;
   			l--;
   			r--;

   			unordered_set<char, custom_hash> miniSet;

   			while(l%csq!=0){
   				if(l==r)break;
   				miniSet.insert(s[l++]);
   			}

   			while(r%csq!=0){
   				if(l==r)break;
   				miniSet.insert(s[r--]);
   			}

			while(l<r){
				for(char asd = 'a';asd<='z';asd++){
					if(myVec[l/csq][asd]>0){
						miniSet.insert(asd);
					}
				}
				l+=csq;
			}

   			if(l==r){
   				miniSet.insert(s[l]);
   			}
   			cout<<miniSet.size()<<endl;
   		}
   	}
}
