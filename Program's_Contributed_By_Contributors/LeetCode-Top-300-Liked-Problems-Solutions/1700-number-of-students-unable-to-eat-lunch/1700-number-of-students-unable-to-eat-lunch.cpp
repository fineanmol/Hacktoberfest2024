class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int c = 0, s = 0;

        for(int stud : students){
            if(stud == 0)
                c++;
            else
                s++;
        }

        for(int sandwich : sandwiches){
            if(sandwich == 0 && c == 0)
                return s;
            if(sandwich == 1 && s == 0)
                return c;
            if(sandwich == 0)
                c--;
            else
                s--;
        }

        return 0;
    }
};