#include <iostream>
#include <string>

using namespace std;

class ChainMonitor {
public:
    void showStatus(uint64_t height, int tps) {
        cout << "当前高度: " << height << endl;
        cout << "每秒交易: " << tps << endl;
    }
};

int main() {
    ChainMonitor monitor;
    monitor.showStatus(1000, 20);
    return 0;
}
