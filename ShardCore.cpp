#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ShardCore {
public:
    vector<vector<string>> splitTxs(vector<string> txs, int shard_num) {
        vector<vector<string>> shards(shard_num);
        for (int i = 0; i < txs.size(); i++) {
            shards[i % shard_num].push_back(txs[i]);
        }
        return shards;
    }
};

int main() {
    ShardCore shard;
    vector<string> txs = {"TX1", "TX2", "TX3", "TX4"};
    auto res = shard.splitTxs(txs, 2);
    cout << "分片1交易数: " << res[0].size() << endl;
    return 0;
}
