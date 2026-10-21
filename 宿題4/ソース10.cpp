
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// プレイヤークラス
class Player {
private:
    string name;
    int hand;

public:
    // 引数付きコンストラクタ
    Player(string n) {
        name = n;
        hand = 0;
    }

    // プレイヤーの手を決定
    void SelectHand() {
        do {
            cout << name << "の手を選んでください" << endl;
            cout << "0:グー 1:チョキ 2:パー" << endl;
            cin >> hand;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                hand = -1;
            }

        } while (hand < 0 || hand > 2);
    }

    // 名前を取得
    string GetName() const {
        return name;
    }

    // 手を取得
    int GetHand() const {
        return hand;
    }
};

// コンピュータクラス
class Computer {
private:
    string name;
    int hand;

public:
    // 引数付きコンストラクタ
    Computer(string n) {
        name = n;
        hand = 0;
    }

    // コンピュータの手を決定
    void SelectHand() {
        hand = rand() % 3;
    }

    // 名前を取得
    string GetName() const {
        return name;
    }

    // 手を取得
    int GetHand() const {
        return hand;
    }
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    // オブジェクト作成
    Player player("プレイヤー");
    Computer cpu("コンピュータ");

    string hands[] = { "グー", "チョキ", "パー" };

    // それぞれのクラスで手を決める
    player.SelectHand();
    cpu.SelectHand();

    // 手を表示
    cout << player.GetName() << "："
        << hands[player.GetHand()] << endl;

    cout << cpu.GetName() << "："
        << hands[cpu.GetHand()] << endl;

    // 勝敗判定
    if (player.GetHand() == cpu.GetHand()) {
        cout << "あいこです" << endl;
    }
    else if ((player.GetHand() + 1) % 3 == cpu.GetHand()) {
        cout << player.GetName() << "の勝ち！" << endl;
    }
    else {
        cout << cpu.GetName() << "の勝ち！" << endl;
    }

    return 0;
}
