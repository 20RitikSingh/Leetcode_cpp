class Solution {
public:
    bool parseBoolExpr(string exp) {
        if(exp=="t") return 1;
        if(exp=="f") return 0;
        bool f=0;
        if(exp[0]=='&') f=1;
        string t;
        int i=2,c=0;
        while(i<exp.size()-1){
            t.push_back(exp[i]);
            if(exp[i]=='(') c++;
            else if(exp[i]==')') c--;
            if(!c && exp[i]==','){
                t.pop_back();
                switch(exp[0]){
                case '&':
                    f&=parseBoolExpr(t);
                    break;
                case '|':
                    f|=parseBoolExpr(t);
                    break;
                default:
                    return !parseBoolExpr(t);
                }
                t="";
            } 
            i++;
        }
        if(t.size())switch(exp[0]){
        case '&':
            f&=parseBoolExpr(t);
            break;
        case '|':
            f|=parseBoolExpr(t);
            break;
        default:
            return !parseBoolExpr(t);
        }
        return f;
    }
};