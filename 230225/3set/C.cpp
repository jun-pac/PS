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

string a,b;

bool ex[30];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        cin>>a;
        cin>>b;
        fill(ex,ex+26,false);
        for(int i=0; i<n; i++){
            ex[a[i]-'a']=true;
        }
        vector<char> chara;
        for(int i=0; i<26; i++){
            if(ex[i]) chara.push_back(i+'a');
        }
        //for(int i=0; i<chara.size(); i++) cout<<chara[i];
        //cout<<endl;
        int numa=chara.size();
        //cout<<"numa : "<<numa<<endl;
        ll res=0;
        if(numa<=k){
            ll duration=n;
            res=((duration+1)*duration)/2LL;
            cout<<res<<endl;
            continue;
        }
        
        for(int i=0; i<(1<<numa); i++){
            //cout<<i<<' ';
            int temp=i, cnt=0;
            int onenum=0;
            while(temp!=0){
                if(temp%2==1) onenum++;
                temp=temp/2;
            }
            if(onenum!=k) continue;

            //cout<<"k n "<<k<<' '<<onenum<<endl;
            temp=i;
            fill(ex,ex+26,false);
            while(temp!=0){
                if(temp%2==1){
                    onenum++;
                    ex[chara[cnt]-'a']=true;
                    //cout<<"true "<<cnt<<endl;
                }
                cnt++;
                temp=temp/2;
            }
            //for(int i=0; i<26; i++) cout<<ex[i];
            //cout<<endl;

            int last_diff=-1;
            ll temp_res=0;
            for(int j=0; j<n; j++){
                if(!ex[a[j]-'a'] && a[j]!=b[j]){
                    ll duration=j-1-last_diff;
                    temp_res+=((duration+1)*duration)/2LL;
                    last_diff=j;
                }
            }
            ll duration=n-1-last_diff;
            temp_res+=((duration+1)*duration)/2;
            //cout<<"temp res : "<<temp_res<<endl;
            res=max(res,temp_res);
        }
        //cout<<endl;
        cout<<res<<endl;
    }
    return 0;
}