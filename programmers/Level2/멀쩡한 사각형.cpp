using namespace std;

long long solution(int w, int h) {
    long long answer = 0;

    long long s = 0;
    long long e = 0;

    long long t_w = (long long)w;
    long long t_h = (long long)h;

    for (long long i = 1; i <= t_w; i++) {
        if ((i * t_h) % t_w != 0) e = ((i * t_h) / t_w) + 1;
        else e = (i * t_h) / t_w;

        answer += (e - s);

        s = ((i * t_h) / t_w);
    }

    answer = (t_w * t_h) - answer;

    return answer;
}