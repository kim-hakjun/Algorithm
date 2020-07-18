#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    bool flag = false;
    vector<string> cacheData;

    if (cacheSize == 0) {
        answer = cities.size() * 5;
    }
    else {

        for (auto iter = cities.begin(); iter != cities.end(); iter++) {

            flag = false;
            transform(iter->begin(), iter->end(), iter->begin(), ::tolower);

            for (auto iter2 = cacheData.begin(); iter2 != cacheData.end(); iter2++) {
                if (*iter == *iter2) {
                    answer += 1;
                    cacheData.erase(iter2);
                    cacheData.push_back(*iter);
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                answer += 5;
                if (cacheData.size() == cacheSize) {
                    cacheData.erase(cacheData.begin());
                }
                cacheData.push_back(*iter);
            }

        }
    }

    return answer;
}