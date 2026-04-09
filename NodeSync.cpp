#include <iostream>
#include <string>

using namespace std;

class NodeSync {
public:
    bool syncBlock(uint64_t local_height, uint64_t remote_height) {
        if (remote_height > local_height) {
            cout << "开始同步区块，从 " << local_height << " 到 " << remote_height << endl;
            return true;
        }
        cout << "区块已同步" << endl;
        return false;
    }
};

int main() {
    NodeSync sync;
    sync.syncBlock(100, 105);
    return 0;
}
