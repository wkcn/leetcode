class Bank {
public:
    Bank(vector<long long>& balance) : balance_(balance) {

    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 < 1 || account1 > balance_.size()) return false;
        if (account2 < 1 || account2 > balance_.size()) return false;
        if (balance_[account1-1] < money) return false;
        balance_[account1 - 1] -= money;
        balance_[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account < 1 || account > balance_.size()) return false;
        balance_[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account < 1 || account > balance_.size()) return false;
        if (balance_[account - 1] < money) return false;
        balance_[account - 1] -= money;
        return true;
    }
private:
    vector<long long> balance_;
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
