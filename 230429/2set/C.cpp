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

int datas[50];
int ssum[50];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,pos,neg;
        cin>>n>>pos;
        neg=(n*(n+1))/2-pos;
        int cnt=pos;
        for(int i=0; i<n; i++){
            if(cnt>=(i+1)){
                ssum[i]=(i==0?2:ssum[i-1]+2);
                cnt-=(i+1);
            }
            else if(cnt>0){
                ssum[i]=cnt*2-1;
                cnt=0;
            }
            else{
                ssum[i]=-2-2*i;
            }
        }
        //cout<<0<<' ';
        for(int i=0; i<n; i++){
            //cout<<ssum[i]<<' ';
            cout<<ssum[i]-(i==0?0:ssum[i-1])<<' ';
        }
        cout<<endl;
    }
    return 0;
}