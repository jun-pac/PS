// 
//./D<test

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

int a[200000], b[200000], posa[200000], posb[200000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
        a[i]--;
        posa[a[i]]=i;
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
        b[i]--;
        posb[b[i]]=i;
    }
    
    ll res=0;
    int la=posa[0],ra=posa[0],tara=posa[0];
    int lb=posb[0],rb=posb[0],tarb=posb[0];
    int l,r;
    
    // k=0일 때는 단순히 0이 없는 모든 구간이다.
    if(tara>tarb) swap(tara,tarb);
    res=res+(ll)(tara+1)*(tara)/2;
    res=res+(ll)(n-tarb)*(n-tarb-1)/2;
    res=res+(ll)(tarb-tara)*(tarb-tara-1)/2;
    //cout<<"one matics : "<<res<<endl;

    for(int i=1; i<n; i++){
        tara=posa[i];
        la=min(la,posa[i-1]);
        ra=max(ra,posa[i-1]);
        tarb=posb[i];
        lb=min(lb,posb[i-1]);
        rb=max(rb,posb[i-1]);
        l=min(la,lb);
        r=max(ra,rb);
        if((l<=tara && tara<=r)||(l<=tarb && tarb<=r)) continue;
        if(tara>tarb) swap(tara,tarb);
        // always tara <= tarb
        ll temp=0;
        if(r<tara){
            // 둘 다 오른쪽
            temp=(ll)(tara-r)*(l+1);
            res=res+temp;
        }
        else if(tarb<l){
            // 둘 다 왼쪽
            temp=(ll)(l-tarb)*(n-r);
            res=res+temp;
        }
        else{
            // tara는 왼쪽, tarb는 오른쪽
            temp=(ll)(l-tara)*(tarb-r);
            res=res+temp;
        }
        //cout<<i+1<<" th matics : "<<temp<<endl;
    }
    cout<<res+1<<endl;

    return 0;
}