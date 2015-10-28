#include <stdio.h>

#define max(a,b) ((a) > (b)) ? (a) : (b)
#define min(a,b) ((a) > (b)) ? (b) : (a)

static int divide(int a, int b) {
  if (a < 0) return 0;
  return b == 0 ? 9999999 : a / b;
}

int main() {
  int r, g, w, x, y, z, p, q;
  while (scanf("%d %d %d %d %d %d %d %d", &r, &g, &w, &x, &y, &z, &p, &q) != EOF) {
    int ans = 0, red;
      for (red = 0; red <= r; red++) {
        int green = min((r - red * (w - 1)) / y,  divide(g - red * x - 1, z - 1));
        if (green < 1) {
          break;
        }
        ans = max(ans, red * p + green * q);
      }
      
      int green;
      for (green = 0; green <= g; green++) {
        int red = min(divide(r - green * y - 1, w - 1),  (g - green * (z - 1)) / x);
          if (red < 1) {
            break;
          }
        ans = max(ans, red * p + green * q);
      }
      printf("%d\n", ans + r * p + g * q);
  }
  return 0;
}