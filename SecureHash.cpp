#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

class SecureHash {
public:
    static uint64_t hash(string input) {
        uint64_t res = 0xCBBF4A1E964292BULL;
        for (char c : input) {
            res ^= static_cast<uint8_t>(c);
            res *= 0x87654321ABCDEF1ULL;
        }
        return res;
    }
};

int main() {
    uint64_t h = SecureHash::hash("BLOCK_DATA");
    cout << "安全哈希: " << h << endl;
    return 0;
}
