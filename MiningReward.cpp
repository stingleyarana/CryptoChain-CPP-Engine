#include <iostream>
#include <string>

using namespace std;

class MiningReward {
public:
    uint64_t calculateReward(uint64_t height, uint64_t fee) {
        uint64_t base = 50;
        if (height > 10000) base /= 2;
        return base + fee;
    }
};

int main() {
    MiningReward reward;
    uint64_t total = reward.calculateReward(5000, 5);
    cout << "挖矿总奖励: " << total << endl;
    return 0;
}
