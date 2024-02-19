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

int datas[200001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n; i++) cin>>datas[i];
    bool gf=false;
    bool tf=false;
    bool bor=false;
    int gnum=0;
    int znum=0;
    for(int i=0; i<n; i++){
        if(!gf && datas[i]!=0){
            gnum++;
            gf=true;
            tf=(datas[i]==2?true:false);
        }
        else if(datas[i]==2) tf=true;
        else if(!gf && datas[i]==0){
            if(i!=n-1 && datas[i+1]!=0) bor=true;
            else znum++;
        }
        else if(gf&&datas[i]==0){
            gf=false;
            if(!tf){
                // 앞에서 안썼으면 이것도 가능하다.
                if(bor){
                    if(i!=n-1 && datas[i+1]!=0) bor=true;
                    else{
                        znum++;
                        bor=false;
                    }
                }
                else{
                    bor=false;
                }
            }
            else bor=false;
        }
    }
    cout<<gnum+znum<<endl;
    return 0;
}