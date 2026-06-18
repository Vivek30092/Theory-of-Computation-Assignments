#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

int main() {
    int nSym, nStates;

    cout << "Number of input symbols: ";
    cin >> nSym;

    vector<char> sym(nSym);
    cout << "Enter symbols:\n";
    for (int i = 0; i < nSym; i++)
        cin >> sym[i];

    cout << "Number of NFA states: ";
    cin >> nStates;

    vector<vector<set<int>>> nfa(nStates, vector<set<int>>(nSym));

    cout << "\nEnter transitions:\n";
    for (int i = 0; i < nStates; i++) {
        for (int j = 0; j < nSym; j++) {
            int k;
            cout << "State " << i << " on " << sym[j]
                 << " -> Number of next states: ";
            cin >> k;

            cout << "Enter states: ";
            for (int t = 0; t < k; t++) {
                int x;
                cin >> x;
                nfa[i][j].insert(x);
            }
        }
    }

    int k;
    set<int> start, finals;

    cout << "\nNumber of initial states: ";
    cin >> k;
    cout << "Enter initial states: ";
    while (k--) {
        int x;
        cin >> x;
        start.insert(x);
    }

    cout << "Number of final states: ";
    cin >> k;
    cout << "Enter final states: ";
    while (k--) {
        int x;
        cin >> x;
        finals.insert(x);
    }

    cout << "\n----- NFA Transition Table -----\n";
    cout << "State\t";
    for (char c : sym) cout << c << "\t";
    cout << "\n";

    for (int i = 0; i < nStates; i++) {
        cout << i << "\t";
        for (int j = 0; j < nSym; j++) {
            cout << "{";
            for (int x : nfa[i][j]) cout << x;
            cout << "}\t";
        }
        cout << "\n";
    }

    map<set<int>, int> id;
    vector<set<int>> dfaStates;
    vector<vector<int>> dfaTrans;
    queue<set<int>> q;

    id[start] = 0;
    dfaStates.push_back(start);
    q.push(start);

    while (!q.empty()) {
        set<int> cur = q.front();
        q.pop();

        int curId = id[cur];

        if ((int)dfaTrans.size() <= curId)
            dfaTrans.resize(curId + 1, vector<int>(nSym, -1));

        for (int j = 0; j < nSym; j++) {
            set<int> nxt;

            for (int st : cur)
                nxt.insert(nfa[st][j].begin(), nfa[st][j].end());

            if (!id.count(nxt)) {
                id[nxt] = dfaStates.size();
                dfaStates.push_back(nxt);
                q.push(nxt);
            }

            dfaTrans[curId][j] = id[nxt];
        }
    }

    cout << "\n----- DFA States -----\n";
    for (int i = 0; i < (int)dfaStates.size(); i++) {
        cout << "D" << i << " = {";
        for (int x : dfaStates[i]) cout << x << " ";
        cout << "}\n";
    }

    cout << "\n----- DFA Transition Table -----\n";
    cout << "State\t";
    for (char c : sym) cout << c << "\t";
    cout << "\n";

    for (int i = 0; i < (int)dfaStates.size(); i++) {
        cout << "D" << i << "\t";
        for (int j = 0; j < nSym; j++)
            cout << "D" << dfaTrans[i][j] << "\t";
        cout << "\n";
    }

    cout << "\nDFA Final States:\n";
    for (int i = 0; i < (int)dfaStates.size(); i++) {
        bool isFinal = false;

        for (int x : dfaStates[i]) {
            if (finals.count(x)) {
                isFinal = true;
                break;
            }
        }

        if (isFinal)
            cout << "D" << i << " ";
    }

    cout << endl;
    return 0;
}