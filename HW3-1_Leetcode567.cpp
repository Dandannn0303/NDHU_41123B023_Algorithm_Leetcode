#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length()>s2.length())
        return false;
        vector<int> count1(26,0),count2(26,0);//26個陣列 初始值為0
        for(char c : s1)
        {
            count1[c-'a'] = count1[ c - 'a']+1;//為什麼要「記錄字母出現次數」？
            //因為老闆（程式）很懶，他不想每次都盯著看是什麼字母。他手上有一張清單：
            //訂單清單 (count1)：a: 1, b: 1（其他都是 0）。
            //目前框框清單 (count2)：
            //當框框滑到 ba 時，count2 也會記錄成：a: 1, b: 1。
            //老闆只要比對這兩張清單上的數字是不是都一樣，就知道有沒有找對了！
        }
        //初始化第一個窗口
        for(int i=0;i<s1.size();i++)
        {
            count2[s2[i]-'a']++;
        }
        //初始完要先比一次
        if (count1 == count2)
        return true;
        //開始滑動
        for(int i=s1.size();i<s2.size();i++)
        {
            count2[s2[i]-'a']++;
            count2[s2[i-s1.size()]-'a']--;
            if (count2==count1)
            return true;
        }
    return false;
    }
    
};