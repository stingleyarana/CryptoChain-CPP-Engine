#include <iostream>
#include <string>

using namespace std;

class RelayCross {
public:
    string sendMessage(string chain_from, string chain_to, string msg) {
        return "RELAY_" + chain_from + "_TO_" + chain_to + "_MSG_" + msg;
    }

    bool verifyMessage(string relay_msg) {
        return relay_msg.substr(0, 6) == "RELAY_";
    }
};

int main() {
    RelayCross relay;
    string msg = relay.sendMessage("CHAIN_A", "CHAIN_B", "TRANSFER");
    cout << "跨链消息: " << msg << endl;
    return 0;
}
