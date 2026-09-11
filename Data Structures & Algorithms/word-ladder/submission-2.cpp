class Solution {
public:
    bool canTransform (string fromStr, string toStr) {
        if (fromStr == toStr)
            return false;

        int diff = 0;

        for (int i = 0; i < fromStr.size(); i++) {
            if (fromStr[i] != toStr[i])
                diff++;

            if (diff > 1)
                return false;
        } 

        return true;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> graph;

        for (auto &word : wordList) {
            if (canTransform(beginWord, word)) {
                graph[beginWord].push_back(word);
                graph[word].push_back(beginWord);
            }
        }

        int n = wordList.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (canTransform(wordList[i], wordList[j])) {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        queue<string> q;

        unordered_map<string, int> visitedMpp;

        q.push(beginWord);
        visitedMpp[beginWord]++;

        int dist = 1;

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                string currWord = q.front(); 
                q.pop();

                // cout<<"CurrWord: "<<currWord<<" Dist: "<<dist<<endl;

                if (currWord == endWord)
                    return dist;

                for (auto &nextWord : graph[currWord]) {
                    if (visitedMpp.count(nextWord))
                        continue;

                    q.push(nextWord);
                    visitedMpp[nextWord]++;
                }
            }

            dist++;
        }

        return 0;
    }
};
