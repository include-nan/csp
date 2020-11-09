#include <iostream>
using namespace std;

bool judge(int a) {
    if (a % 7 == 0) {
        return false;
    }
    while (a > 10) {
        int b = a % 10;
        if (b == 7) {
            return false;
        }
        a = a / 10;
        if(a == 7){
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int flag[4] = {0};
    int j = 1, k = 0, m = 1;

    // if(!judge(27))
    //     cout<<"Yes"<<endl;

    for (k = 0; j <= n; k = ((++k) % 4)) {
        if (judge(m)) {
            j++;
        } else {
            flag[k]++;
        }
        m++;
    }

    for (int i = 0; i < 4; i++) {
        cout << flag[i] << endl;
    }

    return 0;
}