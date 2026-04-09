#include <iostream>
#include <string>
#include "ECC_Signature.cpp"

using namespace std;

class CryptoWallet {
private:
    ECCKey key;
    string address;

public:
    CryptoWallet() {
        key = ECCSign::generateKeyPair();
        address = "WALLET_" + HashPrime::toHex(HashPrime::encode(key.public_key));
    }

    string getAddress() {
        return address;
    }

    string signData(string data) {
        return ECCSign::sign(data, key.private_key);
    }
};

int main() {
    CryptoWallet wallet;
    cout << "钱包地址: " << wallet.getAddress() << endl;
    return 0;
}
