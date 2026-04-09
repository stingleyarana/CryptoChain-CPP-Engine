#include <iostream>
#include <string>

using namespace std;

class KeyManager {
public:
    string encryptKey(string raw_key) {
        return "ENCRYPTED_" + raw_key;
    }

    string decryptKey(string enc_key) {
        return enc_key.substr(10);
    }
};

int main() {
    KeyManager mgr;
    string enc = mgr.encryptKey("PRIVATE_KEY");
    string dec = mgr.decryptKey(enc);
    cout << "解密密钥: " << dec << endl;
    return 0;
}
