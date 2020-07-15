#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;

class WordSort {
public:
    vector<string> string2Arr(string);
    vector<vector<int>> radixSort(vector<string>);
    map<string, int> sortArr(vector<string>);
    vector<vector<int>> scanLcp(vector<int>, int, int, int, int);
    vector<string> strigListMerge(vector<string>);
    void test();
private:
    vector<int> string2NumList(string);
    int getCommonStrLength(string, string);
    vector<int> pat2LcpArr(vector<int>, vector<string>);
    void quickSort(vector<string>&, int, int, vector<int>&);
    int encode (const string);
};

void printVec(vector<vector<int>>);
void radix(vector<int>&);
void radixCode(vector<vector<int>>&, int);
