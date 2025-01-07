
#include <bits/stdc++.h>
using namespace std;

array<int,3> Solve(int rows, int cols){
    int cnta=0, cntb=0, cntab=0;
    for(int i=0; i<rows*cols; i++){
        for(int j=i+1; j<rows*cols; j++){
            int mna=i;
            int mnb=min(rows*(i%cols)+i/cols,rows*(j%cols)+j/cols);
            if(mna<mnb) cnta++;
            else if(mna>mnb) cntb++;
            else cntab++;
        }
    }
    cout<<cnta<<' '<<cntb<<' '<<cntab<<' '<<cnta+cntb+cntab<<'\n';
    return {cnta, cntb, cntab};
}

array<int,3> Solve_mx(int rows, int cols){
    int cnta=0, cntb=0, cntab=0;
    for(int i=0; i<rows*cols; i++){
        for(int j=i+1; j<rows*cols; j++){
            int mna=j;
            int mnb=max(rows*(i%cols)+i/cols,rows*(j%cols)+j/cols);
            if(mna<mnb) cnta++;
            else if(mna>mnb) cntb++;
            else cntab++;
        }
    }
    cout<<cnta<<' '<<cntb<<' '<<cntab<<' '<<cnta+cntb+cntab<<'\n';
    return {cnta, cntb, cntab};
}


array<int,3> Solve2(int rows, int cols){
    int cnta=0, cntb=0, cntab=0;
    for(int i=0; i<rows*cols; i++){
        int j=i;
        int mna=i;
        int mnb=min(rows*(i%cols)+i/cols,rows*(j%cols)+j/cols);
        if(mna<mnb) cnta++;
        else if(mna>mnb) cntb++;
        else cntab++;
    }
    cout<<cnta<<' '<<cntb<<' '<<cntab<<' '<<cnta+cntb+cntab<<'\n';
    return {cnta, cntb, cntab};
}

int main(){
    double mx=1;
    for(int i=1; i<22; i++){
        for(int j=i+1; j<22; j++){
            cout<<"Case "<<i<<' '<<j<<": ";
            auto res=Solve(i,j);
            cout<<"Case "<<i<<' '<<j<<": ";
            res=Solve_mx(i,j);
            cout<<'\n';
        }
    }
    return 0;
}

