#include <string>
#include <vector>
#include <map>
#define ll long long

/*
    + 백준 10775 공항
*/

using namespace std;

map<ll, ll> m;

ll Find(ll x) {
    if (m[x] == 0) return x;
    else return m[x] = Find(m[x]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    for (int i = 0; i < room_number.size(); i++) {
        ll cur = room_number[i];

        if (m[cur] == 0) {
            answer.push_back(cur);
            m[cur] = Find(cur + 1);
        }
        else {
            ll res = Find(cur);
            answer.push_back(res);
            m[res] = Find(res + 1);
        }
    }

    return answer;
}