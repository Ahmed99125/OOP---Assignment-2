// File: A2_S23_20220013_Problem01.cpp
// Purpose: .........
// Author: Ahmed tamer fathy
// Section: S23
// ID: 20220013
// TA: ........................
// Date: 26 Oct 2023

#include <iostream>
#include <vector>
#include <set>
#include <deque>

using namespace std;

struct dominoT {
    int leftDots;
    int rightDots;
};

bool formDominoChain(vector<dominoT> &dominos);

deque <int> ans;

int main() {
    vector<dominoT> dominos;
    cout << "Enter the number of dominos:" << endl;
    int n;
    cin >> n;
    cout << "Enter 2 space separated intgers for each piece of domino:" << endl;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        dominos.push_back(dominoT{x, y});
    }

    if (formDominoChain(dominos)) {
        for (auto i : ans) {
            cout << dominos[i].leftDots << '|' << dominos[i].rightDots;
            if (i != ans.back())
                cout << " - ";
        }
    }

    return 0;
}

// backtracking
bool formDominoChain(vector<dominoT> &dominos) {
    static set <int> st;
    static int rightDots{0}, leftDots{0};
    static deque <int> tmp_ans;
    if (st.size() == dominos.size()) {
        if (ans.empty()) {
            for (auto i : tmp_ans)
                ans.push_back(i);
        }
        return true;
    }
    int res = 0;
    for (int i = 0; i < dominos.size(); i++) {
        if (st.empty()) {
            tmp_ans.push_back(i);
            st.insert(i);
            rightDots = dominos[i].rightDots;
            leftDots = dominos[i].leftDots;
            res |= formDominoChain(dominos);
            st.erase(i);
            tmp_ans.pop_back();
            rightDots = 0;
            leftDots = 0;
        }
        else if (!st.count(i)) {
            if (rightDots == dominos[i].leftDots) {
                tmp_ans.push_back(i);
                st.insert(i);
                int tmp = rightDots;
                rightDots = dominos[i].rightDots;
                res |= formDominoChain(dominos);
                rightDots = tmp;
                st.erase(i);
                tmp_ans.pop_back();
            }
            else if (leftDots == dominos[i].rightDots) {
                st.insert(i);
                tmp_ans.push_front(i);
                int tmp = leftDots;
                leftDots = dominos[i].leftDots;
                formDominoChain(dominos);
                leftDots = tmp;
                st.erase(i);
                tmp_ans.pop_front();
            }
        }
    }

    return res;
}