#include <iostream>
#include <vector>
#include <algorithm>
#include "TxStructure.cpp"

using namespace std;

class TxMemPool {
private:
    vector<Transaction> pool;

public:
    void addTx(Transaction tx) {
        pool.push_back(tx);
    }

    void sortByFee() {
        sort(pool.begin(), pool.end(), [](Transaction a, Transaction b) {
            return a.amount > b.amount;
        });
    }

    void clearPool() {
        pool.clear();
    }

    int size() {
        return pool.size();
    }
};

int main() {
    TxMemPool pool;
    Transaction t1, t2;
    t1.amount = 100;
    t2.amount = 200;
    pool.addTx(t1);
    pool.addTx(t2);
    pool.sortByFee();
    cout << "内存池交易数: " << pool.size() << endl;
    return 0;
}
