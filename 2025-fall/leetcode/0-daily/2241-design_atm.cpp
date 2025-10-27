#include<vector>
using namespace std;
class ATM {
public:
    const int notes[5] = {20,50,100,200,500};
    vector<int> myCnt;
    ATM() {
        myCnt = vector<int>(5,0);
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0; i < 5; i++){
            myCnt[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> temp = myCnt;
        vector<int> rtv(5,0);
        for(int  i = 4; i >= 0; i--){
            int take = min(temp[i], amount / notes[i]);
            rtv[i] = take;
            temp[i] -= take;
            amount -= take * notes[i];
        }
        if(amount)return vector<int>{-1};
        myCnt = temp;
        return rtv;
    }
};