//实现标题数据抽词排序

#include "wordSort.h"
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iterator>
#include <map>
#include <string>
#include <vector>

//获取PAT数组和LCP数组
map<string, int> WordSort::sortArr(vector<string> wordList) {
    vector<string> originWordList = wordList;
    vector<int> patArr(wordList.size(), 0);
    int i = 0;
    for(auto& word : patArr) {
        word = i;
        i++;
    }
    for(auto word : wordList) {
        cout << word  << endl;;
    }
    quickSort(wordList, 0, wordList.size() - 1, patArr);
    for(auto word : patArr) {
        cout << word << ",";
    }
    cout << endl;
    for(auto word : wordList) {
        cout << word  << endl;;
    }
    cout << wordList.size() << endl;
    vector<int> lcpArr = pat2LcpArr(patArr, originWordList);
    for(auto word : lcpArr) {
        cout << word << ",";
    }
    cout << endl;
    map<string, int> cutWordList;
    vector<vector<int>> wordRate = scanLcp(lcpArr, lcpArr.size(), 0, 6, 15);
    for(auto wordPosition : wordRate) {
        //获取需要截图的query
        string temp = wordList[wordPosition[0]];
        string cutWord = temp.substr(0, lcpArr[wordPosition[0]]);
        cutWordList[cutWord] = wordPosition[1];
    }

    map<string, int>::iterator iter;
    iter = cutWordList.begin();
    for(iter = cutWordList.begin(); iter != cutWordList.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << cutWordList["中国"] << endl;
    cout << cutWordList["习近平"] << endl;
    cout << cutWordList["近平"] << endl;
    return cutWordList;
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


//通过lcp数组获取词频
vector<vector<int>> WordSort::scanLcp(vector<int> lcpArr, int count, int start, int minLen, int maxLen) {
    vector<vector<int>> wordRate;
    for(auto num : lcpArr) {
        cout << num;
    }
    cout << endl;
    int left = start;
    while (left <= count - 1) {
        int lcpStart = left;
        bool isFirst = true;//表示起点
        bool isLarge = true;//判断是否找到比起点值大的数据
        bool isContinue = true;//用来标识之前是都已经计算过

        int j = 0;
        int i = left;

        for (; i < count; i++) {
            //超过成词的最大长度
            if (isFirst && lcpArr[i] > maxLen) {
                left += 1;
                break;
            }
            if (isFirst) {
                if (i - 1 >= 0) {
                    if (lcpArr[i - 1] >= lcpArr[i]) {
                        for (int k = i - 1; k >= 0; k--) {
                            //之前的数据比当前更大
                            if (lcpArr[k] >= minLen && lcpArr[k] > lcpArr[i]) {
                                j += 1;
                            } else {
                                //如果出现相等 直接略过 说明之前已经计算过
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
            if (lcpArr[i] >= minLen && lcpArr[i] >= lcpArr[lcpStart] && isContinue) {
                if (isFirst) {
                    lcpStart = i;
                    isFirst = false;
                }
                //获取第一个比start大数所在的位置，设置为left 即下一轮起点。
                if (isLarge && lcpArr[i] > lcpArr[lcpStart]) {
                    left = i;
                    isLarge = false;

                }
            } else {
                //匹配到最后
                if ((isFirst && lcpArr[i] < minLen) || !isContinue) {
                    left = i + 1;
                } else {
                    //之后的数比当前的数字都要小，即 left=left+1
                    if(isLarge && lcpArr[i] < lcpArr[lcpStart]) {
                        left = i;
                    }
                    if (lcpArr[lcpStart] <= maxLen) {
                        int position = lcpStart;
                        int times = (i - lcpStart) + 1 + j;
                        cout << "position:" << position << endl;
                        cout << "times:" << times << endl;
                        vector<int> wordPosition = {position, times};
                        wordRate.push_back(wordPosition);
                    }
                }
                break;
            }
        }
    }
    return wordRate;
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
            right -= 1;
        }
        while (wordList[left] + target <= target + wordList[left] && left < right) {
            left += 1;
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
    for(int i = 0; i < length; i += 3) {
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
//单词切分后子串合并
vector<string> strigListMerge(vector<string> wordCutList) {
    vector<string> res;
    return  res;
}
//基数排序
vector<vector<int>> WordSort::radixSort(vector<string>content) {
    vector<vector<int>> res;
    int maxNum = 0;
    for(auto item : content) {
        vector<int> itemNumList = string2NumList(item);
        res.push_back(itemNumList);
        if (itemNumList.size() > maxNum) {
            maxNum = itemNumList.size();
        }
    }
    printVec(res);
    cout << "maxNum:" << maxNum << endl;
    radixCode(res, maxNum);
    return res;
}
vector<int> WordSort::string2NumList(string content) {
    vector<int> numList;
    int length = content.size();
    int i = 0;
    while (i < length) {
        string str = content.substr(i, 3);
        i += 3;
        numList.push_back(encode(str));
    }
    return numList;
}
int WordSort::encode (string str) {
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        unsigned int m = (unsigned int)(unsigned char)str[i];
        sum = sum * 16 * 16 + m;
    }
    return sum;
}
void radixCode(vector<vector<int>>& numList, int wordLength) {

    int length = wordLength;
    for(int n = 0; n < length; n++) {
        int buckets[numList.size()];
        map<int, vector<int>> bucketsMap;
        memset(buckets, 0, sizeof(buckets));
        for(int m = 0; m < numList.size(); m++) {
            if (numList[m].size() > n) {
                int tempNum = numList[m][n];
                buckets[m] = tempNum;
                bucketsMap[tempNum] = numList[m];
            }
        }
        sort(buckets, buckets + numList.size());
        for(auto i : buckets) {
            cout << i << endl;
        }

        int k = 0;
        for(auto n : buckets) {
            numList[k++] = bucketsMap[n];
        }

    }
    printVec(numList);
}

void printVec(vector<vector<int>> numList) {
    for(auto l : numList) {
        for (auto n : l) {
            cout << n << " ";
        }
        cout << endl;
    }

}


void radix(vector<int>& numList) {
    int max = 100;

    for(int i = 1; max / i > 0; i = i * 10) {
        int buckets[numList.size()][10];
        memset(buckets, 0, sizeof(buckets));
        for(int m = 0; m < numList.size(); m++) {
            int num = (numList[m] / i) % 10;
            buckets[m][num] = numList[m];
        }
        int k = 0;
        for(int n = 0; n < 10; n++) {
            for(int r = 0; r < numList.size(); r++) {
                if (buckets[r][n] != 0) {
                    numList[k++] = buckets[r][n];
                }

            }
        }

    }

}
