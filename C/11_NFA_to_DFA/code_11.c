/* Question:
   Design a program to convert NFA to DFA.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_STATES 64
#define MAX_SYMBOLS 10
#define MAX_DFA_STATES 1024

unsigned long long nfa[MAX_STATES][MAX_SYMBOLS];
char sym[MAX_SYMBOLS];
unsigned long long dfaStates[MAX_DFA_STATES];
int dfaTrans[MAX_DFA_STATES][MAX_SYMBOLS];
int dfaStatesCount = 0;

unsigned long long q[MAX_DFA_STATES];
int head = 0;
int tail = 0;

void push(unsigned long long set) {
    q[tail++] = set;
}

unsigned long long pop() {
    return q[head++];
}

int q_empty() {
    return head == tail;
}

int getDfaStateId(unsigned long long set) {
    for (int i = 0; i < dfaStatesCount; i++) {
        if (dfaStates[i] == set) {
            return i;
        }
    }
    return -1;
}

int addDfaState(unsigned long long set) {
    dfaStates[dfaStatesCount] = set;
    return dfaStatesCount++;
}

int main() {
    int nSym, nStates;

    printf("Number of input symbols: ");
    if (scanf("%d", &nSym) != 1) return 0;

    printf("Enter symbols:\n");
    for (int i = 0; i < nSym; i++) {
        scanf(" %c", &sym[i]);
    }

    printf("Number of NFA states: ");
    if (scanf("%d", &nStates) != 1) return 0;

    printf("\nEnter transitions:\n");
    for (int i = 0; i < nStates; i++) {
        for (int j = 0; j < nSym; j++) {
            int k;
            printf("State %d on %c -> Number of next states: ", i, sym[j]);
            if (scanf("%d", &k) != 1) return 0;

            printf("Enter states: ");
            unsigned long long mask = 0;
            for (int t = 0; t < k; t++) {
                int x;
                if (scanf("%d", &x) != 1) return 0;
                mask |= (1ULL << x);
            }
            nfa[i][j] = mask;
        }
    }

    int k;
    unsigned long long start = 0;
    unsigned long long finals = 0;

    printf("\nNumber of initial states: ");
    if (scanf("%d", &k) != 1) return 0;
    printf("Enter initial states: ");
    while (k--) {
        int x;
        if (scanf("%d", &x) != 1) return 0;
        start |= (1ULL << x);
    }

    printf("Number of final states: ");
    if (scanf("%d", &k) != 1) return 0;
    printf("Enter final states: ");
    while (k--) {
        int x;
        if (scanf("%d", &x) != 1) return 0;
        finals |= (1ULL << x);
    }

    printf("\n----- NFA Transition Table -----\n");
    printf("State\t");
    for (int i = 0; i < nSym; i++) {
        printf("%c\t", sym[i]);
    }
    printf("\n");

    for (int i = 0; i < nStates; i++) {
        printf("%d\t", i);
        for (int j = 0; j < nSym; j++) {
            printf("{");
            unsigned long long mask = nfa[i][j];
            for (int x = 0; x < nStates; x++) {
                if ((mask & (1ULL << x)) != 0) {
                    printf("%d", x);
                }
            }
            printf("}\t");
        }
        printf("\n");
    }

    addDfaState(start);
    push(start);

    while (!q_empty()) {
        unsigned long long cur = pop();
        int curId = getDfaStateId(cur);

        for (int j = 0; j < nSym; j++) {
            unsigned long long nxt = 0;
            for (int st = 0; st < nStates; st++) {
                if ((cur & (1ULL << st)) != 0) {
                    nxt |= nfa[st][j];
                }
            }

            int nxtId = getDfaStateId(nxt);
            if (nxtId == -1) {
                nxtId = addDfaState(nxt);
                push(nxt);
            }
            dfaTrans[curId][j] = nxtId;
        }
    }

    printf("\n----- DFA States -----\n");
    for (int i = 0; i < dfaStatesCount; i++) {
        printf("D%d = {", i);
        unsigned long long mask = dfaStates[i];
        for (int x = 0; x < nStates; x++) {
            if ((mask & (1ULL << x)) != 0) {
                printf("%d ", x);
            }
        }
        printf("}\n");
    }

    printf("\n----- DFA Transition Table -----\n");
    printf("State\t");
    for (int i = 0; i < nSym; i++) {
        printf("%c\t", sym[i]);
    }
    printf("\n");

    for (int i = 0; i < dfaStatesCount; i++) {
        printf("D%d\t", i);
        for (int j = 0; j < nSym; j++) {
            printf("D%d\t", dfaTrans[i][j]);
        }
        printf("\n");
    }

    printf("\nDFA Final States:\n");
    for (int i = 0; i < dfaStatesCount; i++) {
        if ((dfaStates[i] & finals) != 0) {
            printf("D%d ", i);
        }
    }
    printf("\n");

    return 0;
}
