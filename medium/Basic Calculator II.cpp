/**
* Leetcode Problem - https://leetcode.com/problems/basic-calculator-ii/
* Author - Shubham Nagaria
* Date - 25th Dec 2021
**/
//Most Optimal Way
//O(N) time complexity O(1) Space Complexity
class Solution {
public:
    int calculate(string s) {
        int lastNumber=0,currentNumber=0;
        char operation ='+';
        int n =s.size();
        int result=0;
        for(int i =0;i < n;i++){
            char x= s[i];
            if(isdigit(x))
                currentNumber=(currentNumber*10)+(x-'0');
             if( (!isdigit(x) && !iswspace(x) )|| (i==(n-1)) ){
                if(operation=='+'){
                    result+=lastNumber;
                    lastNumber=currentNumber;
                    }
                else if(operation=='-'){
                    result+=lastNumber;
                    lastNumber=-currentNumber;
                }
                else if (operation=='*'){
                    lastNumber*=currentNumber;
                }
                else if (operation =='/'){
                   lastNumber/=currentNumber;
                }
                currentNumber=0;
                operation = x;
            }
        }
       
         return result+lastNumber;   
    }
};

// O(N) time complexity but O(N) space complexity

class Solution {
public:
    int calculate(string s) {
        int lastNumber=0;
        char operation ='+';
        int n =s.size();
        int result=0;
        stack<int>ar;
        for(int i =0;i < n;i++){
            char x= s[i];
            if(isdigit(x))
                lastNumber=(lastNumber*10)+(x-'0');
             if( (!isdigit(x) && !iswspace(x) )|| (i==(n-1)) ){
                if(operation=='+')
                    ar.push(lastNumber);
                else if(operation=='-')
                    ar.push(-lastNumber);
                else if (operation=='*'){
                    int top = ar.top();
                    ar.pop();
                    ar.push(top*lastNumber);
                }
                else if (operation =='/'){
                    int top = ar.top();
                    ar.pop();
                    ar.push(top/lastNumber);
                }
                lastNumber=0;
                operation = x;
            }
        }
        while(!ar.empty()){
            result+=ar.top();
            ar.pop();
        }
         return result;   
    }
};
