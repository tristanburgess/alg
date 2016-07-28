#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    vector<string> elems;
    vector< vector<string> > table;
    
    size_t h(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t p = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % p;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {
      table.resize(bucket_count);
    }

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }
    
    void processQueryBetter(const Query& query) {
        if (query.type == "check") {
            // use reverse order, because we append strings to the end
            for (auto it = table.at(query.ind).rbegin(); it != table.at(query.ind).rend(); ++it) {
              std::cout << *it << " ";
            }
            std::cout << "\n";
        } else if (query.type == "find") {
            auto it = std::find(table.at(h(query.s)).begin(), table.at(h(query.s)).end(), query.s);
            writeSearchResult(it != table.at(h(query.s)).end());
        } else if (query.type == "add") {
            auto it = std::find(table.at(h(query.s)).begin(), table.at(h(query.s)).end(), query.s);
            if (it == table.at(h(query.s)).end()) {
              table.at(h(query.s)).push_back(query.s);
            }
        } else if (query.type == "del") {
            auto it = std::find(table.at(h(query.s)).begin(), table.at(h(query.s)).end(), query.s);
            if (it != table.at(h(query.s)).end()) {
              table.at(h(query.s)).erase(it);
            }
        }
    }
    
    void processQuery(const Query& query) {
        if (query.type == "check") {
            // use reverse order, because we append strings to the end
            for (int i = static_cast<int>(elems.size()) - 1; i >= 0; --i)
                if (h(elems[i]) == query.ind)
                    std::cout << elems[i] << " ";
            std::cout << "\n";
        } else {
            vector<string>::iterator it = std::find(elems.begin(), elems.end(), query.s);
            if (query.type == "find")
                writeSearchResult(it != elems.end());
            else if (query.type == "add") {
                if (it == elems.end())
                    elems.push_back(query.s);
            } else if (query.type == "del") {
                if (it != elems.end())
                    elems.erase(it);
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQueryBetter(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
