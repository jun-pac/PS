
#include <bits/stdc++.h>
using namespace std;
#define epsilon 0.000001

void gaussian_elimination(vector<float> input_array) {
    double A[3][3];
    double b[3];
    for(int i=0; i<3; i++) A[0][i]=input_array[i];
    for(int i=0; i<3; i++) A[1][i]=input_array[i+4];
    for(int i=0; i<3; i++) A[2][i]=input_array[i+8];
    for(int i=0; i<3; i++) b[i]=input_array[4*i+3];
    
    bool singular=0;

    // Forward elimination
    for(int i=0; i<3; i++){
        int mxRow = i;
        for(int k=i+1; k<3; k++) {
            if(abs(A[k][i])>abs(A[mxRow][i])) {
                mxRow=k;
            }
        }
        swap(A[i], A[mxRow]);
        swap(b[i], b[mxRow]);
        
        if(abs(A[i][i])<epsilon) singular=1;
        else{
            // Make all rows below this 0 in current column
            for(int k=i+1; k<3; k++){
                double factor=A[k][i]/A[i][i];
                for(int j=i; j<3; j++){
                    A[k][j]-=factor*A[i][j];
                }
                b[k]-=factor*b[i];
            }
        }
    }
    // A is row echelon form now. 

    // Back substitution
    double x[3];
    for(int i=2; i>=0; i--){
        if(abs(A[i][i])<epsilon){
            if(abs(b[i])>epsilon){
                cout<<"No solution\n";
                return ;
            } 
            else{
                cout<<"Infinitely many solutions\n";
                return ;
            }
        }
        else{
            x[i]=b[i]/A[i][i];
            for(int j=0; j<3; j++) {
                b[j]-=A[j][i]*x[i];
            }
        }
    }
    cout<<fixed;
    cout.precision(10);
    cout<<x[0]<<' '<<x[1]<<' '<<x[2]<<'\n';
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<double> input_array;
    for(int i=0; i<12; i++){
        double x;
        cin>>x;
        input_array.push_back(x);
    }
    double A[3][3];
    double b[3];
    for(int i=0; i<3; i++) A[0][i]=input_array[i];
    for(int i=0; i<3; i++) A[1][i]=input_array[i+4];
    for(int i=0; i<3; i++) A[2][i]=input_array[i+8];
    for(int i=0; i<3; i++) b[i]=input_array[4*i+3];
    
    bool singular=0;

    // Forward elimination
    for(int i=0; i<3; i++){
        int mxRow = i;
        for(int k=i+1; k<3; k++) {
            if(abs(A[k][i])>abs(A[mxRow][i])) {
                mxRow=k;
            }
        }
        swap(A[i], A[mxRow]);
        swap(b[i], b[mxRow]);
        
        if(abs(A[i][i])<epsilon) singular=1;
        else{
            // Make all rows below this 0 in current column
            for(int k=i+1; k<3; k++){
                double factor=A[k][i]/A[i][i];
                for(int j=i; j<3; j++){
                    A[k][j]-=factor*A[i][j];
                }
                b[k]-=factor*b[i];
            }
        }
    }
    // A is row echelon form now. 
    // for(int i=0; i<3; i++){
    //     for(int j=0; j<3; j++) cout<<A[i][j]<<' ';
    //     cout<<'\n';
    // }
    // for(int i=0; i<3; i++) cout<<b[i]<<'\n';

    // Back substitution
    double x[3];
    for(int i=2; i>=0; i--){
        if(abs(A[i][i])<epsilon){
            if(abs(b[i])>epsilon){
                cout<<"No solution\n";
                return 0;
            } 
            else{
                cout<<"Infinitely many solutions\n";
                return 0;
            }
        }
        else{
            x[i]=b[i]/A[i][i];
            for(int j=0; j<3; j++) {
                b[j]-=A[j][i]*x[i];
            }
        }
    }
    cout<<fixed;
    cout.precision(10);
    cout<<x[0]<<' '<<x[1]<<' '<<x[2]<<'\n';
    return 0;
}

