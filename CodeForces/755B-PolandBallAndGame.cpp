#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,m_nuevo;
    string s;
    cin >> n >> m;
    float repited=0.0;
    unordered_set<string> poland;
    for(int i = 0; i < n; i++){
        cin >> s;
        poland.insert(s);
    }
    for(int i = 0; i < m; i++){
        cin >> s;
        if(poland.count(s))
            repited++;
    }
    m -= ceil(repited/2);
    n -= floor(repited/2);

    
    if(n > m)
        cout << "YES\n";
    else
    {
        cout << "NO\n";
    }
    return 0;
}