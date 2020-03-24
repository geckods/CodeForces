#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAXN 300001

map<int,set<int>> xors;
int xorCount;
int setCount;
map<int,set<int>> andnands;



bool toSet[MAXN];
bool toNotSet[MAXN];

void setProp(int i);
void notSetProp(int i);

void setProp(int i){
	// cerr<<"HI"<<i<<endl;
	if(!toSet[i])
		setCount++;
	toSet[i]=true;

	int c;

	set<int> newXors=xors[i];
	for(auto j=newXors.begin();j!=newXors.end();j++){
	// cerr<<"aaaHI"<<i<<endl;
		c=*j;
		if(xors[c].find(i)!=xors[c].end())
			xors[c].erase(xors[c].find(i));
		xors[i].erase(c);
		xorCount--;
		notSetProp(c);
	}
	// cerr<<"HERE"<<xors[i].size()<<endl;
	// xors[i].clear();

	set<int> newandNands=andnands[i];
	for(auto j=newandNands.begin();j!=newandNands.end();j++){
		c=*j;
		if(andnands[c].find(i)!=andnands[c].end())
			andnands[c].erase(andnands[c].find(i));
		andnands[i].erase(c);
		setProp(c);
	}
	// andnands[i].clear();

}

void notSetProp(int i){
	// cerr<<"nHI"<<i<<endl;

	toNotSet[i]=true;

	int c;
	set<int> newXors=xors[i];
	for(auto j=newXors.begin();j!=newXors.end();j++){
		// if()
		c=*j;
		if(xors[c].find(i)!=xors[c].end())
			xors[c].erase(xors[c].find(i));
		xors[i].erase(c);
	// cerr<<"nnnHI"<<i<<endl;
		xorCount--;
		setProp(c);
	}
	// xors[i].clear();
	set<int> newandNands=andnands[i];
	for(auto j=newandNands.begin();j!=newandNands.end();j++){
		c=*j;
		// cerr<<"AAA"<<endl;
		if(andnands[c].find(i)!=andnands[c].end())
			andnands[c].erase(andnands[c].find(i));
		andnands[i].erase(c);
		notSetProp(c);
	}
	// andnands[i].clear();

}

void doCheck(int a, int b){
	// cerr<<"nnHI"<<a<<" "<<b<<endl;
	if(toSet[a])setProp(a);
	else if (toNotSet[a])notSetProp(a);
	if(toSet[b])setProp(b);
	else if (toNotSet[b])notSetProp(b);

}



int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0;i<MAXN;i++){
    	toSet[i]=toNotSet[i]=false;
    }
    setCount=0;
    xorCount=0;

    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    //store (could have dones) in case of multiple ways

    //each time -> you can get a set, a reset, an and, an xor, or a nand

    // vector<set<int> > lampSets(k);
    int whichSet[n][2];
    for(int i=0;i<n;i++){
    	whichSet[i][0]=whichSet[i][1]=-1;
    }

    for(int i=0;i<k;i++){
    	int c,d;
    	cin>>c;
    	for(int j=0;j<c;j++){
    		// lampSets[]
    		cin>>d;
    		d--;
    		if(whichSet[d][0]==-1){
    			whichSet[d][0]=i;
    		}
    		else{
    			whichSet[d][1]=i;    			
    		}
    	}
    }


    for(int i=0;i<n;i++){
    	cerr<<i<<" "<<whichSet[i][0]<<" "<<whichSet[i][1]<<endl;
    	if(whichSet[i][0]==-1){
	    	cout<<setCount+ceil(xors.size()/4.0)<<endl;
    		continue;
    	}
    	if(s[i]=='0'){
    		//either set or xor
    		if(whichSet[i][1]==-1){
    			//SET PROPOGATE
    			setProp(whichSet[i][0]);
    		}
    		else{
    			xorCount++;
    			//XOR propogate new pair (check if already set or not set)
    			xors[whichSet[i][0]].insert(whichSet[i][1]);
    			xors[whichSet[i][1]].insert(whichSet[i][0]);
    			doCheck(whichSet[i][0],whichSet[i][1]);
    		}
    	}
    	else{
    		//either notSet or andNand
    		if(whichSet[i][1]==-1){
    			// toNotSet[whichSet[i][0]]=false;
    			//NOT-SET PROPOGATE
    			notSetProp(whichSet[i][0]);
    		}
    		else{
    			//AND-NAND propogate new pair (check if already set or not set)
    			andnands[whichSet[i][0]].insert(whichSet[i][1]);
    			andnands[whichSet[i][1]].insert(whichSet[i][0]);
    			doCheck(whichSet[i][0],whichSet[i][1]);
    		}
    	}
    	// cerr<<"ERROR "<<setCount<<" "<<xorCount<<" "<<ceil(xors.size()/4.0)<<endl;
    	cout<<setCount+ceil(xors.size()/4.0)<<endl;
    }
}