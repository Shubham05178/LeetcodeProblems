/**
* Leetcode Problem - https://leetcode.com/contest/weekly-contest-281/problems/count-integers-with-even-digit-sum/
* Author - Shubham Nagaria
* Date - 25th Feb 2022
**/
/**
Observation -
2->1
4->2
6->3
8->4
11->5
13->6
15->7
17->8
19->9
20->10
22->11
24->12
26->13
28->14
29-> 29/2 =14.5
30->30/2 = 15 
**/
class Solution {
public:
    int countEven(int n) {
        int sum = 0;
        int num =n;
        while(num){
            sum+= num%10;
            num/=10;
        }
        if((sum&1)==0)
            return n/2;
        else
            return (int)ceil((n/2.0))-1;
    }
};
