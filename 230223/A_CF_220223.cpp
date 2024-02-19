// A

#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t,a,b,c,d,e,f;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d>>e>>f;
		if(b==d) cout<<abs(c-a)<<'\n';
		if(d==f) cout<<abs(c-e)<<'\n';
		if(f==b) cout<<abs(e-a)<<'\n';
		else cout<<0<<'\n';
	}
}
