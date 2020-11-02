#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N;
    cin >> M;
    int a[N][M + 1];
    int b[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M + 1; j++) {
            cin >> a[i][j];
        }
    }

    int T = 0, k = 1, P = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M + 1; j++) {
            T = T + a[i][j];
        }
    }

    int flag = 0;

    for (int i = 0; i < N; i++) {
        int tmp = 0;
        for (int j = 1; j < M + 1; j++) {
            if (a[i][j] < 0) {
                tmp += a[i][j];
            }
        }
        if (tmp < flag) {
            flag = tmp;
            k = i + 1;
            P = flag;
        }
    }

    cout << T << " " << k << " " << -P << endl;
    return 0;
}