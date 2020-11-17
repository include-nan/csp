#include <iostream>
using namespace std;

bool isIn(int xl, int yd, int xr, int yu, int m, int n) {
    if (m >= xl && m <= xr && n >= yd && n <= yu) {
        return true;
    }
    return false;
}

int main() {
    int n, k, t, xl, yd, xr, yu;
    cin >> n >> k >> t >> xl >> yd >> xr >> yu;

    int a[n][t];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < t; j++) {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            if (isIn(xl, yd, xr, yu, tmp1, tmp2)) {
                a[i][j] = 1;
            } else {
                a[i][j] = 0;
            }
        }
    }

    int ans1 = 0;
    int ans2 = 0;

    for (int i = 0; i < n; i++) {
        int times1 = 0;
        int times2 = 0;
        int times3 = 0;
        for (int j = 0; j < t; j++) {
            if (a[i][j] == 1) {
                times1++;
                times2++;
            } else {
                if (times2 > times3) {
                    times3 = times2;
                }
                times2 = 0;
            }
        }
        if (times1 > 0) {
            ans1++;
        }
        if (times3 >= k || times2 >= k) {
            ans2++;
        }
    }
    cout << ans1 << endl << ans2 << endl;
    return 0;
}
