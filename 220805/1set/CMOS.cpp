// 
//./C<test

#include <bits/stdc++.h>
#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}

int sqrtN;

class Query{
public:
	int idx, s, e;
	bool operator < (Query &x){
		if(s/sqrtN != x.s/sqrtN) return s/sqrtN < x.s/sqrtN;
		return e < x.e;
	}
};

int datas[200000];
int ninc[200000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
        int n,q;
        cin>>n>>q;
        int cnt=0;
        for(int i=0; i<n; i++){
            cin>>datas[i];
            if(i>=2){
                if(datas[i]<=datas[i-1] && datas[i-1]<=datas[i-2]){
                    ninc[cnt++]=i;
                }
            }
        }
        int l,r;
        for(int i=0; i<q; i++){
            cin>>l>>r;
            l--, r--;
            if(r<=l+1) cout<<r-l+1<<endl;
            else{
                // r-l+1에서 [l+2,r]에 속하는 ninc의 개수를 빼준다.
                int s=lower_bound(ninc, ninc+cnt, l+2)-ninc;
                int e=upper_bound(ninc, ninc+cnt, r)-ninc;
                //cout<<"l r "<<l<<' '<<r<<endl;
                //cout<<"DEB ";
                //for(int j=s; j<=e; j++)cout<<ninc[j]<<' ';
                //cout<<endl;
                cout<<r-l+1-(e-s)<<endl;
            }
            
        }
    return 0;
}