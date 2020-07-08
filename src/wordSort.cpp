//实现标题数据抽词排序

#include "wordSort.h"
#include <string>
#include <vector>

//获取PAT数组和LCP数组
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
    for(auto word : wordList) {
        cout << word << ",";
    }
    cout << endl;

    scanLcp(lcpArr, lcpArr.size(), 0, 2, 6);
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
//通过lcp数组获取词频 new
void WordSort::getWordListByScanLcp(vector<int> lcpArr, int count, int start, int minLen, int maxLen) {
    while(start < count) {
        int left = -1;
        int right = -1;
        int lcpStart = 0;
        int length = 0;
        for(int i = start; i < count; i++) {
            if(lcpArr[i] >= minLen) {
                left = i;
            }
            if (left != -1 && lcpArr[i] > lcpArr[left]) {
                lcpStart = i;
            }
            if (left != -1 && lcpArr[i] < lcpArr[left]) {
                right = i;
            }

        }
		cout<<"left:"<<left<<" right:"<<right<<" lcpStart:"<<lcpStart<<endl;
        if (lcpStart != -1 && lcpStart < right) {
            start = lcpStart;
        } else {
            start = right;
        }
        if (left != -1 && right != -1) {
            length = right - left + 1;
        } else if (left == -1) {
            length = 0;
        } else if (left != -1 && right == -1) {
            length = count - left;
        }
    }
}


//通过lcp数组获取词频
void WordSort::scanLcp(vector<int> lcpArr, int count, int start, int minLen, int maxLen) {
    int left = start;
    while (left <= count - 1) {
        int lcpStart = left;
        bool isFirst = true;
        bool isLarge = true;
        bool isContinue = true;

        int j = 0;
        int i = left;

        for (; i < count; i++) {
            //超过成词的最大长度
            if (lcpArr[i] > maxLen) {
                left += 1;
                break;
            }
            if (isFirst) {
                if (i - 1 >= 0) {
                    if (lcpArr[i - 1] >= lcpArr[i]) {
                        for (int k = i - 1; k >= 0; k--) {
                            if (lcpArr[k] >= minLen && lcpArr[k] != lcpArr[i]) {
                                j += 1;
                            } else {
                                if (lcpArr[k] == lcpArr[i]) {
                                    isContinue = false;
                                    j = 0;
                                }
                                break;
                            }
                        }
                    }
                }
            }
            if (lcpArr[i] >= minLen && lcpArr[i] >= lcpArr[left] && isContinue) {
                if (isFirst) {
                    lcpStart = i;
                    isFirst = false;
                }
                if (isLarge && lcpArr[i] > lcpArr[lcpStart]) {
                    left = i;
                    isLarge = false;

                }
            } else {
                if ((isFirst && lcpArr[i] < minLen) || !isContinue) {
                    left = i + 1;
                } else {
                    if(isLarge && lcpArr[i] < lcpArr[lcpStart]) {
                        left = i;
                    }
                    if (lcpArr[lcpStart] <= maxLen) {
                        int position = lcpStart;
                        int times = (i - lcpStart) + 1 + j;
                        cout << "position:" << position << endl;
                        cout << "times:" << times << endl;
                    }
                }
                break;
            }
        }
    }

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
