#pragma once
int fact(int n) {
    int x, i, count;
    x = 1;
    count = 1;
    for (i = 0; i < n; i++) {
        x = x * count;
        count++;
    }
    n = x;
    return n;
}
