    // ********************* Method 1 ******************************
class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.size();
        int n = goal.size();

        if(m != n){
            return false;
        }

        for(int count = 1; count <= m; count++){
            rotate(s.begin(), s.begin()+1, s.end());

            if(s == goal){
                return true;
            }
        }

        return false;

        
    }
};

// ************************* Method 2 ******************************

class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.size();
        int n = goal.size();

        if (m != n) {
            return false;
        }

        if ((s+s).find(goal) != string::npos) {
            return true;
        }

        return false;
    }
};