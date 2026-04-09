#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

class PeerAuth {
private:
    unordered_set<string> whitelist;

public:
    void addWhite(string node) {
        whitelist.insert(node);
    }

    bool auth(string node) {
        return whitelist.count(node) > 0;
    }
};

int main() {
    PeerAuth auth;
    auth.addWhite("TRUSTED_NODE");
    cout << "授权: " << (auth.auth("TRUSTED_NODE") ? "通过" : "拒绝") << endl;
    return 0;
}
