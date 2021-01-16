#include "iostream"

using namespace std;

class Solution {
public:
    int getMaximumGenerated(unsigned int n) {
        cout << "n=" << n << endl;
        unsigned int nums[n+1], max=0, i2=0;
        for(unsigned int i=0; i<n+1; i++) {
          if(i<2) {
            nums[i] = i;
            cout << "i=" << i << endl;
          }
          if(i>0) {
            i2 = 2*i;
            if(i2<=n)
              nums[i2] = nums[i];
            if(i2+1<=n)
              nums[i2+1] = nums[i] + nums[i+1];
          }
          cout << "i=" << i << ", nums[i]=" << nums[i] << endl;
          if(max<nums[i])
            max = nums[i];
        }
        return max;
    }};

int main(int argc, char *argv[]) {
    cout << "Hello leetcode !!!\n";
    unsigned int n = *argv[1]-48;
    cout << n << endl;

    Solution solve;
    cout << solve.getMaximumGenerated(n) << endl;

    return 0;
}
