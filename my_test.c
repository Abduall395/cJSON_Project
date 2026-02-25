#include "cJSON.h"
int main(){
  cJSON *json = cJSON_CreateString("Hello cJSON!");
  printf("%s\n", cJSON_Print(json));
  cJSON_Delete(json);
  return 0;
}

