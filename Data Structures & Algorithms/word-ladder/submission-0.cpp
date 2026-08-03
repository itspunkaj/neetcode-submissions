class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        int len = beginWord.size();

        queue<string> q;

        q.push(beginWord);
        int steps = 0;

        while (!q.empty()) {
            steps++;

            int sz = q.size();

            while (sz--) {
                string currWord = q.front();

                if (currWord == endWord) return steps;

                q.pop();

                for (int i = 0; i < len; i++) {
                    char o = currWord[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c != o) {
                            currWord[i] = c;
                            if (st.find(currWord) != st.end()) {
                                st.erase(currWord);
                                q.push(currWord);
                            }
                        }
                    }

                    currWord[i] = o;
                }
            }
        }

        return 0;
    }
};
