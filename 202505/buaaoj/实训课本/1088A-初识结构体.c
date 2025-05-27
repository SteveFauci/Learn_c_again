#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 102   // 最大长度为 100 + '\0'
#define MAX_COUNTRIES 500

struct Country {
    char name[MAX_NAME_LEN];
    int t;                  // 时区
    char capital[MAX_NAME_LEN];
} countries[MAX_COUNTRIES];

// 去除字符串结尾的换行符
void remove_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    getchar();  // 吃掉换行符，避免干扰 fgets

    for (int i = 0; i < n; i++) {
        // 读入国家名
        fgets(countries[i].name, MAX_NAME_LEN, stdin);
        remove_newline(countries[i].name);

        // 读入时区
        scanf("%d", &countries[i].t);
        getchar();  // 吃掉换行符

        // 读入首都名
        fgets(countries[i].capital, MAX_NAME_LEN, stdin);
        remove_newline(countries[i].capital);
    }

    char query[MAX_NAME_LEN];

    for (int i = 0; i < m; i++) {
        // 读取查询的国家名
        fgets(query, MAX_NAME_LEN, stdin);
        remove_newline(query);

        // 查找匹配的国家
        for (int j = 0; j < n; j++) {
            if (strcmp(query, countries[j].name) == 0) {
                printf("%d\n", countries[j].t);
                printf("%s\n", countries[j].capital);
                break;
            }
        }
    }

    return 0;
}