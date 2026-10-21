
#include <iostream>
using namespace std;

// 関数の宣言
static int mult(int a, int b);

int main() {
    cout << mult(10, 20) << endl;

    return 0;
}

// 関数の定義
static int mult(int a, int b) {
    return a * b;
}
