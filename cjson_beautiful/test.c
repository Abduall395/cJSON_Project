#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

int main() {
    cJSON *root = cJSON_CreateObject();
    cJSON_AddStringToObject(root, "name", "test");
    cJSON_AddNumberToObject(root, "age", 18);

    // 普通输出
    char *normal = cJSON_Print(root);
    printf("普通输出:\n%s\n", normal);

    // 美化输出
    char *pretty = cJSON_Print_Pretty(root, 4);
    printf("\n美化输出:\n%s\n", pretty);

    free(normal);
    free(pretty);
    cJSON_Delete(root);
    return 0;
}
