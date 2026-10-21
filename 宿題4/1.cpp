
#include <iostream>
using namespace std;

const char* str_match(const char* s1, const char* s2) {
    for (int i = 0; s1[i] != '\0'; i++) {
        int j = 0;

        while (s2[j] != '\0' && s1[i + j] != '\0'
            && s1[i + j] == s2[j]) {
            j++;
        }

        if (s2[j] == '\0') {
            return &s1[i];
        }
    }

    return nullptr;
}

int main() {
    const char* s1 = "abcabcdef";
    const char* s2 = "abcd";

    const char* p = str_match(s1, s2);

    if (p != nullptr) {
        cout << p << endl;
    }
    else {
        cout << "見つかりません" << endl;
    }

    return 0;
}
