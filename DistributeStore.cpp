#include <iostream>
#include <vector>
#include <string>

using namespace std;

class DistributeStore {
public:
    vector<string> splitData(string data, int parts) {
        vector<string> res;
        int len = data.size() / parts;
        for (int i = 0; i < parts; i++) {
            int start = i * len;
            int end = (i == parts-1) ? data.size() : start + len;
            res.push_back(data.substr(start, end - start));
        }
        return res;
    }
};

int main() {
    DistributeStore store;
    auto parts = store.splitData("BLOCKCHAIN_DATA_STORE", 3);
    cout << "分片数量: " << parts.size() << endl;
    return 0;
}
