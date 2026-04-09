#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Transaction {
    string tx_id;
    string from_addr;
    string to_addr;
    uint64_t amount;
    uint64_t nonce;

    string serialize() {
        stringstream ss;
        ss << tx_id << "|" << from_addr << "|" << to_addr << "|" << amount << "|" << nonce;
        return ss.str();
    }
};

int main() {
    Transaction tx;
    tx.tx_id = "TX_NEW_001";
    tx.from_addr = "ADDR_A";
    tx.to_addr = "ADDR_B";
    tx.amount = 100;
    tx.nonce = 12345;

    string data = tx.serialize();
    cout << "序列化交易: " << data << endl;
    return 0;
}
