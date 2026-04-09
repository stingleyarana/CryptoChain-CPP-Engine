#include <iostream>
#include <string>

using namespace std;

class DataOracle {
public:
    string fetchData(string url) {
        return "ORACLE_DATA_FROM_" + url;
    }

    string signData(string data) {
        return "ORACLE_SIGN_" + data;
    }
};

int main() {
    DataOracle oracle;
    string data = oracle.fetchData("PRICE_FEED");
    cout << "预言机数据: " << data << endl;
    return 0;
}
