// 
//./E<test

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

int raw[100005];
int datas[100005];
int icdu_cur[100005];
vector<int> wcdm[100005];
vector<int> icdu[100005]; // 전부 idx아닌 pos로
priority_queue<pair<int,int>> pq; // {-pos, m_idx}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    for(int r=1; r<=100000; r++){
        for(int i=1; i*r<=100000; i++){
            wcdm[i*r].push_back(r);
        }
    }

    //cout<<"ds"<<endl;

    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0; i<n; i++) cin>>raw[i];
        sort(raw,raw+n);
        int cnt=0;
        datas[cnt++]=raw[0];
        for(int i=1; i<n; i++){
            if(raw[i]!=raw[i-1]) datas[cnt++]=raw[i];
        }

        while(!pq.empty()) pq.pop();


        for(int i=0; i<=m; i++) icdu[i].clear();
        for(int i=0; i<cnt; i++){
            for(int j=0; j<wcdm[datas[i]].size(); j++){
                //if(m/2<wcdm[datas[i]][j] && wcdm[datas[i]][j]<=m){
                //    icdu[wcdm[datas[i]][j]].push_back(datas[i]);
                //}
                if(m/2<wcdm[datas[i]][j] && wcdm[datas[i]][j]<=m){
                    icdu[wcdm[datas[i]][j]].push_back(datas[i]);
                }
            }
        }
        
        int mx_pos=0;
        int res=1000000007;
        fill(icdu_cur,icdu_cur+m+1,0);
        //for(int i=m/2+1; i<=m; i++){
        for(int i=m/2+1; i<=m; i++){
            if(icdu[i].size()==0){
                res=-1;
                break;
            }
            pq.push({-icdu[i][icdu_cur[i]],i});
            mx_pos=max(mx_pos,icdu[i][icdu_cur[i]]);
            //cout<<"m : "<<i<<' '<<icdu[i][icdu_cur[i]]<<endl;
            icdu_cur[i]++;
        }

        //cout<<"init "<<pq.size()<<' '<<m<<endl;

        if(res==-1){
            cout<<-1<<endl;
            continue;
        }

        bool fflag=true;
        for(int i=0; i<cnt; i++){
            while(!pq.empty() && -pq.top().fi<datas[i]){
                pair<int,int> temp=pq.top();
                pq.pop();
                int idx=temp.se;
                if(icdu_cur[idx]>=icdu[idx].size()){
                    fflag=false;
                    break;
                }
                pq.push({-icdu[idx][icdu_cur[idx]],idx});
                mx_pos=max(mx_pos,icdu[idx][icdu_cur[idx]]);
                icdu_cur[idx]++;
            }
            //cout<<"idx i is okay : "<<i<<endl;

            if(!fflag) break;
            res=min(res,mx_pos-datas[i]);
        }
        cout<<res<<endl;
    }
    return 0;
}