#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

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

int main() {
    // 初始化隨機生成
    srand(time(nullptr));

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
        // ... 添加更多规则
    };

    // 輸入輸出和文件名
    string inputFilename;
    string outputFilename;

    cout << "請輸入轉換的shell文件名：";
    cin >> inputFilename;

    cout << "請輸入輸出文件指定名稱：";
    cin >> outputFilename;

    // 打開和輸入文件
    ifstream inputFile(inputFilename);
    ofstream outputFile(outputFilename);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "file opening fail！" << endl;
        return 1;
    }

    // 讀取並轉換成shell腳本
    string line;
    while (getline(inputFile, line)) {
        // 简單按照特性將其參數化
        // 根據需要進行複雜解析
        istringstream iss(line);
        string command;
        iss >> command;

        // 轉換命令
        string dongbeiCommand = convertToDongbei(command, conversionRules);

        // 輸出轉化後的東北話
        outputFile << dongbeiCommand;

        // 處理參數
        string argument;
        while (iss >> argument) {
            outputFile << " " << argument;
        }

        outputFile << endl;
    }

    // 關閉文件
    inputFile.close();
    outputFile.close();

    cout << "轉換完成！" << endl;

    return 0;
}
