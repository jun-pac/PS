// 
//./D<test

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

#define MOD 998244353

int a[100000], b[100000];
pair<int,int> datas[100000]; // pos로
vector<int> pos[100000]; // pos로
bool used[100000]; // pos로
int cnt[100000]; // num으로 접근
int fix_idx[100000]; // num으로 접근
bool flag;

void DFS(int num, int idx){
    // num이 idx로 확정됐을 때
    if(used[idx]){
        flag=false;
        return;
    }
    if(fix_idx[num]!=-1){
        flag=false;
        return;
    }
    fix_idx[num]=idx;
    used[idx]=true;
    for(int i=0; i<pos[num].size(); i++){
        int next=pos[num][i];
        if(idx==next) continue;
        int other=datas[next].fi+datas[next].se-num;
        if(other==num){
            flag=false;
            return;
        }
        DFS(other,next);
    }
}

void DFS2(int num, int idx){
    //cout<<num+1<<' '<<idx+1<<endl;
    if(used[idx]){
        flag=false;
        return;
    }
    if(fix_idx[num]!=-1){
        flag=false;
        return;
    }
    fix_idx[num]=idx;
    used[idx]=true;
    int other=datas[idx].fi+datas[idx].se-num;
    if(other==num){
        flag=false;
        return;
        // cannot happen
    }
    cnt[other]--;
    if(cnt[other]==0 && fix_idx[other]==-1){
        flag=false;
        return;
    }
    if(cnt[other]==1) DFS2(other, pos[other][0]+pos[other][1]-idx);
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];
        for(int i=0; i<n; i++) datas[i]={min(a[i]-1,b[i]-1),max(a[i]-1,b[i]-1)};
        //sort(datas,datas+n);
        fill(used,used+n,false);
        for(int i=0; i<n; i++) pos[i].clear();
        ll res=1;
        flag=true;
        fill(fix_idx,fix_idx+n,-1);
        
        // graph
        for(int i=0; i<n; i++){
            pos[datas[i].fi].push_back(i);
            pos[datas[i].se].push_back(i);
        }

        for(int i=0; i<n; i++){
            if(pos[i].size()==0) flag=false;
            cnt[i]=pos[i].size();
        }

        for(int i=0; i<n; i++){
            if(datas[i].fi==datas[i].se){
                DFS(datas[i].fi, i);
                res=(res*n)%MOD;
                if(!flag) break;
            }
        }

        
        if(!flag){
            cout<<0<<endl;
            continue;
        }

        for(int i=0; i<n; i++){
            if(fix_idx[i]==-1 && cnt[i]==1){
                int idx=pos[i][0]; // datas에서의 idx
                //cout<<"DFS2call"<<endl;
                DFS2(i, idx);
                if(!flag) break;
            }
        }
        if(!flag){
            cout<<0<<endl;
            continue;
        }

        for(int i=0; i<n; i++) pos[i].clear();
        for(int i=0; i<n; i++){
            if(!used[i]){
                pos[datas[i].fi].push_back(i);
                pos[datas[i].se].push_back(i);
            }
        }
        for(int i=0; i<n; i++){
            if(!used[i]){
                res=(res*2)%MOD;
                
                int num=datas[i].fi;
                int idx=i;
                used[i]=true;
                int other=datas[i].se;
                int other_idx=pos[num][0]+pos[num][1]-idx;
                while(other_idx!=i){
                    //cout<<i<<' '<<other_idx<<endl;
                    used[other_idx]=true;
                    other=datas[other_idx].fi+datas[other_idx].se-other;
                    other_idx=pos[num][0]+pos[num][1]-other_idx;
                }
            }
        }
        cout<<res<<endl;
        // used[i] == false인 곳이 이루는 cycle개수를 알면 되는거다

    }
    return 0;
}