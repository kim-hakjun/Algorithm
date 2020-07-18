#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

string info[12] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
unordered_map<string, char> map;

// ��� �ð� 
int timeDiff(string A, string B) {
    int ret = stoi(B.substr(0, 2)) * 60 + stoi(B.substr(3, 2)) - (stoi(A.substr(0, 2)) * 60 + stoi(A.substr(3, 2)));
    return ret;
}

// �Ǻ� ��ȯ
string convertFunc(string m) {
    string temp;
    for (int i = 0; i < m.length(); i++) {
        if (m[i] == '#') continue;

        if (i != m.length() - 1 && m[i + 1] == '#') {
            temp += map[m.substr(i, 2)];
        }
        else {
            temp += map[m.substr(i, 1)];
        }
    }
    return temp;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int maxLen = -1;

    // # ó�� ���� �׳� map Ȱ��...
    for (int i = 0; i < 12; i++) {
        map[info[i]] = 'a' + i;
    }
    m = convertFunc(m);

    for (int i = 0; i < musicinfos.size(); i++) {
        // ���ڿ� split
        string contents[4], stringBuffer;
        istringstream ss(musicinfos[i]);
        int type = 0;
        while (getline(ss, stringBuffer, ',')) {
            contents[type] = stringBuffer;
            type++;
        }
        contents[3] = convertFunc(contents[3]);

        // ��� �ð� ���
        int playTime = timeDiff(contents[0], contents[1]);

        // ����ð� ������ �Ǻ�
        string music = contents[3];
        if (playTime > contents[3].length()) {
            int temp = playTime - contents[3].length();
            while (temp != 0) {
                if (temp >= contents[3].length()) {
                    music += contents[3];
                    temp -= contents[3].length();
                }
                else {
                    music += contents[3].substr(0, temp);
                    temp = 0;
                }
            }
        }
        else music = contents[3].substr(0, playTime);

        // �Ǻ��� �Ϻζ��
        if (music.find(m) != -1) {
            if (maxLen < playTime) {
                answer = contents[2];
                maxLen = playTime;
            }
        }
    }

    return answer;
}