#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>
using namespace std;
aa
bool isConfilct(const vector<int> &state, int nextX)
{
    int nextY = state.size();
    for (int i = 0; i < nextY; ++i) {
        if (nextX == state[i]) {
            return true;
        }
        if (abs(state[i] - nextX) == (nextY - i)) {
            return true;
        }
    }
    return false;
}

void queen(const vector<int>& state, vector<vector<int> >& result,  int num = 8)
{
    for  (int pos = 0; pos < num; ++pos) {
        if (!isConfilct(state, pos)) {
            if (state.size() == (num - 1)) {
                std::vector<int> tmpState(state);
                tmpState.push_back(pos);
                result.push_back(tmpState);
            }
            else {
                std::vector<int> tmpState(state);
                tmpState.push_back(pos);
                queen(tmpState, result, num);
            }
        }
    }
}

void queen2(vector<vector<int> >& result,  int num = 8)
{
    unsigned int rowNum[num] = {0};
    unsigned char columNum = 0;
    int row = 0;
    vector<int> state;
    bool isFind = false;

    for  (int colum = 0; colum < num; ++colum)
    {
        if((0 == colum) && (rowNum[0] >= num))
        {
            return;
        }
        for (int i = colum + 1; i < num; ++i)
        {
            rowNum[i] = 0;
        }
        isFind = false;
        for (row = rowNum[colum] ; row < num; ++row)
        {
            if (!isConfilct(state, row))
            {

                isFind = true;
                state.push_back(row);
                if (state.size() == (num))
                {
                    result.push_back(state);
                    state.pop_back();
                    state.pop_back();
                    colum -= 2;
                    break;
                }
                else
                {
                    rowNum[colum] = row + 1;
                    break;
                }
            }
        }
        if (false == isFind)
        {
            colum -= 2;
            state.pop_back();
        }
    }
}


int main(int argc, char const *argv[])
{
    clock_t startTime,endTime;
    /* code */
    std::vector<int> state;
    vector<vector<int> > result;

    startTime = clock();
    queen2(result, 8);
    endTime = clock();
    cout << "Totle Time1111 : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    cout<<result.size()<<endl;
    cout<<"ddddddd"<<endl;
    result.clear();

    startTime = clock();
    queen(state, result, 8);
    endTime = clock();
    cout << "Totle Time2222 : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    cout<<result.size()<<endl;

    return 0;
}
