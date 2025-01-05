#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define TOP 0
#define BOT 1
typedef struct record {
    int cur, len;
    bool first;
}record;
 
int read_int()
{
    int x = 0;
    char ch = getchar();
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch - '0'); // x * 10
        ch = getchar();
    }
    return x;
}
int case_b_zero()
{
    assert(false);
    return 0;
}
void read_new(record *rec, int position, int *longest, int *longest_len)
{
    int new = read_int();
    if (rec[position].first) {
        rec[position].cur = new;
        rec[position].len = 1;
        rec[position].first = false;
        return;
    }
    if (rec[position].cur == new) {
        rec[position].len++;
        if (rec[position].len > *longest_len) {
            *longest = rec[position].cur;
            *longest_len = rec[position].len;
        }
    }
    else {
        rec[position].cur = new;
        rec[position].len = 1;
    }
}
int main()
{
    int n, a, b;
    n = read_int();
    a = read_int();
    b = read_int(); // b might be zero
    // assert(b > 0);
    if (b == 0) {
        int res = case_b_zero();
        printf("%d\n", res);
        return 0;
    }
 
    int cycle = (a - b) >> 1;
    bool left = (a - b) & 1;
 
    int longest, longest_len;
    record rec[2];
    rec[BOT].first = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b; j++) {
            read_new(rec, BOT, &longest, &longest_len);
        }
        // b != 0
        rec[TOP].first = true;
        for (int j = 0; j < cycle; j++) {
            read_new(rec, BOT, &longest, &longest_len);
            read_new(rec, TOP, &longest, &longest_len);
            read_new(rec, TOP, &longest, &longest_len);
            read_new(rec, BOT, &longest, &longest_len);
        }
        if (left)
            read_new(rec, BOT, &longest, &longest_len);
    }
    printf("%d\n", longest_len);
    return 0;
}