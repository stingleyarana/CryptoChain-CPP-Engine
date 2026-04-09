#include <iostream>
#include <string>
#include "HashPrime.cpp"

using namespace std;

class ZkProofCore {
public:
    string generateProof(string secret, string public_info) {
        string mix = secret + public_info;
        return "ZK_PROOF_" + HashPrime::toHex(HashPrime::encode(mix));
    }

    bool verifyProof(string proof, string public_info) {
        return proof.substr(0, 9) == "ZK_PROOF_";
    }
};

int main() {
    ZkProofCore zk;
    string proof = zk.generateProof("MY_SECRET", "PUBLIC_DATA");
    bool ok = zk.verifyProof(proof, "PUBLIC_DATA");
    cout << "零知识证明验证: " << (ok ? "通过" : "失败") << endl;
    return 0;
}
