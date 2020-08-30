// TODO: Hierholzer
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, vector<string> > ma;
        vector<string> out;
        int num_tickets = 0;
        for (auto &v : tickets) {
            ma[v[0]].push_back(v[1]);
            ++num_tickets;
        }
        for (auto &kv : ma) {
            sort(kv.second.begin(), kv.second.end());
        }
        map<string, vector<bool> > used;
        for (auto &kv : ma) {
            used[kv.first].resize(kv.second.size(), false);
        }
        vector<string> buf(num_tickets + 1);
        buf[0] = "JFK";
        function<void(string, int)> F;
        bool found = false;
        F = [&](string now, int i) {
            if (found) return;
            if (i >= buf.size()) {
                found = true;
                return;
            }
            auto &u = used[now];
            auto &v = ma[now];
            string oldp = buf[i];
            for (int j = 0; j < u.size(); ++j) {
                if (!u[j]) {
                    u[j] = true;
                    buf[i] = v[j];
                    F(v[j], i + 1);
                    if (found) return;
                    u[j] = false;
                }
            }
            buf[i] = oldp;
        };
        F("JFK", 1);
        return buf;
    }
};
