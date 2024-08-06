class Solution {
public:
    stack<char> opr;
    stack<int> op;

    int precedence(char ch) {
        if (ch == '+' || ch == '-') {
            return 1;
        } else if (ch == '*' || ch == '/') {
            return 2;
        } else {
            return 0;
        }
    }

    int doProcess() {
        int a = op.top();
        op.pop();
        int b = op.top();
        op.pop();
        char ch = opr.top();
        opr.pop();
        if (ch == '+')
            return b + a;
        else if (ch == '-')
            return b - a;
        else if (ch == '*')
            return b * a;
        else
            return b / a;
    }

    int calculate(string s) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') 
                continue;
            else if (isdigit(s[i])) {
                int num = 0;
                while (i < s.length() && isdigit(s[i])) { 
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                --i;
                op.push(num);
            } else {
                char ch = s[i];
                while (!opr.empty() && precedence(opr.top()) >= precedence(ch)) {
                    op.push(doProcess());
                }
                opr.push(ch);
            }
        }
        while (!opr.empty()) {
            op.push(doProcess());
        }
        return op.top();
    }
};     
