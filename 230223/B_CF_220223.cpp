// B

#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int,int> um;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		um.clear();
		int n,a,cnt=0;
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>a;
			if(um[a]==0) cnt++;
			um[a]++;
		}
		for(int i=0; i<n; i++){
			cout<<max(i+1,k)<<'\n';
		}
	}
}
