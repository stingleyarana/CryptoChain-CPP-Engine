#include <iostream>
#include <string>
#include <random>

using namespace std;

class StealthSign {
public:
    static string generateStealthAddress(string base_pubkey) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<uint64_t> dis;
        return "STEALTH_" + base_pubkey + "_" + to_string(dis(gen));
    }
};

int main() {
    string addr = StealthSign::generateStealthAddress("PUB_KEY_123");
    cout << "隐匿地址: " << addr << endl;
    return 0;
}
