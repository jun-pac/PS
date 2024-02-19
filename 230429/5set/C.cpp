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

int datas[100020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,c,d;
        cin>>n>>c>>d;
        for(int i=0; i<n; i++) cin>>datas[i];
        sort(datas,datas+n);
        ll mn=n*c+d;
        ll last=-1;
        ll cnt_uniq=0;
        for(int i=0; i<n; i++){
            if(last==datas[i]) continue;
            else{
                cnt_uniq++;
                last=datas[i];
            }
            // datas[i]까지 만들겁니다.
            // cnt_uniq개 남김, n-cnt_uniq개 제거, datas[i]-cnt-uniq개 추가
            ll temp=(n-cnt_uniq)*c+(datas[i]-cnt_uniq)*d;
            mn=min(mn,temp);
        }
        cout<<mn<<endl;
    }
    return 0;
}