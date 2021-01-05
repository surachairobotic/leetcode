#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        if(arr.size() > 100 ||
           arr.size() < pieces.size() ||
           pieces.size() < 1)
           return false;
        unsigned int _sum=0;
        for(unsigned int i=0; i<pieces.size(); i++) {
            _sum += pieces[i].size();
            for(unsigned int j=0; j<pieces[i].size(); j++)
                if(pieces[i][j] < 1 || pieces[i][j] > 100)
                    return false;
        }
        if(_sum != arr.size())
            return false;
        for(unsigned int i=0; i<arr.size(); i++) {
            if(arr[i] < 1 || arr[i] > 100)
                return false;
            bool b_match=false;
            for(unsigned int j=0; j<pieces.size(); j++) {
                bool chk=true;
                for(unsigned int k=0; k<pieces[j].size(); k++) {
                    if(arr[i+k] != pieces[j][k])
                        chk=false;
                }
                if(chk) {
                    b_match=true;
                    i+=(pieces[j].size()-1);
                    pieces.erase(pieces.begin()+j);
                    break;
                }
            }
            if(!b_match)
                return false;
        }
        return true;
    }
};


int main() {
    cout << "Hello leetcode !!!\n";
    
    vector<int> arr = {32,66,73,15,3,70,53};
    vector<vector<int>> pieces = {{66,73},{15},{3},{32},{70},{53}};
    
    Solution solve;
    if(solve.canFormArray(arr, pieces))
        cout << "True\n";
    else
        cout << "Fasle\n";

    return 0;
}
