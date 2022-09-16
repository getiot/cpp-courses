#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

#define JSON_FILE "../files/reflected_ray_dst.json"

struct point_xyz {
    float x;
    float y;
    float z;
};

int main(void)
{
    //char jsonData[1024 * 1024 * 2] = {0};
    
    FILE *fp = fopen(JSON_FILE, "rb");
    if (fp == NULL) {
        printf("Can not open %s\n", JSON_FILE);
    }

    printf("Open %s\n", JSON_FILE);

    fseek(fp, 0, SEEK_SET);
    long begin = ftell(fp);
    fseek(fp, 0, SEEK_END);
    long end = ftell(fp);
    long filesize = end - begin;
    fseek(fp, 0, SEEK_SET);
    unsigned char* jsonData = (unsigned char*)malloc(filesize);
    
    while (fread(jsonData, filesize, 1, fp) == 1) {
        //printf("Read JSON\n");
        //printf("%s\n", jsonData);
        // cJSON *json = cJSON_Parse(jsonData);
        // printf("%s\n\n", cJSON_Print(json));
        // cJSON_Delete(json);
    }

    printf("\n\n");

    cJSON *root = cJSON_Parse(jsonData);
    printf("%s\n\n", cJSON_Print(root));

    cJSON *module0 = cJSON_GetObjectItemCaseSensitive(root, "module_0");
    cJSON *module1 = cJSON_GetObjectItemCaseSensitive(root, "module_1");
    cJSON *module2 = cJSON_GetObjectItemCaseSensitive(root, "module_2");
    cJSON *module3 = cJSON_GetObjectItemCaseSensitive(root, "module_3");

    if (cJSON_IsArray(module0)) {
        long arraySize = cJSON_GetArraySize(module0);
        printf("Array Size = %ld\n", arraySize);

        struct point_xyz points[8][arraySize];

        struct cJSON *element = module0->child;

        for (int i=0; i<arraySize; i++) {
            //printf("%s\n", cJSON_Print(element));

            points[0][i].x = cJSON_GetArrayItem(element, 0)->valuedouble;
            points[0][i].y = cJSON_GetArrayItem(element, 1)->valuedouble;
            points[0][i].z = cJSON_GetArrayItem(element, 2)->valuedouble;

            element = element->next;
            if (element == NULL) break;
        }

        for (int j=0; j<arraySize; j++) {
            printf("[%d] %f %f %f\n", j, points[0][j].x, points[0][j].y, points[0][j].z);
        }

#if 0
        cJSON_ArrayForEach(element, module0) {
            printf("%s\n", cJSON_Print(element));
        }
#endif
    }

    

    cJSON_Delete(root);
    
    free(jsonData);
    fclose(fp);

    printf("Close %s\n", JSON_FILE);
    return 0;
}