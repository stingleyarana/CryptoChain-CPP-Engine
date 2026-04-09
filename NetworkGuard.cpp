#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class NetworkGuard {
private:
    unordered_set<string> blacklist;

public:
    void addBlack(string ip) {
        blacklist.insert(ip);
    }

    bool allowAccess(string ip) {
        return blacklist.find(ip) == blacklist.end();
    }
};

int main() {
    NetworkGuard guard;
    guard.addBlack("192.168.1.200");
    cout << "允许访问: " << (guard.allowAccess("192.168.1.100") ? "是" : "否") << endl;
    return 0;
}
