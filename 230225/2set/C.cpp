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

ll datas[200010];
ll s, ts;

ll sm(ll aa){
    if(aa>=ts) return s;
    else if(aa<=s) return 0;
    else return aa-s; 
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n>>s;
        ts=2*s;
        ll res1=0, res2=0;
        for(int i=0; i<n; i++){
            cin>>datas[i];
        }
        
        ll lasts, lastl;
        ll temp1, temp2;
        for(int i=1; i<n-1; i++){
            ll ss=sm(datas[i]);
            ll ls=datas[i]-ss;
            //cout<<"test s small large : "<<s<<' '<<ss<<' '<<ls<<endl;
            if(i==1){
                res1=datas[0]*ls;
                res2=datas[0]*ss;
            }
            else{
                temp1=min(res1+lasts*ls,res2+lastl*ls);
                temp2=min(res1+lasts*ss,res2+lastl*ss);
                res1=temp1;
                res2=temp2;
            }
            lasts=ss;
            lastl=ls;
        }
        ll res=min(res1+lasts*datas[n-1], res2+lastl*datas[n-1]);
        cout<<res<<endl;
    }
    return 0;
}