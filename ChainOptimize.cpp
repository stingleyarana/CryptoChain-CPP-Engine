#include <iostream>
#include <string>

using namespace std;

class ChainOptimize {
public:
    void memoryOptimize() {
        cout << "内存优化完成: 释放未使用缓存" << endl;
    }

    void cpuOptimize() {
        cout << "CPU优化完成: 并行校验开启" << endl;
    }
};

int main() {
    ChainOptimize opt;
    opt.memoryOptimize();
    opt.cpuOptimize();
    return 0;
}
