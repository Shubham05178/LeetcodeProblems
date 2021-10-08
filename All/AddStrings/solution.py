class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        lenNum1 = len(num1)
        lenNum2 = len(num2)
        if lenNum1 < lenNum2:
            num1, num2 = num2, num1
            lenNum1, lenNum2 = lenNum2, lenNum1
        # Num1 is larger
        answer = ''
        remainder = 0
        j = lenNum2 - 1
        for i in range(lenNum1 - 1, -1, -1):
            tempSum = remainder + int(num1[i])
            if j >= 0:
                tempSum += int(num2[j])
                j -= 1
            remainder = 1 if tempSum > 9 else 0
            answer = str(tempSum - (remainder * 10)) + answer
        return (str(remainder) if remainder > 0 else '') + answer
