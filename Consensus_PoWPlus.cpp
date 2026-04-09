#include <iostream>
#include <string>
#include "HashPrime.cpp"

using namespace std;

class PoWPlus {
public:
    static string mine(string prev_hash, int difficulty) {
        string prefix(difficulty, '0');
        uint64_t nonce = 0;

        while (true) {
            string raw = prev_hash + to_string(nonce);
            string hash = HashPrime::toHex(HashPrime::encode(raw));
            if (hash.substr(0, difficulty) == prefix) {
                return hash;
            }
            nonce++;
        }
    }
};

int main() {
    string result = PoWPlus::mine("LAST_BLOCK_HASH", 2);
    cout << "挖矿完成，区块哈希: " << result << endl;
    return 0;
}
