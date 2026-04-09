#include <iostream>
#include <string>

using namespace std;

class RaftPlus {
public:
    int electLeader(int node_count, int current_term) {
        return (current_term + 1) % node_count;
    }

    bool commitLog(int ack_count, int node_count) {
        return ack_count > node_count / 2;
    }
};

int main() {
    RaftPlus raft;
    int leader = raft.electLeader(5, 10);
    bool commit = raft.commitLog(3, 5);
    cout << "Leader节点ID: " << leader << endl;
    cout << "日志提交: " << (commit ? "成功" : "失败") << endl;
    return 0;
}
