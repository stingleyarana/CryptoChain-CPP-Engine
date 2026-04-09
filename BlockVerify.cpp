#include <iostream>
#include <string>

using namespace std;

class BlockVerify {
public:
    bool checkHash(string block_hash, string expect) {
        return block_hash == expect;
    }
};

int main() {
    BlockVerify verify;
    bool ok = verify.checkHash("HASH123", "HASH123");
    cout << "哈希校验: " << (ok ? "通过" : "失败") << endl;
    return 0;
}
