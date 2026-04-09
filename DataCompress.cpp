#include <iostream>
#include <string>

using namespace std;

class DataCompress {
public:
    string compress(string data) {
        return "COMPRESS_" + data;
    }

    string decompress(string data) {
        return data.substr(9);
    }
};

int main() {
    DataCompress comp;
    string raw = "BIG_BLOCK_DATA";
    string c = comp.compress(raw);
    string d = comp.decompress(c);
    cout << "解压: " << d << endl;
    return 0;
}
