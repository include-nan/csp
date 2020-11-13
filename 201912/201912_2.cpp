#include <iostream>
using namespace std;
struct Node {
    int x;
    int y;
};

bool isbin(Node node[], int i, int n) {
    int flag = 0;
    for (int j = 0; j < n; j++) {
        if (node[i].x == node[j].x && node[i].y == node[j].y) {
            continue;
        }
        if (node[i].x == node[j].x && node[i].y == node[j].y - 1) {
            flag++;
        }
        if (node[i].x == node[j].x && node[i].y == node[j].y + 1) {
            flag++;
        }
        if (node[i].x == node[j].x + 1 && node[i].y == node[j].y) {
            flag++;
        }
        if (node[i].x == node[j].x - 1 && node[i].y == node[j].y) {
            flag++;
        }
    }
    if (flag == 4) {
        return true;
    }
    return false;
}

int Ssocre(Node node[], int i, int n) {
    int tmp = 0;
    for (int q = 0; q < n; q++) {
        if (i == q) {
            continue;
        }
        if (node[i].x == node[q].x + 1 && node[i].y == node[q].y - 1) {
            tmp++;
        }
        if (node[i].x == node[q].x - 1 && node[i].y == node[q].y + 1) {
            tmp++;
        }
        if (node[i].x == node[q].x + 1 && node[i].y == node[q].y + 1) {
            tmp++;
        }
        if (node[i].x == node[q].x - 1 && node[i].y == node[q].y - 1) {
            tmp++;
        }
    }
    return tmp;
}
int main() {
    int n;
    cin >> n;
    int score[5] = {0, 0, 0, 0, 0};
    Node node[n];

    for (int i = 0; i < n; i++) {
        cin >> node[i].x >> node[i].y;
    }

    for (int i = 0; i < n; i++) {
        int flag = 0;
        if (isbin(node, i, n)) {
            score[Ssocre(node, i, n)]++;
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << score[i] << endl;
    }

    return 0;
}