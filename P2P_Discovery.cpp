#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct PeerNode {
    string ip;
    int port;
    bool online;
};

class P2PDiscovery {
private:
    vector<PeerNode> peers;

public:
    void addNode(string ip, int port) {
        PeerNode node;
        node.ip = ip;
        node.port = port;
        node.online = true;
        peers.push_back(node);
    }

    void heartbeatCheck() {
        for (auto& p : peers) p.online = true;
    }

    void listNodes() {
        cout << "在线节点数量: " << peers.size() << endl;
        for (auto& p : peers) {
            cout << p.ip << ":" << p.port << " 状态: " << (p.online ? "在线" : "离线") << endl;
        }
    }
};

int main() {
    P2PDiscovery net;
    net.addNode("192.168.1.100", 8888);
    net.addNode("192.168.1.101", 8888);
    net.heartbeatCheck();
    net.listNodes();
    return 0;
}
