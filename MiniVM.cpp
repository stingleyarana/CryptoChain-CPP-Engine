#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MiniVM {
private:
    vector<uint64_t> stack;

public:
    void push(uint64_t val) {
        stack.push_back(val);
    }

    uint64_t pop() {
        if (stack.empty()) return 0;
        uint64_t val = stack.back();
        stack.pop_back();
        return val;
    }

    void add() {
        uint64_t a = pop();
        uint64_t b = pop();
        push(a + b);
    }
};

int main() {
    MiniVM vm;
    vm.push(10);
    vm.push(20);
    vm.add();
    cout << "计算结果: " << vm.pop() << endl;
    return 0;
}
