// C++版本实现快排
#include "src/wordSort.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string demoStr1 = "习近平强调面对疫情中阿人民同舟共济相互支持体现了两国人民的深厚情谊当前中国和阿根廷等拉美国家都面临抗疫情稳经济保民生的艰巨任务中方愿继续同阿根廷积极开展抗疫合作并向阿提供力所能及的帮助习近平强调中方坚定支持阿方为维护国家稳定和发展所作出的努力愿深化两国各领域友好交流和务实合作推动中阿全面战略伙伴关系取得更大发展费尔南德斯表示感谢中国政府和人民为应对疫情所付出的巨大努力和在国际抗疫斗争中发挥的领导作用特别感谢中方向阿根廷伸出援手患难见真情值此特殊时刻我们深切感受到阿中友谊之深厚我坚信我们正在开启两国关系的辉煌时期阿中全面战略伙伴关系及多边合作将得到进一步深化习近平习近平";
    string demoStr = "hellohellohellolvlvlvgoogoodgood";
    string demoStr2 = "习近平强调面对疫情中国阿根廷人民同舟共济相互支持体现了两国人民的深厚情谊当前中国和阿根廷习近平强调习近平哈哈";
    WordSort ws;
    vector<string> cutWordList = ws.string2Arr(demoStr2);
    ws.sortArr(cutWordList);
    //vector<int> lcpArr = {1, 1, 3, 2, 1, 0, 0, 2,0};
    //ws.scanLcp(lcpArr, lcpArr.size(), 0, 1, 5);
}
