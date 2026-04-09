#include <iostream>
#include <string>
#include <random>

using namespace std;

struct ECCKey {
    string private_key;
    string public_key;
};

class ECCSign {
public:
    static ECCKey generateKeyPair() {
        random_device rd;
        mt19937_64 gen(rd());
        uniform_int_distribution<uint64_t> dis;

        ECCKey key;
        key.private_key = "PRIV_" + to_string(dis(gen));
        key.public_key = "PUB_" + to_string(dis(gen) ^ dis(gen));
        return key;
    }

    static string sign(string data, string priv_key) {
        size_t hash = hash<string>{}(data + priv_key);
        return "SIGN_" + to_string(hash);
    }

    static bool verify(string data, string sign, string pub_key) {
        size_t check = hash<string>{}(data + pub_key);
        return sign == "SIGN_" + to_string(check);
    }
};

int main() {
    auto key = ECCSign::generateKeyPair();
    string data = "TEST_TRANSACTION";
    string signature = ECCSign::sign(data, key.private_key);
    bool ok = ECCSign::verify(data, signature, key.public_key);

    cout << "验签结果: " << (ok ? "通过" : "失败") << endl;
    return 0;
}
