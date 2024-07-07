// Min/Max Queue (queue that returns current min/max value)
// time complexity: query O(1), space: O(n)

struct MinQ {
    deque<pair<int, int>> K;
    int size = 0;

    void push(int x) {
        int cnt = 0;
        while (K.size() && K.back().first >= x) { // <=   -  Max Queue
            cnt += K.back().second + 1;
            K.pop_back();
        }
        K.push_back({ x, cnt });
        ++size;
    }

    void pop() {
        if (K.front().second == 0)
            K.pop_front();
        else
            K.front().second--;
        --size;
    }

    int extreme() {
        return K.front().first;
    }
};
