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

int datas[200020];
int out[200020],in[200020]; // log값을 적는다.
int out_cnt[50], in_cnt[50];
int plus2[50], minus2[50];
int DP[50];
#define ALL 38

int is_pow(int i){
    for(int j=0; j<32; j++){
        if(i==(1<<j)) return j+1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        bool flag=true;
        ll sum=0, mm;
        for(int i=0; i<n; i++) sum+=datas[i];
        if(sum%n!=0){
            cout<<"No"<<endl;
            continue;
        }
        mm=sum/n;
        //cout<<"mean "<<mm<<endl;
        fill(plus2,plus2+40,0);
        fill(minus2,minus2+40,0);
        for(int i=0; i<n; i++){
            if(datas[i]==mm){
                out[i]=ALL; in[i]=ALL;
            }
            else if(datas[i]>mm){
                // out이 더 크다.
                int dev=datas[i]-mm;
                int temp;
                if(temp=is_pow(dev)){
                    plus2[temp-1]++;
                }
                bool tflag=false;
                for(int k=0; (1<<k)<=dev; k++){
                    if(temp=is_pow(dev+(1<<k))){
                        in[i]=k;
                        out[i]=temp-1;
                        tflag=true;
                        break;
                    }
                }
                if(!tflag){
                    flag=false;
                    break;
                }
            }
            else{
                int dev=-datas[i]+mm;
                int temp;
                if(temp=is_pow(dev)){
                    minus2[temp-1]++;
                }
                bool tflag=false;
                for(int k=0; (1<<k)<=dev; k++){
                    if(temp=is_pow(dev+(1<<k))){
                        in[i]=temp-1;
                        out[i]=k;
                        tflag=true;
                        break;
                    }
                }
                if(!tflag){
                    flag=false;
                    break;
                }
            }
            //cout<<"num : "<<datas[i]<<' '<<datas[i]-mm<<' '<<in[i]<<' '<<out[i]<<endl;
        }
        //cout<<"plus "<<' '; for(int i=0; i<10; i++) cout<<plus2[i]<<' '; cout<<endl;
        //cout<<"minus "<<' '; for(int i=0; i<10; i++) cout<<minus2[i]<<' '; cout<<endl;

        if(!flag){
            cout<<"No"<<endl;
            continue;
        }
        fill(in_cnt,in_cnt+40,0);
        fill(out_cnt,out_cnt+40,0);
        for(int i=0; i<n; i++){
            in_cnt[in[i]]++;
            out_cnt[out[i]]++;
        }
        //cout<<"out_cnt "<<' '; for(int i=0; i<10; i++) cout<<out_cnt[i]<<' '; cout<<endl;
        //cout<<"in_cnt  "<<' '; for(int i=0; i<10; i++) cout<<in_cnt[i]<<' '; cout<<endl;
        

        for(int i=0; i<35; i++) DP[i]=in_cnt[i]-out_cnt[i];
        for(int i=0; i<35; i++){
            //cout<<i<<' '<<DP[i]<<' '<<plus2[i]<<endl;
            if(DP[i]>0){
                if(DP[i]%2==0 && DP[i]/2<=plus2[i]){
                    DP[i+1]+=DP[i]/2;
                }
                else{
                    flag=false; break;
                }
            }
            else if(DP[i]<0){
                if(DP[i]%2==0 && -DP[i]/2<=minus2[i]){
                    DP[i+1]+=DP[i]/2;
                }
                else{
                    flag=false; break;
                }
            }
        }

        if(!flag){
            cout<<"No"<<endl;
            continue;
        }
        else cout<<"Yes"<<endl;
    }
    return 0;
}