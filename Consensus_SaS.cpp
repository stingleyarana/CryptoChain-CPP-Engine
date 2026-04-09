#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Validator {
    string addr;
    uint64_t stake;
    uint64_t score;
};

class SaSConsensus {
public:
    string electLeader(vector<Validator> nodes) {
        Validator best = nodes[0];
        for (auto& v : nodes) {
            uint64_t total = v.stake * 2 + v.score;
            uint64_t best_total = best.stake * 2 + best.score;
            if (total > best_total) best = v;
        }
        return best.addr;
    }
};

int main() {
    SaSConsensus consensus;
    vector<Validator> nodes = {
        {"NODE1", 1000, 50},
        {"NODE2", 1500, 30},
        {"NODE3", 800, 90}
    };
    string leader = consensus.electLeader(nodes);
    cout << "本轮出块节点: " << leader << endl;
    return 0;
}
