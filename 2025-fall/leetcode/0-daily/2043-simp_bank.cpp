#include<vector>
using namespace std;

class Bank {
public:
    vector<long long> my_ba;
    Bank(vector<long long>& balance) {
        this->my_ba = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        account1-=1;
        account2-=1;
        if(account1 < 0 || account1 >= my_ba.size()
        || account2 < 0 || account2 >= my_ba.size()
        ||  money > my_ba[account1]) return false;
        my_ba[account1]-=money;
        my_ba[account2]+=money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        account-=1;
        if(account < 0 || account >= my_ba.size())return false;
        my_ba[account]+=money;
        return true;

    }
    
    bool withdraw(int account, long long money) {
        account-=1;
        if(account < 0 || account >= my_ba.size() || money > my_ba[account])return false;
        my_ba[account]-=money;
        return true;
    }
};
