class Solution:
    def calculate(self, s: str) -> int:
        result = 0
        number = 0
        sign = 1
        stack = []
        for char in s:
            if char.isdigit():
                number = (10 * number) + int(char)
            elif char in ["-", "+"]:
                result += sign * number
                number = 0
                sign = -1 if char == '-' else 1
            elif char == "(":
                stack.append(result)
                stack.append(sign)
                sign = 1
                result = 0
            elif char == ")":
                result += (sign * number)
                result *= stack.pop()
                result += stack.pop()
                number = 0
        return result + (number * sign)
