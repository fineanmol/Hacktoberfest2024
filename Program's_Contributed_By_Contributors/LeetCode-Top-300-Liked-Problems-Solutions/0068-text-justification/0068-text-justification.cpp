class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while(i < n){
            int lineLength = words[i].size();
            int j = i + 1; // Selecting next word

            while(j < n && lineLength + words[j].size() + (j - i) <= maxWidth ) { // (j - i) => no of spaces between words
            lineLength += words[j].size();
            j++; // Move to next word
            }

            int numWords = j - i;
            int numSpaces = maxWidth - lineLength;

            string line;

            if(numWords == 1 || j == n){ // Edge cases : Only one word possible or Last line
                line = words[i];
                for(int k = i + 1; k < j; k++){
                    line += ' ' + words[k];
                }
                line += string(maxWidth - line.size(), ' '); // Spaces at the end of string
            }
            else{
                int spaceBetweenWords = numSpaces / (numWords - 1); // numWords - 1 => Words other than start word
                int extraSpaces = numSpaces % (numWords - 1);

                line = words[i];
                for(int k = i + 1; k < j; k++){
                    line += string(spaceBetweenWords,' ');
                    if(extraSpaces > 0){
                        line += ' ';
                        extraSpaces--;
                    }
                    line += words[k];
                }
            }
            ans.push_back(line);
            i = j;
        }
    return ans;  
    }
};