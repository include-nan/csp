#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;
    int M;
    cin >> N;

    // 使用二维指针
    // int **a;
    // a = new int *[N];
    // for (int i = 0; i < N; i++) {
    //     cin >> M;
    //     a[i] = new int[M];
    //     a[i][0] = M;
    //     for (int j = 1; j < M+1; j++) {
    //         cin >> a[i][j];
    //     }
    // }

    // 使用vector
    vector< vector<int> > a;
    for (int i = 0; i < N; i++) {
        vector<int> tmp;
        cin >> M;
        tmp.push_back(M);
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            if (j == 0 && x <= 0) {
                return 0;
            }
            tmp.push_back(x);
        }
        a.push_back(tmp);
    }

    int T = 0, D = 0, E = 0;
    vector<int> e;

    for (int i = 0; i < N; i++) {
        int t = 0, flag = 0;
        for (int j = 1; j < a[i][0] + 1; j++) {
            if (a[i][j] > 0) {
                if (t > a[i][j]) {
                    flag = 1;
                }
                t = a[i][j];
            } else {
                t += a[i][j];
            }
        }
        T += t;
        if (flag == 1) {
            D++;
            e.push_back(1);
        } else {
            e.push_back(0);
        }
    }

    int size = e.size();
    for (int i = 0; i < size; i++) {
        if (e[i] == 1 && e[(i + 1) % size] == 1 && e[(i + 2) % size] == 1) {
            E++;
        }
    }

    cout << T << " " << D << " " << E << endl;

    // for (int i = 0; i < N; i++) {
    //     for (int j = 1; j < a[i][0] + 1; j++) {
    //         cout << a[i][j] <<" ";
    //     }
    //     cout << endl;
    // }

    return 0;
}