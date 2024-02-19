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


// 예를 들어 a가 증가하거나 일정한 와중에 중간에를 제거하면 똑같다.
// 그 외의 경우에는 제거하면 줄어든다.

int datas[300030];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        int last=datas[0];
        int cnt=0;
        for(int i=1; i<n-1; i++){
            if(last==datas[i] || datas[i]==datas[i+1]){
                cnt++;
            }
            else if(((ll)datas[i]-last)*((ll)datas[i+1]-datas[i])>0){
                cnt++;
            }
            else last=datas[i];
        }        
        if(n!=1 && datas[n-1]==last) cnt++;
        cout<<n-cnt<<endl;
    }
    return 0;
}