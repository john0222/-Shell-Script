#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <sstream>

using namespace std;

// 定義一個結構來規定轉換規則
struct ConversionRule {
    string shellCommand;
    vector<string> dongbeiEquivalents;
};

// 將shell 東北化的
string convertToDongbei(const string& shellCommand, const vector<ConversionRule>& rules) {
    // 查找一個匹配的規則
    for (const auto& rule : rules) {
        if (rule.shellCommand == shellCommand) {
            // 隨機選擇一個東北話表達
            int randomIndex = rand() % rule.dongbeiEquivalents.size();
            return rule.dongbeiEquivalents[randomIndex];
        }
    }

    // 如果沒有找到規則，就原樣返回
    return shellCommand;
}

void testConvertToDongbei() {
    // 定義轉換規則
    vector<ConversionRule> conversionRules = {
        {"cd", {"窜到", "整到", "滚到"}},
        {"ls", {"瞅瞅", "瞧瞧", "看看有啥玩意"}},
        {"mkdir", {"整一个", "鼓捣一个", "创一个"}},
        {"rm", {"干掉", "整没", "删了"}},
        {"mv", {"挪到", "搬到", "给爷滚到"}},
        {"cp", {"复制一个", "整一个一样的", "克隆一个"}},
        {"cat", {"瞅一眼", "读一下", "看看里面是啥"}},
        {"echo", {"喊一嗓子", "说一句", "输出一下"}},
        {"grep", {"找找", "搜搜", "看看有没有"}},
        {"find", {"翻翻", "找出来", "定位到"}},
        // ... 添加更多
    };

    // 測資
    assert(convertToDongbei("cd", conversionRules) == "窜到" || 
           convertToDongbei("cd", conversionRules) == "整到" ||
           convertToDongbei("cd", conversionRules) == "滚到");
    
    assert(convertToDongbei("ls", conversionRules) == "瞅瞅" || 
           convertToDongbei("ls", conversionRules) == "瞧瞧" ||
           convertToDongbei("ls", conversionRules) == "看看有啥玩意");

    assert(convertToDongbei("mkdir", conversionRules) == "整一个" || 
           convertToDongbei("mkdir", conversionRules) == "鼓捣一个" ||
           convertToDongbei("mkdir", conversionRules) == "创一个");

    // ... 添加更多测试用例

    // 測試不匹配配的狀況
    assert(convertToDongbei("unknown", conversionRules) == "unknown");

    cout << "testConvertToDongbei passed!" << endl;
}

int main() {
    // 初始化隨機生成
    srand(time(nullptr));

    testConvertToDongbei();

    return 0;
}
