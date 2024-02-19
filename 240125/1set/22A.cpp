
/*
balance=[30,30,30,30]
transactionaction=[[1,2,10],[2,3,20],[3,4,5],[3,4,30]]
abnormalormal=[1]
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)  
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)

using namespace std;

vector<int> solution(vector<int> balance, vector<vector<int>> transaction, vector<int> abnormal) {
    int n,m,k;
    n=balance.size();
    m=transaction.size();
    k=abnormal.size();
    vector<int> answer(n);
    vector<stack<pair<int,int>>> datas(n);


    rng(i,0,n-1) datas[i].push({balance[i],0});
    rng(i,0,m-1) transaction[i][0]--, transaction[i][1]--;
    rng(i,0,k-1) abnormal[i]--;
    rng(i,0,k-1) datas[abnormal[i]].top().se=1;
    rng(i,0,m-1){
        int a=transaction[i][0], b=transaction[i][1];
        int val=transaction[i][2];
        while(val>0){
            assert(!datas[a].empty());
            pair<int,int> temp=datas[a].top();
            datas[a].pop();
            if(temp.fi>val){
                datas[a].push({temp.fi-val,temp.se});
                datas[b].push({val,temp.se});
                val=0;
            }
            else{
                datas[b].push(temp);
                val-=temp.fi;
            }
        }
    }
    rng(i,0,n-1){
        int res=0;
        while(!datas[i].empty()){
            pair<int,int> temp=datas[i].top();
            datas[i].pop();
            if(temp.se==0) res+=temp.fi;
        }
        answer[i]=res;
    }
    return answer;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> balance(n);
    vector<vector<int>> transaction(m);
    rng(i,0,m-1) transaction[i].resize(3);
    vector<int> abnormal(k);
    rng(i,0,n-1){
        cin>>balance[i];
    }
    rng(i,0,m-1){
        cin>>transaction[i][0]>>transaction[i][1]>>transaction[i][2];
    }
    rng(i,0,k-1){
        cin>>abnormal[i];
    }
    vector<int> ans;
    ans=solution(balance,transaction,abnormal);

    rng(i,0,n-1) cout<<ans[i]<<' '; cout<<'\n';
    return 0;
}

