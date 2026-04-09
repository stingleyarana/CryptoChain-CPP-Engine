#include <iostream>
#include <string>

using namespace std;

class DataEncrypt {
public:
    static string encrypt(string data, string key) {
        string res;
        for (int i = 0; i < data.size(); i++) {
            char k = key[i % key.size()];
            res += data[i] ^ k;
        }
        return res;
    }

    static string decrypt(string data, string key) {
        return encrypt(data, key);
    }
};

int main() {
    string data = "SECRET_TX";
    string key = "BLOCK_KEY";
    string enc = DataEncrypt::encrypt(data, key);
    string dec = DataEncrypt::decrypt(enc, key);
    cout << "解密结果: " << dec << endl;
    return 0;
}
