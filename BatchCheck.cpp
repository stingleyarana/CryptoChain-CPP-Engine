#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BatchCheck {
public:
    int verifyBatch(vector<string> signs) {
        int count = 0;
        for (auto& s : signs) {
            if (s.substr(0, 5) == "SIGN_") count++;
        }
        return count;
    }
};

int main() {
    BatchCheck check;
    vector<string> signs = {"SIGN_1", "SIGN_2", "FAKE"};
    int ok = check.verifyBatch(signs);
    cout << "有效签名数: " << ok << endl;
    return 0;
}
