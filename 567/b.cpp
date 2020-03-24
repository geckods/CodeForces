#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> add(vector<int> a, vector<int> b){
	int fromback=1;
	int carry=0;

	int maxsize=max(a.size(),b.size());

	vector<int>c(maxsize+1,0);

	while(fromback<=max(a.size(),b.size())){
		int firstadd,secondadd;
		if(fromback<=a.size()){
			firstadd=a[a.size()-fromback];
		}
		else{
			firstadd=0;
		}

		if(fromback<=b.size()){
			secondadd=b[b.size()-fromback];
		}
		else{
			secondadd=0;
		}
		c[maxsize+1-fromback]=(firstadd+secondadd+carry)%10;
		carry=(firstadd+secondadd+carry)/10;

		fromback++;
	}
	c[0]=carry;

	return c;
}


bool lessthan(vector<int> a, vector<int> b){
	if(a.size()<b.size()) return true;
	if(a.size()>b.size()) return false;

	for(int i=0;i<a.size();i++){
		if(a[i]<b[i])return true;
		if(a[i]>b[i])return false;
	}

	return false;
}

void niceprint(vector<int> a){
	for(int i=0;i<a.size();i++){
		if(i==0 && a[i]==0) continue;
		cout<<a[i];
	}
	cout<<endl;
}

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);


 //   	vector<int> a;
 //   	vector<int> b;

 //   	a.push_back(3);
 //   	a.push_back(2);
 //   	a.push_back(1);
 //   	b.push_back(6);
 //   	b.push_back(7);
 //   	b.push_back(9);

 //   	vector<int> c = add(a,b);
	// for(int i=0;i<c.size();i++){
	// 	cout<<c[i];
	// }      	   	   	   	
	// cout<<endl;

   	int l;
   	cin>>l;

   	string n;
   	cin>>n;

   	if(l==1){
   		cout<<n<<endl;
   		return 0;
   	}
   	else if (l==2){
   		cout<<n[0]+n[1]-2*'0'<<endl;
   		return 0;
   	}


   	int possfirst;
   	int possfirst2;

   	possfirst=l/2;
   	while(n[possfirst]=='0')possfirst--;

   	possfirst2=l/2+1;
	while(possfirst2<l && n[possfirst2]=='0')possfirst2++;
	if(possfirst2==l)possfirst2--;


   	vector<int> firsta;
   	vector<int> seconda;

   	for(int i=0;i<possfirst;i++){
   		firsta.push_back(n[i]-'0');
   	}

   	for(int i=possfirst;i<l;i++){
   		seconda.push_back(n[i]-'0');
   	}

   	vector<int> thirda=add(firsta,seconda);

   	// for(int i=0;i<firsta.size();i++){
   	// 	cout<<firsta[i];
   	// }
   	// cout<<endl;

   	// for(int i=0;i<thirda.size();i++){
   	// 	cout<<thirda[i];
   	// }
   	// cout<<endl;

   	vector<int> firstb;
   	vector<int> secondb;

   	for(int i=0;i<possfirst2;i++){
   		firstb.push_back(n[i]-'0');
   	}

   	for(int i=possfirst2;i<l;i++){
   		secondb.push_back(n[i]-'0');
   	}

   	// for(int i=0;i<firstb.size();i++){
   	// 	cout<<firstb[i];
   	// }
   	// cout<<endl;


   	vector<int> thirdb = add(firstb,secondb);

   	// for(int i=0;i<thirdb.size();i++){
   	// 	cout<<thirdb[i];
   	// }
   	// cout<<endl;

   	if(lessthan(thirda,thirdb) || n[possfirst2]=='0'){
   		niceprint(thirda);
   	}
   	else{
   		niceprint(thirdb);
   	}

}