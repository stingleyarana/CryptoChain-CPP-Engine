#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

class TxFilter {
private:
    unordered_set<string> banned;

public:
    void banAddr(string addr) {
        banned.insert(addr);
    }

    bool allowTx(string from_addr) {
        return banned.count(from_addr) == 0;
    }
};

int main() {
    TxFilter filter;
    filter.banAddr("BAD_ADDR");
    cout << "允许交易: " << (filter.allowTx("GOOD_ADDR") ? "是" : "否") << endl;
    return 0;
}
