#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int parent[26];
int therank[26];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    therank[v] = 0;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (therank[a] < therank[b])
            swap(a, b);
        parent[b] = a;
        if (therank[a] == therank[b])
            therank[a]++;
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

    unordered_set<char> seenchars;
    for(int i=0;i<26;i++){
    	make_set(i);
    }

    for(int i=0;i<n;i++){
    	string s;
    	cin>>s;

    	unordered_set<char> thisstring;
    	for(int i=0;i<s.size();i++){
    		seenchars.insert(s[i]);
    		thisstring.insert(s[i]);
    	}
	    // cerr<<"HI"<<endl;

    	int first=s[0]-'a';
    	int temp;
    	for(auto it = thisstring.begin();it!=thisstring.end();it++){
    		temp=(*it)-'a';
    		if(temp!=first)
	    		union_sets(first,temp);
    	}
    }

    unordered_set<int> ans;
    for(auto it=seenchars.begin();it!=seenchars.end();it++){
    	ans.insert(find_set((*it)-'a'));
    }

    cout<<ans.size()<<endl;

}