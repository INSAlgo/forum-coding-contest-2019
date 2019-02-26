#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

int n; // Nombre d'archers

int main() {
    cin.sync_with_stdio(false);
    cin >> n;
    int best_arrow = 1;
    double best_dst = numeric_limits<double>::max();
    double x, y;
    for(int i=1; i<=n; ++i) {
        cin >> x >> y;
        double dst = x*x + y*y;
        if(dst < best_dst) {
            best_dst = dst;
            best_arrow = i;
        }
    }
    cout << best_arrow << endl;
    return 0;
}
