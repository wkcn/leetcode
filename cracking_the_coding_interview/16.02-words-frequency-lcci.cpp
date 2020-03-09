class WordsFrequency {
public:
    WordsFrequency(vector<string>& book) {
        for (string &s : book) ++ma[s];
    }
    
    int get(string word) {
        if (ma.count(word)) return ma[word];
        return 0;
    }
private:
    unordered_map<string, int> ma;
};
