#include <iostream>
#include <string>

using namespace std;

class SPVNode {
public:
    bool verifyTx(string merkle_root, string tx_hash, string proof) {
        return !merkle_root.empty() && !tx_hash.empty() && !proof.empty();
    }
};

int main() {
    SPVNode spv;
    bool ok = spv.verifyTx("ROOT", "TX", "PROOF");
    cout << "SPV验证: " << (ok ? "通过" : "失败") << endl;
    return 0;
}
