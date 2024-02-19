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
#define ALL 38

int is_pow(int i){
    for(int j=0; j<32; j++){
        if(i==(1<<j)) return j;
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

        for(int i=0; i<n; i++){
            if(datas[i]==mm){
                out[i]=ALL; in[i]=ALL;
            }
            else if(datas[i]>mm){
                // out이 더 크다.
                int dev=datas[i]-mm;
                int temp;
                bool tflag=false;
                for(int k=0; (1<<k)<=dev; k++){
                    if(temp=is_pow(dev+(1<<k))){
                        in[i]=k;
                        out[i]=temp;
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
                bool tflag=false;
                for(int k=0; (1<<k)<=dev; k++){
                    if(temp=is_pow(dev+(1<<k))){
                        in[i]=temp;
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

        for(int i=0; i<40; i++){
            if(in_cnt[i]!=out_cnt[i]){
                flag=false;
            }
        }
        if(!flag){
            cout<<"No"<<endl;
            continue;
        }
        /*
        for(int i=0; i<n; i++){
            if(out[i]==ALL) continue;
            in_cnt[in[i]]--;
            if(in_cnt[out[i]]==0 && in_cnt[ALL]>0) in_cnt[ALL]--;
            else if(in_cnt[out[i]]==0 && in_cnt[ALL]==0) flag=false;
            in_cnt[in[i]]++;   
        }
        */
        if(!flag){
            cout<<"No"<<endl;
            continue;
        }
        else cout<<"Yes"<<endl;
    }
    return 0;
}