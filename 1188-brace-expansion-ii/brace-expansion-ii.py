class Solution:
    def braceExpansionII(self, expression: str) -> List[str]:
        op = []  # Operator stack
        stk = []  # Set stack

        # Pop the operator at the top of the stack and perform the calculation
        def ope():
            l, r = len(stk) - 2, len(stk) - 1
            if op[-1] == "+":
                # Union operation
                stk[l] |= stk[r]
            else:
                # Cartesian product operation
                tmp = set()
                for left in stk[l]:
                    for right in stk[r]:
                        tmp.add(left + right)
                stk[l] = tmp
            op.pop()
            stk.pop()

        for i, ch in enumerate(expression):
            if ch == ",":
                # Keep popping operators from the top of the stack until the stack is empty or its top is not a multiplication sign
                while op and op[-1] == "*":
                    ope()
                op.append("+")
            elif ch == "{":
                # First determine whether a multiplication sign needs to be added, then push { onto the operator stack
                if i > 0 and (
                    expression[i - 1] == "}" or expression[i - 1].isalpha()
                ):
                    op.append("*")
                op.append("{")
            elif ch == "}":
                # Keep popping operators from the top of the stack until its top is {
                while op and op[-1] != "{":
                    ope()
                op.pop()
            else:
                # First determine whether a multiplication sign needs to be added, then push the newly constructed set onto the set stack
                if i > 0 and (
                    expression[i - 1] == "}" or expression[i - 1].isalpha()
                ):
                    op.append("*")
                stk.append({ch})
        while op:
            ope()
        return sorted(stk[-1])