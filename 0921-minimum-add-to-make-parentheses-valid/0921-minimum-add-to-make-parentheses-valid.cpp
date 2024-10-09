class Solution {
public:
    int minAddToMakeValid(string s) {
       stack<char> st;
       int open = 0,res = 0;

       for(int i = 0;s[i] != '\0';i++){
        if(s[i] == '('){
            st.push('(');
        }else{
            if(!(st.empty()) && s[i] == ')'){
                st.pop();
            }else{
                open++;
            }
        }
       }
       return (open + st.size());
    }
};