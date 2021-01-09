#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        unsigned int vIndx1=0, vIndx2=0, sIndx1=0, sIndx2=0;
        if( word1.size()<1 || word2.size()<1 )
            return false;
        else if( word1[0].size()<1 || word2.size()<1 )
            return false;
        bool bEnd1=false, bEnd2=false;;
        while(1) {
            if( word1[vIndx1][sIndx1] != word2[vIndx2][sIndx2] )
                return false;

            sIndx1+=1;
            if( sIndx1>=word1[vIndx1].size() ) {
                vIndx1+=1;
                if( vIndx1<word1.size() )
                    sIndx1=0;
                else
                    bEnd1=true;
            }
            sIndx2+=1;
            if( sIndx2>=word2[vIndx2].size() ) {
                vIndx2+=1;
                if( vIndx2<word2.size() )
                    sIndx2=0;
                else
                    bEnd2=true;
            }

            if( bEnd1 != bEnd2 )
                return false;
            else if( bEnd1 && bEnd2 )
                break;
        }
        return true;
    }
};


int main() {
    cout << "Hello leetcode !!!\n";
    
    vector<string> word1 = {"abc", "d", "defg"};
    vector<string> word2 = {"abcddefg"};
    
    Solution solve;
    if(solve.arrayStringsAreEqual(word1, word2))
        cout << "True\n";
    else
        cout << "Fasle\n";

    return 0;
}
