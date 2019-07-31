#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() == 0)
            return result;
        
        vector<string> letter_map = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
        vector<int> letter_map_size = { 0,0,3,3,3,3,3,4,3,4 };
        vector<int> nums_input;//输入的数字
        vector<int> combination_unit;
        vector<int> combination_unit_max;;
        //int count = 1;
        for (int i = 0; i < digits.size(); i++)
        {
            int number = atoi(digits.substr(i, 1).c_str());
            nums_input.push_back(number);
            //count = count * letter_map_size[number];
            combination_unit.push_back(0);
            combination_unit_max.push_back(letter_map_size[number]);
        }       
       while(1)
        {
            string str="";
            for (int k = 0; k < digits.size(); k++)
            {
                str = str + letter_map[nums_input[k]].substr( combination_unit[k],1);              
            }            
            result.push_back(str);            
            int ret=spectialAdd(combination_unit, combination_unit_max, 0);
            if (ret < 0)
                break;

        }
        return result;
    }
    int spectialAdd(vector<int>&combination_unit,vector<int> &combination_unit_size,int index)
    {
        if (index > combination_unit.size() - 1)
            return -1;
        combination_unit[index]++;
        if (combination_unit[index] >= combination_unit_size[index])
        {
            combination_unit[index] = 0;
           int ret=spectialAdd(combination_unit, combination_unit_size, index + 1);
           if (ret < 0)
               return ret;
        }
        return 1;
    }
    void test()
    {
        string str = "9";
        vector<string > result;

        result= letterCombinations(str);
        for (int i = 0; i < result.size();i++)
        {
            printf("%s \n", result[i].c_str());
        }
        printf("\n");
        str = "239";
        result = letterCombinations(str);
        for (int i = 0; i < result.size(); i++)
        {
            printf("%s \n", result[i].c_str());
        }
    }
};
int main()
{
    std::cout << "start to test!\n";
    Solution s1;
    s1.test();

}
