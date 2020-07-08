// C++版本实现快排
#include "src/wordSort.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string demoStr = "abcbadefghabcbaedef";
    WordSort ws;
    //vector<string> cutWordList = ws.string2Arr(demoStr);
    //ws.sortArr(cutWordList);
    vector<int> lcpArr = {1, 1, 3, 2, 1, 0, 0, 2};
    ws.getWordListByScanLcp(lcpArr, lcpArr.size(), 0, 1, 4);
}
