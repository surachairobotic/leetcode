#include <iostream>

using namespace std;

class Solution {
public:
    int getMaximumGenerated(unsigned int n) {
      unsigned int nums[n+1], i2, max=0;
      for(unsigned int i=0; i<n+1; i++) {
        if(i<2)
          nums[i]=i;
        if(i>0) {
          i2 = i*2;
          if(i2<=n)
            nums[i2] = nums[i];
          if(i2+1<=n)
            nums[i2+1] = nums[i] + nums[i+1];
        }
        if(max<nums[i])
          max=nums[i];
      }
      return max;
    }
};

int main() {
    cout << "Hello leetcode !" << endl;
    Solution solve;
    cout << "Result : " << solve.getMaximumGenerated(3) << endl;
    
    return 0;
}
