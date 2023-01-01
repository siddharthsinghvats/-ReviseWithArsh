class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int> s;
        int n = t.size();
        for(int i =0;i<n;i++){
            if(t[i]=="*"){
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(x*y);
            }
            else if(t[i]=="/"){
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(y/x);
            }
            else if(t[i]=="+"){
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(x+y);
            }
             else if(t[i]=="-"){
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(y-x);
            }
            else{
                s.push(stoi(t[i]));
            }
        }
        return s.top();
    }
};
