#include <stdio.h>
typedef struct { int x, y; } Point;
int mod(int a, int p) { 
    int r = a % p; 
    return (r < 0) ? r + p : r; 
}
Point pointAdd(Point P, Point Q, int a, int p) {
    Point R;
    int m;
    if(P.x == Q.x && P.y == Q.y) { 
        m = mod((3*P.x*P.x + a) * 6, p); 
    } else {
        m = mod((Q.y - P.y) * 6, p); 
    }
    R.x = mod(m*m - P.x - Q.x, p);
    R.y = mod(m*(P.x - R.x) - P.y, p);
    return R;
}
Point scalarMult(Point P, int k, int a, int p) {
    Point R = P;
    for(int i = 1; i < k; i++)
        R = pointAdd(R, P, a, p);
    return R;
}
int main() {
    int a = 2, b = 3, p = 17;
    Point G = {5, 1};
    int d = 7; 
    Point Q = scalarMult(G, d, a, p); 
    printf("Public Key Q = (%d, %d)\n", Q.x, Q.y);
    return 0;
}
