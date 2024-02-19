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

ll datas[100010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0; i<n; i++) cin>>datas[i]; // 기울기들
        sort(datas,datas+n);
        for(int i=0; i<m; i++){
            ll a,b,c;
            cin>>a>>b>>c;
            if(c<=0){
                cout<<"NO"<<endl;
                continue;
            }
            ll sqt=sqrt(4*a*c);
            if(sqt*sqt==4*a*c) sqt--;
            ll l_bnd=b-sqt, r_bnd=b+sqt;
            ll r = upper_bound(datas,datas+n,r_bnd)-datas; // 실제로 가능한 값 +1
            ll l = upper_bound(datas,datas+n,l_bnd-1)-datas; // 실제로 가능한 값의 가장 왼쪽 같으면 없는거임
            if(l<r){
                cout<<"YES"<<endl;
                cout<<datas[l]<<endl;
            }
            else cout<<"NO"<<endl;
        }
        cout<<endl;

    }
    return 0;
}