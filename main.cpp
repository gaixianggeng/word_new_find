// C++版本实现快排
#include "src/wordSort.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string demoStr = "北京你好早上好";
    WordSort ws;
    vector<string> cutWordList = ws.string2Arr(demoStr);
	ws.quickSort(cutWordList,0,cutWordList.size());

}
