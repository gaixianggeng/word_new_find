//实现标题数据抽词排序

#include "wordSort.h"

vector<string> WordSort::quickSort(vector<string> wordList, int start, int end) {
    vector<string> res;
    for(auto word : wordList) {
        cout << word << endl;
    }
    return res;

}
vector<string> WordSort::string2Arr(string title) {
    vector<string> res;
	int length = title.length();
	cout<<length<<endl;
	for(int i = 0;i<length;i+=3){
		string temp = title.substr(i,length-i);
		res.push_back(temp);
	}
    return res;
}

void WordSort::test() {
    cout << "test" << endl;
}
