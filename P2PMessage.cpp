#include <iostream>
#include <string>

using namespace std;

class P2PMessage {
public:
    string pack(string type, string data) {
        return type + "|" + data;
    }

    string unpack(string msg) {
        size_t pos = msg.find('|');
        return msg.substr(pos + 1);
    }
};

int main() {
    P2PMessage msg;
    string pack = msg.pack("BLOCK", "HEIGHT_100");
    string data = msg.unpack(pack);
    cout << "消息数据: " << data << endl;
    return 0;
}
