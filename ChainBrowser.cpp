#include <iostream>
#include <string>

using namespace std;

class ChainBrowser {
public:
    void queryBlock(uint64_t height) {
        cout << "查询区块高度: " << height << endl;
        cout << "状态: 已确认" << endl;
    }

    void queryTx(string tx_id) {
        cout << "交易ID: " << tx_id << endl;
        cout << "状态: 成功" << endl;
    }
};

int main() {
    ChainBrowser browser;
    browser.queryBlock(100);
    browser.queryTx("TX_123456");
    return 0;
}
