class Solution {
public:
    int sumOfsq(int n){
        int ans = 0;
        while(n>0){
            int d = n%10;
            ans+=(d*d);
            n=n/10;
        }
        return ans ;
    }
    bool isHappy(int n) {
        int slow = n ;
        int fast = sumOfsq(n);

        while(fast!=1 && slow!=fast ){
            slow = sumOfsq(slow);
            fast = sumOfsq(sumOfsq(fast));
        }

       return fast==1;
    }
};