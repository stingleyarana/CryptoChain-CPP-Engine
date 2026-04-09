#include <iostream>
#include <vector>
#include <string>
#include "HashPrime.cpp"

using namespace std;

class MerkleProof {
public:
    static string buildRoot(vector<string> txs) {
        if (txs.empty()) return "EMPTY_ROOT";
        vector<string> layer = txs;

        while (layer.size() > 1) {
            vector<string> next;
            for (int i = 0; i < layer.size(); i += 2) {
                string left = layer[i];
                string right = (i+1 < layer.size()) ? layer[i+1] : left;
                string combine = HashPrime::toHex(HashPrime::encode(left+right));
                next.push_back(combine);
            }
            layer = next;
        }
        return layer[0];
    }
};

int main() {
    vector<string> txs = {"TX1", "TX2", "TX3"};
    string root = MerkleProof::buildRoot(txs);
    cout << "默克尔根: " << root << endl;
    return 0;
}
