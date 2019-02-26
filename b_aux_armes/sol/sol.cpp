#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

typedef long long int lli;

int main() {
    lli S, L, N;
    cin >> S >> L >> N;
    vector<lli> V(N, 0);
    for(lli i=0; i<N; ++i) {
        cin >> V[i];
    }

    if(S > L) {
        cout << 0 << endl;
        return 0;
    }

    sort(V.begin(), V.end(), greater<lli>());
    for(lli i=0; i<N; ++i) {
        S += V[i];
        if(S > L) {
            cout << i+1 << endl;
            return 0;
        }

    }

    cout << -1 << endl;
    return 0;
}
