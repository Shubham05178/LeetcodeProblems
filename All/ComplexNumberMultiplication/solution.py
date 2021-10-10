class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        '''
            Let's say,
            num1 = a + bi
            num2 = c + di
            Therefore,
            num1 * num2 = ac + (ad + bc)i + bd(i^2)
                        = ac + (ad + bc)i - bd
                        = (ac - bd) + (ad + bc)i
        '''
        plusNum1Index = num1.index("+")
        a = int(num1[:plusNum1Index])
        b = int(num1[plusNum1Index + 1:num1.index("i")])
        plusNum2Index = num2.index("+")
        c = int(num2[:plusNum2Index])
        d = int(num2[plusNum2Index + 1:num2.index("i")])
        return str(a * c - b * d) + "+" + str(a * d + b * c) + "i"
