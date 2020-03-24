/*
require 'set'
if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

nm = gets.chomp.split(" ").map(&:to_i)
n = nm[0]
m = nm[1]

stud = gets.chomp.split(" ").map(&:to_i).reverse

allowpassarr = []
n.times do
	allowpassarr.push Set.new
end

targetset = Set.new

nastya = stud[0]

m.times do
	ab = gets.chomp.split(" ").map(&:to_i)
	# a can get in front of b(while reversing)
	a = ab[0]
	b = ab[1]

	if(b==nastya)
		targetset.add(a)
	end

	allowpassarr[b-1].add(a)
end

i=1
count=0

#p allowpassarr
#p targetset

while(!targetset.empty? && i<n)
	nextguy = stud[i]
	if targetset.include?(nextguy)
		count+=1
		targetset.delete(nextguy)
	else
		targetset=allowpassarr[nextguy-1]&targetset
	end
	i+=1
end

puts count
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int n,m;
   	cin>>n>>m;

   	int arr[n];
   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   	}

   	vector<set<int> > allowpassarr(n);

   	int nastya = arr[n-1];
   	set<int> targetset;

   	int a,b;
//   	cout<<nastya<<endl;

   	int myarr[a][b];
   	for(int i=0;i<m;i++){
   		cin>>a>>b;
   		if(b==nastya)
   			targetset.insert(a);
   	}

   	for(int i=0;i<m;i++){
   		cin>>a>>b;

   		allowpassarr[b-1].insert(a);
   	}

   	int count=0;
   	int nextguy;
	set<int> intersect;

   	for(int i=n-2;i>=0;i--){
   		if(targetset.size()==0) break;
//   		cout<<"HI"<<endl;

   		nextguy=arr[i];

   		if(targetset.find(nextguy)!=targetset.end()){
   			count++;
   			targetset.erase(nextguy);	
	   	}
	   	else{
			set_intersection(targetset.begin(),targetset.end(),allowpassarr[nextguy-1].begin(),allowpassarr[nextguy-1].end(),std::inserter(intersect,intersect.begin()));
			targetset=intersect;
	   	}
   	}

   	cout<<count<<endl;
/*
i=1
count=0

#p allowpassarr
#p targetset

while(!targetset.empty? && i<n)
	nextguy = stud[i]
	if targetset.include?(nextguy)
		count+=1
		targetset.delete(nextguy)
	else
		targetset=allowpassarr[nextguy-1]&targetset
	end
	i+=1
end

puts count
*/

}