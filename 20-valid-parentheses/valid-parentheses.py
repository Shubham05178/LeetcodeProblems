class Solution:
    def isValid(self, s: str) -> bool:
        st=[]
        for i in s:
            if i=="(":
                st.append("(")
            elif i=="[":
                st.append("[")
            elif i =="{":
                st.append("{")
            elif i==")" and len(st) and st[-1]=="(":
                st.pop()
            elif i=="]" and  len(st)  and st[-1]=="[":
                st.pop()
            elif i=="}" and  len(st)  and st[-1]=="{":
                st.pop()
            else:
               
                return False
        return not len(st)