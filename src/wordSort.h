#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class WordSort {
public:
    vector<string> string2Arr(string);
    map<string, int> sortArr(vector<string>);
    vector<vector<int>> scanLcp(vector<int>, int, int, int, int);
    void test();
private:
    int getCommonStrLength(string, string);
    vector<int> pat2LcpArr(vector<int>, vector<string>);
    void quickSort(vector<string>&, int, int, vector<int>&);
};
