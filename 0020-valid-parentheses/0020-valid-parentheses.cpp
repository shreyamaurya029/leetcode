class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]); // inserting the char in the stack
            } else {
                if (st.empty()) { // agar koi opening hai hi nahi closing ke liye to stack enpty hoga and valid nahi hoga string
                    return false;
                }
                char top = st.top();
                st.pop();
                if ((s[i] == ')' && top != '(') || (s[i] == ']' && top != '[') || (s[i] == '}' && top != '{')) {
                    return false; // if the condition is not satisfied
                    // yahan par ek galti ki thi meine ki,i was comparing worng chars 
                    //we have to look if the closing char in the string is present and on the top of the stack is the opening chars
                }
            }
        }
        return st.empty();
    }
};

// like for example ( should be in the stack and ) should be in the string

// also at the end just return simply st.empty() don't overconplicate it 
