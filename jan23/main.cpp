#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> result = mat;
        cout << "1111111" << endl;
        for(int i=mat.size()-2; i>=0; --i) {
            unsigned int kj=0, ki=i;
            vector<int> s;
            do {
                cout << mat[ki][kj] << ", ";
                s.push_back(mat[ki][kj]);
                ++ki;
                ++kj;
            } while(ki<mat.size() && kj<mat[0].size());
            cout << endl;

            sort(&s);

            kj=0;
            ki=i;
            for(unsigned int m=0; m<s.size(); m++) {
                result[ki+m][kj+m] = s[m];
            }
        }
        cout << "2222222" << endl;
        for(unsigned int j=1; j<mat[0].size()-1; j++) {
            unsigned int kj=j, ki=0;
            vector<int> s;
            do {
                cout << mat[ki][kj] << ", ";
                s.push_back(mat[ki][kj]);
                ++ki;
                ++kj;
            } while(ki<mat.size() && kj<mat[0].size());
            cout << endl;
            
            sort(&s);

            kj=j;
            ki=0;
            for(unsigned int m=0; m<s.size(); m++) {
                result[ki+m][kj+m] = s[m];
            }
        }
            return result;
    }
    void sort(vector<int> *s) {
        unsigned int k;
        for(unsigned int i=0; i<s->size()-1; i++) {
            for(unsigned int j=i+1; j<s->size(); j++) {
                if(s->at(i)>s->at(j)) {
                    k=s->at(i);
                    s->at(i)=s->at(j);
                    s->at(j)=k;
                }
            }
        }
    }
};

void print_mat(vector<vector<int>> &mat);

int main() {
    cout << "Hello leetcode !" << endl;
    vector<vector<int>> mat = {{4,4,4,4},{3,3,3,3},{2,2,2,2},{1,1,1,1}}, result;
    print_mat(mat);
    Solution solve;
    result = solve.diagonalSort(mat);
    cout << "-----------" << endl;
    print_mat(result);
    
    return 0;
}

void print_mat(vector<vector<int>> &mat) {
    for(unsigned int i=0; i<mat.size(); i++) {
        for(unsigned int j=0; j<mat[0].size(); j++) {
            cout << mat[i][j];
            if(j!=mat[0].size()-1)
                cout << ", ";
        }
        cout << endl;
    }
}
