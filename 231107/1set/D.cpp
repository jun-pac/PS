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

#define MOD 998244353

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}
ll datas[300030];
ll xors[300030];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>datas[i];
        }
        ll res=0;
        for(int k=0; k<30; k++){
            ll mul=(1<<k);
            ll l1=0, r1=0, cur;
            ll lecnt=1, locnt=0, recnt=1, rocnt=0;
            ll temp=0;
            for(int i=1; i<n; i++){
                if(datas[i]&mul){
                    r1++;
                }
                if(r1%2==0) recnt++;
                else rocnt++;
            }
            cur=((datas[0]&mul)?1:0);
            for(int i=0; i<n; i++){
                if((datas[i]&mul)==0){
                    temp=(temp+lecnt*rocnt)%MOD;
                    temp=(temp+locnt*recnt)%MOD;
                }
                else{
                    temp=(temp+lecnt*recnt)%MOD;
                    temp=(temp+locnt*rocnt)%MOD;
                }

                if((datas[i]&mul)==0) lecnt++;
                else{
                    swap(lecnt,locnt);
                    lecnt++;
                }
                if(i!=n-1){
                    if(datas[i+1]&mul){
                        recnt--;
                        swap(recnt,rocnt);
                    }
                    else{
                        recnt--;
                    }
                }
            }
            res=(res+temp*mul)%MOD;
        }
        cout<<(res%MOD+MOD)%MOD<<endl;
    return 0;
}