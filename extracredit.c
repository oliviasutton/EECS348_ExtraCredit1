#include <stdio.h>
#include <stdbool.h>

int d[5][5] = {
    {1,5,3,2,4},
    {1,3,4,2,5},
    {3,4,2,5,1},
    {3,1,2,4,5},
    {4,3,1,2,5}
};

int p[5][5] = {
    {3,1,2,5,4},
    {4,3,1,5,2},
    {2,5,4,1,3},
    {4,5,2,1,3},
    {3,2,1,5,4}
};

int dept[5] = {-1, -1, -1, -1, -1}; 
bool prgrm_free[5] = {true, true, true, true, true}; 

void main() {
    while (true) {
        bool match_all = true;
        for (int i = 0; i < 5; i++) {
            if (dept[i] == -1) { 
                match_all = false;
                for (int j = 0; j < 5; j++) {
                    int programmer = d[i][j] - 1;
                    if (prgrm_free[programmer]) { 
                        dept[i] = programmer;
                        prgrm_free[programmer] = false;
                        break;
                    } else {
                        int cur_match = dept[programmer];
                        int rank = 0, new_rank = 0;
                        for (int k = 0; k < 5; k++) {
                            if (p[programmer][k] == i + 1) {
                                new_rank = k;
                            }
                            if (p[programmer][k] == cur_match + 1) {
                                rank = k;
                            }
                        }
                        if (new_rank < rank) {
                            dept[i] = programmer;
                            prgrm_free[programmer] = false;
                            dept[cur_match] = -1;
                            break;
                        }
                    }
                }
            }
        }
        if (match_all) {
            break;
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("Department %d will get Programmer %d\n", i+1, dept[i]+1);
    }
}