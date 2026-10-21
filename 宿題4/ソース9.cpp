
#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string name;
    int speed;

public:
    // 引数付きコンストラクタ
    Car(string n, int s) {
        name = n;
        speed = s;
    }

    // 加速する
    void Accelerate() {
        speed += 10;
    }

    // 減速する
    void Brake() {
        speed -= 10;
    }

    // 情報を表示する
    void Show() {
        cout << "車の名前：" << name << endl;
        cout << "現在の速度：" << speed << "km/h" << endl;
    }
};

int main() {
    Car car("プリウス", 50);

    car.Show();

    car.Accelerate();
    car.Show();

    car.Brake();
    car.Show();

    return 0;
}
