//实现标题数据抽词排序

#include "wordSort.h"
#include <string>
#include <vector>

//获取PAT数组
vector<string> WordSort::sortArr(vector<string> wordList) {
    vector<string> originWordList = wordList;
    vector<int> patArr(wordList.size(), 0);
    int i = 0;
    for(auto& word : patArr) {
        word = i;
        i++;
    }

    quickSort(wordList, 0, wordList.size() - 1, patArr);
    for(auto word : patArr) {
        cout << word << ",";
    }
    cout << endl;
    vector<int> lcpArr = pat2LcpArr(patArr, originWordList);
    for(auto word : lcpArr) {
        cout << word << ",";
    }
    cout << endl;
    return wordList;
}

//将pat数组转为lcp数组
vector<int> WordSort::pat2LcpArr(vector<int> patArr, vector<string> wordList) {
    vector<int> res;
    for (int i = 0; i < patArr.size() - 1; i++) {
        int len = getCommonStrLength(wordList[patArr[i]], wordList[patArr[i + 1]]);
        res.push_back(getCommonStrLength(wordList[patArr[i]], wordList[patArr[i + 1]]));
    }
	res.push_back(0);
    return res;
}


//通过对字符串数组排序获取所在位置的int数
//所以不用对wordlist排序，而是要要通过对wordlist的排序获取patArr的排序结果即PAT数组
void  WordSort::quickSort(vector<string>& wordList, int start, int end, vector<int>&patArr) {
    if (start >= end) {
        return;
    }
    int left = start;
    int right = end;
    string target = wordList[start];
    int position = patArr[start];

    while (left < right) {
        while(wordList[right] + target >= target + wordList[right] && right > left) {
            right--;
        }
        while (wordList[left] + target <= target + wordList[left] && left < right) {
            left++;
        }
        string t  = wordList[left];
        wordList[left] = wordList[right];
        wordList[right] = t;

        int temp  = patArr[left];
        patArr[left] = patArr[right];
        patArr[right] = temp;
    }
    wordList[start] = wordList[left];
    wordList[left] = target;

    patArr[start] = patArr[left];
    patArr[left] = position;
    quickSort(wordList, start, left - 1, patArr);
    quickSort(wordList, left + 1, end, patArr);

}

//字符串转数组
vector<string> WordSort::string2Arr(string title) {
    vector<string> res;
    int length = title.length();
    cout << length << endl;
    for(int i = 0; i < length; i += 1) {
        string temp = title.substr(i, length - i);
        res.push_back(temp);
    }
    return res;
}

//获取公共字符串长度
int WordSort::getCommonStrLength(string str1, string str2) {
    int i = 0;
    while (str1[i] == str2[i]) {
        i++;
    }
    return i;
}

void WordSort::test() {
    cout << "test" << endl;
}
