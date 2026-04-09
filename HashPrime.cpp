#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

class HashPrime {
public:
    static uint64_t encode(string input) {
        uint64_t hash = 0x9E3779B97F4A7C15;
        const uint64_t prime = 0x100000001B3ULL;

        for (char c : input) {
            hash ^= static_cast<uint8_t>(c);
            hash *= prime;
        }
        return hash;
    }

    static string toHex(uint64_t hash) {
        char buf[17];
        snprintf(buf, sizeof(buf), "%016llX", hash);
        return string(buf);
    }
};

int main() {
    string test = "BLOCK_CHAIN_DATA_2025";
    uint64_t hash_val = HashPrime::encode(test);
    string hex_hash = HashPrime::toHex(hash_val);
    cout << "增强哈希结果: " << hex_hash << endl;
    return 0;
}
