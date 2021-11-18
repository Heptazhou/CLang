#define MIN           MIN2
#define MAX           MAX2
#define MIN2(a, b)    (((a) < (b)) ? (a) : (b))
#define MAX2(a, b)    (((a) > (b)) ? (a) : (b))
#define MIN3(a, b, c) (((a) < (b)) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
#define MAX3(a, b, c) (((a) > (b)) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c)))

#define IS_LOWER_CASE(c) (((int) (c) >= 97 && (int) (c) < 123) ? 1 : 0)
#define IS_UPPER_CASE(c) (((int) (c) >= 65 && (int) (c) <= 90) ? 1 : 0)

int main() { }
