#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DecentralizeCore {
public:
    bool voteResult(vector<bool> votes) {
        int yes = 0;
        for (bool v : votes) if (v) yes++;
        return yes > votes.size() / 2;
    }
};

int main() {
    DecentralizeCore core;
    vector<bool> votes = {true, true, false};
    bool res = core.voteResult(votes);
    cout << "投票结果: " << (res ? "通过" : "拒绝") << endl;
    return 0;
}
