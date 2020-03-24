#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> intpair;


int vowelcount(string s){
	int ans=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
			ans++;
		}
	}
	return ans;
}

int lastvowel(string s){
	int i=s.length()-1;
	while(i>=0 && !((s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'))){
		i--;
	}

	if(i<0) return -1;
	switch(s[i]){
		case 'a':
			return 0;
		case 'e':
			return 1;
		case 'i':
			return 2;
		case 'o':
			return 3;
		case 'u':
			return 4;
		default:
			return -1;
	}
}

map<intpair, int> seenMap; 
bool comparemy(intpair int1, intpair int2){
	return seenMap[int1]<seenMap[int2];
}

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<string> myVec;
    string s;

    map<intpair, stack<string> > myMap;

    int maxlen=0;
    int vc;
    int lv;
    intpair mypair;

    for(int i=0;i<n;i++){
    	cin>>s;
    	maxlen=max(0,(int)s.length());
    	vc = vowelcount(s);
    	lv = lastvowel(s);
    	mypair = make_pair(vc,lv);

    	if(seenMap[mypair]==0){
    		myMap[mypair] = stack<string>();
    	}
    	seenMap[mypair]++;
    	myMap[mypair].push(s);
    	myVec.push_back(s);
    }


    stack<intpair> hasodd;
    vector<intpair> canform;

    map<intpair, int>::iterator it;
    for(it=seenMap.begin();it!=seenMap.end();it++){
    	// cerr<<(*it).first.first<<" "<<(*it).first.second<<endl;
		canform.push_back(it->first);
		if(it->second%2==1)hasodd.push(it->first);
    }

    sort(canform.begin(),canform.end(),comparemy);

    vector<vector<string> > ans;

    while(1){
    	if(canform.empty()) break;
    	string firstword;
    	intpair temp;
    	bool cf=false;
    	if(!hasodd.empty()){
    		temp = hasodd.top();
    		hasodd.pop();
    	}
    	else{
    		temp=*canform.end();
    		cf = true;
    	}

    	seenMap[temp]--;

    	if(seenMap[temp]%2==1){
    		hasodd.push(temp);
    	}
    	if(seenMap[temp]==0 && cf){
    		canform.erase(canform.end());
    	}

    	firstword = myMap[temp].top();
    	myMap[temp].pop();

    	if(canform.empty()) break;

    	string secondword;
    	// intpair temp;
    	cf=false;
    	if(!hasodd.empty()){
    		temp = hasodd.top();
    		hasodd.pop();
    	}
    	else{
    		cf = true;
    		temp=*canform.end();
    	}

    	seenMap[temp]--;

	    cerr<<"HI"<<temp.first<<" "<<temp.second<<" "<<cf<<"	"<<(*canform.end()).first<<endl;
    	if(seenMap[temp]%2==1){
    		hasodd.push(temp);
    	}
    	if(seenMap[temp]==0 && cf){
    		canform.erase(canform.end());
    	}

    	secondword = myMap[temp].top();
    	myMap[temp].pop();

    	if(canform.empty()) break;

    	string thirdword;
    	temp=*canform.end();
    	seenMap[temp]--;
    	thirdword=myMap[temp].top();
    	myMap[temp].pop();

    	if(seenMap[temp]==0 && temp == *canform.end()){
    		canform.erase(canform.end());
    	}
    	if(canform.empty()) break;

    	string fourthword;

    	temp=*canform.end();
    	seenMap[temp]--;
    	fourthword=myMap[temp].top();
    	myMap[temp].pop();

    	if(seenMap[temp]==0 && temp == *canform.end()){
    		canform.erase(canform.end());
    	}

    	vector<string> minians;
    	minians.push_back(firstword);
    	minians.push_back(thirdword);
    	minians.push_back(secondword);
    	minians.push_back(fourthword);
    	ans.push_back(minians);   	    	    	
    }

    cout<<ans.size()<<endl;
}