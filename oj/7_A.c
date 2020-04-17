#include <stdio.h>
#include <math.h>
struct team{
    int rank;
    int score;
    char positiveornot;
    int win;
    int lose;
    char winornot;
    int jifen;
};
void stress(struct team* a,struct team* b){
    int x;
    int y;
    scanf("%d:%d", &x, &y);
    a->win = a->win + x;
    b->win = b->win + y;
    a->lose = a->lose + y;
    b->lose = b->lose + x;
    a->score = a->win - a->lose;
        if(a->score>=0){
            a->positiveornot = '+';
        }
        else
            a->positiveornot = '-';
    b->score = b->win - b->lose;
        if(b->score>=0){
            b->positiveornot = '+';
        }
        else
            b->positiveornot = '-';
    if(x>y){
        a->jifen = a->jifen + 3;
    }
    if(x==y){
        a->jifen = a->jifen + 1;
        b->jifen = b->jifen + 1;
    }
    if(x<y){
        b->jifen = b->jifen + 3;
    }
}
int main(){
    struct team TEAM[4];
    for (int i = 0; i < 4;i++){
        TEAM[i].win = 0;
        TEAM[i].lose = 0;
        TEAM[i].rank = i;
        TEAM[i].score = 0;
        TEAM[i].jifen = 0;
    }
    stress(&TEAM[0], &TEAM[1]);
    stress(&TEAM[2], &TEAM[3]);
    stress(&TEAM[0], &TEAM[2]);
    stress(&TEAM[3], &TEAM[1]);
    stress(&TEAM[1], &TEAM[2]);
    stress(&TEAM[3], &TEAM[0]);
    int switcher;
    for (int i = 0; i < 4;i++){
        for (int j = 0; j < 4;j++){
            if(TEAM[i].jifen<TEAM[j].jifen && TEAM[i].rank < TEAM[j].rank){
                switcher = TEAM[i].rank;
                TEAM[i].rank = TEAM[j].rank;
                TEAM[j].rank = switcher;
                
            }
            if(TEAM[i].jifen==TEAM[j].jifen){
                if(TEAM[i].score<TEAM[j].score && TEAM[i].rank < TEAM[j].rank){
                switcher = TEAM[i].rank;
                TEAM[i].rank = TEAM[j].rank;
                TEAM[j].rank = switcher;
                }
                 if(TEAM[i].score==TEAM[j].score){
                     if(TEAM[i].win<TEAM[j].win && TEAM[i].rank < TEAM[j].rank){
                switcher = TEAM[i].rank;
                TEAM[i].rank = TEAM[j].rank;
                TEAM[j].rank = switcher;
                }}
                            }
        }
    }
    for (int i = 0; i < 4;i++){
        if(TEAM[i].rank <=1){
            TEAM[i].winornot = 'Y';
        }
        else
            TEAM[i].winornot = 'N';
    }
    for (int i = 0; i < 4;i++){
        printf("%d %d %c%d %d %d %c\n", TEAM[i].rank + 1, TEAM[i].jifen, TEAM[i].positiveornot,abs(TEAM[i].score), TEAM[i].win, TEAM[i].lose, TEAM[i].winornot);

    }
    return 0;
}