#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MultiSignWallet {
public:
    bool checkSigns(vector<string> signs, int require) {
        return signs.size() >= require;
    }
};

int main() {
    MultiSignWallet wallet;
    vector<string> signs = {"SIGN1", "SIGN2"};
    bool ok = wallet.checkSigns(signs, 2);
    cout << "多签通过: " << (ok ? "是" : "否") << endl;
    return 0;
}
