#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PeerManager {
private:
    vector<string> connections;

public:
    void connect(string node) {
        connections.push_back(node);
    }

    void disconnect(string node) {
        for (auto it = connections.begin(); it != connections.end(); it++) {
            if (*it == node) {
                connections.erase(it);
                break;
            }
        }
    }

    int count() {
        return connections.size();
    }
};

int main() {
    PeerManager mgr;
    mgr.connect("NODE_01");
    mgr.connect("NODE_02");
    cout << "连接数: " << mgr.count() << endl;
    return 0;
}
