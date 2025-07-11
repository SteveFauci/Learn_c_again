// 我用模拟，直接根据题意做完了，题解有*数位dp*，有空再读。。
class Solution {
public:
    int rotatedDigits(int n) {
        int sum = 0;
        for(int i = 0;i <= n;i++){
            if(is_good(i))sum++;
        }
        return sum;
    }

    int my_switch(int n){
        switch(n){
            case 1:return 1;
            case 2:return 5;
            case 5:return 2;
            case 6:return 9;
            case 8:return 8;
            case 9:return 6;
            case 0:return 0;
            default:return -1;
        }
    }

    bool is_good(int num){
        int ori_num = num;
        int exp = 1;
        int temp = 0;
        while(num){
            if(my_switch(num%10)==-1)return false;
            temp+=my_switch(num%10)*exp;
            exp*=10;
            num/=10;
        }
        if(temp!=ori_num)return true;
        return false;
    }
};
