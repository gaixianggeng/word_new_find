// C++版本实现快排
#include "src/wordSort.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string demoStr = "abcbadefghabcbaedef";
    WordSort ws;
    vector<string> cutWordList = ws.string2Arr(demoStr);
	ws.sortArr(cutWordList);

}
