#include <bits/stdc++.h>
using namespace std;

int main (){

    vector<vector<int>> matrix(10, vector<int>(10, -1));

    /*for(auto x: matrix){

        for(auto x2: x){

            cout << x2 << " ";
        }
        cout << endl;
    }

    cout << endl;*/

    int n; cin>>n;

    int d, l, r, c; bool ban = true;
    for(int z = 0; z < n; z++){
        cin>>d>>l>>r>>c;

        if(d){ // vertical

            if(r + l - 2 >= 10){
                ban = false; break;
            }

            for(int i = r-1, j = 0; j < l; j++, i++){
                if(matrix[i][c-1] != -1){
                    ban = false; break;
                }else{
                    matrix[i][c-1] = 1;
                }
            }

        } else { //Horizontal

            if(c + l - 2 >= 10){
                ban = false;  break;
            }

            for(int i = c-1, j = 0; j < l; j++, i++){
                if(matrix[r-1][i] != -1){
                    ban = false; break;
                }else{
                    matrix[r-1][i] = 1;
                }
            }

        }

    }

    /*cout << endl;

    for(auto x: matrix){

        for(auto x2: x){

            cout << x2 << " ";
        }
        cout << endl;
    }

    cout << endl;*/

    if(ban) cout <<"Y\n"; else cout<<"N\n";

    return 0;
}
