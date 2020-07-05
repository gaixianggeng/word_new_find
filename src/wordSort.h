#include <iostream>
#include <vector>
#include <string>
using namespace std;

class WordSort {
public:
    vector<string> string2Arr(string);
    vector<string> sortArr(vector<string>);
    void test();

private:
    int getCommonStrLength(string, string);
    vector<int> pat2LcpArr(vector<int>, vector<string>);
    void quickSort(vector<string>&, int, int, vector<int>&);
};
