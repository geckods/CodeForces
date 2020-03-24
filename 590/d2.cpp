#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll countSetBits(ll n) 
{ 
    ll count = 0; 
    while (n) 
    { 
	    n &= (n-1);
    	count++; 
    } 
    return count; 
} 

ll getMid(ll s, ll e) { return s + (e -s)/2; }

multiset<char> getSumUtil(vector<multiset<char> > &myST, ll ss, ll se, ll qs, ll qe, ll si)  
{  
    // If segment of this node is a part of given range, then return  
    // the sum of the segment  
    if (qs <= ss && qe >= se)  
        return myST[si];
  
    // If segment of this node is outside the given range  
    if (se < qs || ss > qe)  
        return multiset<char>();
  
    // If a part of this segment overlaps with the given range  
    int mid = getMid(ss, se);  
    multiset<char> newSet;
    multiset<char> newSetA=getSumUtil(myST, ss, mid, qs, qe, 2*si+1);
    multiset<char> newSetB=getSumUtil(myST, mid+1, se, qs, qe, 2*si+2);

    set_union(newSetA.begin(),newSetA.end(),newSetB.begin(),newSetB.end(),newSet.begin());
    return newSet;
}  


ll getSum(vector<multiset<char> > &myST, ll n, ll qs, ll qe)
{  
    // Check for erroneous input values  
    if (qs < 0 || qe > n-1 || qs > qe)  
    {  
        cout<<"Invalid Input";  
        return -1;  
    }  
  
    multiset<char> myRet = getSumUtil(myST, 0, n-1, qs, qe, 0);

    int ans=0;
    for(char z='a';z<='z';z++){
    	if(myRet.find(z)!=myRet.end())ans++;
    }
    return ans;
}  

int parent(int x){
	if(x%2==0){
		return x/2-1;
	}
	else{
		return x/2;
	}
}

void updateValueUtil(vector<multiset<char> > &myST, int ind, char oldChar, char newChar){
	myST[ind].erase(oldChar);
	myST[ind].insert(newChar);
	if(ind!=0){
		updateValueUtil(myST,parent(ind),oldChar,newChar);
	}
}

void updateValue(vector<multiset<char> > &myST, string &s, int n, int pos, char newChar){
	char oldChar = s[pos];
	s[pos]=newChar;
	updateValueUtil(myST,n+pos,oldChar,newChar);
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input", "r", stdin);
		freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin>>s;


	int asd = pow(2,ceil(log2(s.length())));
	while(s.length()<asd){
		s+='0';
	}

	int n=s.length();


	int q;
	cin>>q;

	vector<multiset<char> > myVec(2*n-1);
	for(int i=n;i<n+n;i++){
		myVec[i].insert(s[i-asd]);
	}

	for(int i=asd-1;i>=0;i--){
		set_union(myVec[2*i+1].begin(),myVec[2*i+1].end(),myVec[2*i+2].begin(),myVec[2*i+2].end(),myVec[i]);
	}

	int x,l,r;
	int pos;
	char z;
	for(int quer=0;quer<q;quer++){
		cin>>x;
		if(x==1){
			cin>>pos;
			cin>>z;
			updateValue(myVec,s,n,pos,z);
		}
		else{
			cin>>l>>r;
			l--;
			r--;
			cout<<getSum(myVec,n,l,r)<<endl;
		}
	}
}
