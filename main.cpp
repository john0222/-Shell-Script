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
        //根據以上的規則，替我擴展更多
        {"touch", {"整一个空文件", "新建一个文件", "创建文件"}},
        {"chmod", {"改权限", "设置权限", "调整权限"}},
        {"chown", {"改主人", "设置主人", "调整主人"}},
        {"tar", {"打包", "压缩", "归档"}},
        {"gzip", {"压缩", "打包", "压缩文件"}},
        {"unzip", {"解压", "打开", "解压缩"}},
        {"wget", {"下载", "获取", "抓取"}},
        {"curl", {"获取", "下载", "抓取"}},
        {"ssh", {"远程连接", "登录", "连接到"}},
        {"scp", {"远程复制", "传输", "拷贝到"}},
        {"sudo", {"用管理员权限", "以管理员身份", "超级用户"}},
        {"apt-get", {"安装软件", "获取软件", "更新软件"}},
        {"yum", {"安装软件", "获取软件", "更新软件"}},
        {"pip", {"安装Python包", "获取Python包", "更新Python包"}},
        {"npm", {"安装Node.js包", "获取Node.js包", "更新Node.js包"}},
        {"make", {"编译", "构建", "生成"}},
        {"gcc", {"编译C代码", "生成可执行文件", "编译C程序"}},
        {"g++", {"编译C++代码", "生成可执行文件", "编译C++程序"}},
        {"python", {"运行Python脚本", "执行Python代码", "启动Python"}},
        {"node", {"运行Node.js脚本", "执行Node.js代码", "启动Node.js"}},
        {"java", {"运行Java程序", "执行Java代码", "启动Java"}},
        {"docker", {"运行容器", "创建容器", "管理容器"}},
        {"kubectl", {"管理Kubernetes集群", "操作Kubernetes", "控制Kubernetes"}},
        {"git", {"管理代码仓库", "版本控制", "提交代码"}},
        {"vim", {"编辑文件", "修改文件", "打开文件"}},
        {"nano", {"编辑文件", "修改文件", "打开文件"}},
        {"top", {"查看系统资源", "监控系统", "查看进程"}},
        {"ps", {"查看进程", "监控进程", "显示进程"}},
        {"kill", {"杀死进程", "终止进程", "结束进程"}},
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
