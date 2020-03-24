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

    string s;
    cin>>s;

    int n = s.length();

    int first91=0;
    while(first91<n && s[first91]!='[') first91++;

    int firstcolon=first91;
	while(firstcolon < n && s[firstcolon]!=':') firstcolon++;

    int last93=n-1;
    while(last93>=0 && s[last93]!=']') last93--;

    int lastcolon=last93;
	while(lastcolon>=0 && s[lastcolon]!=':') lastcolon--;

	if(first91==n || firstcolon==n || last93 == -1 || lastcolon == -1 || lastcolon <= firstcolon){
		cout<<-1<<endl;
		return 0;
	}

	int ans=4;
	while(firstcolon<lastcolon){
		if(s[firstcolon] == '|') ans++;
		firstcolon++;
	}

	cout<<ans<<endl;


}