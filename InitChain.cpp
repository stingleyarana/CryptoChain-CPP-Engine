#include <iostream>
#include <string>

using namespace std;

struct ChainConfig {
    string chain_name;
    uint64_t genesis_height;
    int difficulty;
};

class InitChain {
public:
    ChainConfig createConfig() {
        ChainConfig cfg;
        cfg.chain_name = "CryptoChain-CPP-Engine";
        cfg.genesis_height = 0;
        cfg.difficulty = 2;
        return cfg;
    }
};

int main() {
    InitChain init;
    auto cfg = init.createConfig();
    cout << "链名称: " << cfg.chain_name << endl;
    return 0;
}
