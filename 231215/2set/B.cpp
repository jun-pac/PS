// 
//./B<test

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

int datas[200020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        ll cnt=0;
        ll last=datas[n-1];
        for(int i=n-1; i>=0; i--){
            if(datas[i]>last){
                if(datas[i]%last==0){
                    cnt+=datas[i]/last-1;
                }
                else{
                    int temp=datas[i]/last+1;
                    cnt+=temp-1;
                    last=datas[i]/temp;
                }
            }
            else last=datas[i];
        }
        cout<<cnt<<'\n';
    }
    return 0;
}