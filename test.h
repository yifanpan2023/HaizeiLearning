/*************************************************************************
	> File Name: test.h
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 三  8/26 15:30:44 2020
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#define COLOR(msg, code) "\033[1;" #code "m" msg "\033[0m"
#define RED(msg) COLOR(msg, 31)
#define GREEN(msg) COLOR(msg, 32)
#define YELLOW(msg) COLOR(msg, 33)
#define BLUE(msg) COLOR(msg, 34)

#define TEST(func, arr, n) test_func(#func, __FILE__, __LINE__, func, arr, n)

int *getRandData(int n) {
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) arr[i] = rand() % n;
    return arr;
}

bool check(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
     return true;
}

void test_func(
    const char *func_name,
    const char *file_name,
    int line_no,
    void (*func)(int *, int, int), 
    int *arr,
    int n 
) {
    int *temp = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) temp[i] = arr[i];
    long long b = clock();
    func(temp, 0, n - 1);
    long long e = clock();
    if (check(temp, n)) {
        printf(GREEN("[    OK    ]") " %s", func_name);
    } else {
        printf(RED("[  FAILED  ]") " %s", func_name);
    }
    printf(YELLOW(" (%lld ms)\n"), 1000 * (e - b) / CLOCKS_PER_SEC);
    free(temp);
    return ;
}

#endif
