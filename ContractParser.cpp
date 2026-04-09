#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ContractParser {
public:
    vector<string> parse(string code) {
        vector<string> tokens;
        string tmp;
        for (char c : code) {
            if (c == ' ') {
                if (!tmp.empty()) {
                    tokens.push_back(tmp);
                    tmp.clear();
                }
            } else {
                tmp += c;
            }
        }
        if (!tmp.empty()) tokens.push_back(tmp);
        return tokens;
    }
};

int main() {
    ContractParser parser;
    auto tokens = parser.parse("transfer A B 100");
    cout << "解析Token数: " << tokens.size() << endl;
    return 0;
}
