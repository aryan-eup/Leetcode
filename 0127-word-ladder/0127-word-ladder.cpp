class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word=q.front().first;
            int lev=q.front().second;
            q.pop();
            if(word==endWord) return lev;
            for(int i=0;i<word.size();i++){
                char org=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,lev+1});
                        st.erase(word);
                    }
                }
                word[i]=org;
            }
        }
        return 0;
    }
};