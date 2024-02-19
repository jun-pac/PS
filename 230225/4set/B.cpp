// 
//./B<test

#include <bits/stdc++.h>
//#define endl '\n'
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

#define N 100100

int ww[N], ii[N], nn[N];

vector<int> WI,IW,IN,NI,WN,NW;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        WI.clear(),IW.clear(),IN.clear(),NI.clear(),WN.clear(),NW.clear();
        for(int i=0; i<n; i++){
            cin>>s;
            ww[i]=ii[i]=nn[i]=0;
            for(int j=0; j<3; j++){
                if(s[j]=='w') ww[i]++;
                else if(s[j]=='i') ii[i]++;
                else nn[i]++;
            }
            if(ww[i]>1 && ii[i]==0) IW.push_back(i);
            if(ww[i]>1 && nn[i]==0) NW.push_back(i);
            if(ii[i]>1 && ww[i]==0) WI.push_back(i);
            if(ii[i]>1 && nn[i]==0) NI.push_back(i);
            if(nn[i]>1 && ww[i]==0) WN.push_back(i);
            if(nn[i]>1 && ii[i]==0) IN.push_back(i);
        }
        //cout<<IW.size()<<' '<<WI.size()<<' '<<NW.size()<<' '<<WN.size()<<' '<<IN.size()<<' '<<NI.size()<<endl;
        //assert(IW.size()==WI.size() && NW.size()==WN.size() && IN.size()==NI.size());
        int sz1=IW.size()+NW.size()+NI.size();
        int sz2=WI.size()+WN.size()+IN.size();
        if(sz1==sz2){
            cout<<sz1<<endl;
            for(int i=0; i<IW.size(); i++) cout<<IW[i]+1<<' '<<'w'<<' '<<WI[i]+1<<' '<<'i'<<endl;
            for(int i=0; i<NW.size(); i++) cout<<NW[i]+1<<' '<<'w'<<' '<<WN[i]+1<<' '<<'n'<<endl;
            for(int i=0; i<NI.size(); i++) cout<<NI[i]+1<<' '<<'i'<<' '<<IN[i]+1<<' '<<'n'<<endl;
        }
        else if(sz1>sz2){
            int tri=sz1-sz2;
            cout<<sz2+tri<<endl;
            for(int i=0; i<(int)IW.size()-tri; i++) cout<<IW[i]+1<<' '<<'w'<<' '<<WI[i]+1<<' '<<'i'<<endl;
            for(int i=0; i<(int)NW.size(); i++) cout<<NW[i]+1<<' '<<'w'<<' '<<WN[i]+1<<' '<<'n'<<endl;
            for(int i=0; i<(int)NI.size()-tri; i++) cout<<NI[i]+1<<' '<<'i'<<' '<<IN[i]+1<<' '<<'n'<<endl;
            for(int i=0; i<tri; i++){
                cout<<IW[IW.size()-tri+i]+1<<' '<<'w'<<' '<<NI[NI.size()-tri+i]+1<<' '<<'i'<<endl;
                cout<<NI[NI.size()-tri+i]+1<<' '<<'w'<<' '<<WN[WN.size()-tri+i]+1<<' '<<'n'<<endl;
            }
        }
        else{
            int tri=sz2-sz1;
            cout<<sz1+tri<<endl;
            for(int i=0; i<(int)IW.size(); i++) cout<<IW[i]+1<<' '<<'w'<<' '<<WI[i]+1<<' '<<'i'<<endl;
            for(int i=0; i<(int)NW.size()-tri; i++) cout<<NW[i]+1<<' '<<'w'<<' '<<WN[i]+1<<' '<<'n'<<endl;
            for(int i=0; i<(int)NI.size(); i++) cout<<NI[i]+1<<' '<<'i'<<' '<<IN[i]+1<<' '<<'n'<<endl;
            for(int i=0; i<tri; i++){
                cout<<NW[NW.size()-tri+i]+1<<' '<<'w'<<' '<<IN[IN.size()-tri+i]+1<<' '<<'n'<<endl;
                cout<<IN[IN.size()-tri+i]+1<<' '<<'w'<<' '<<WI[WI.size()-tri+i]+1<<' '<<'i'<<endl;
            }
        }
    }
    return 0;
}