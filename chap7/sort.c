/*
 * sort.c
 * p326...
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
} rectangle;

int compare_scores(const void* score_a, const void* score_b)
{
    /*
     * 最初の * は、score_a に格納されている int を取得する。
     * (int*) は、score_a は、voidポインタなので、整数ポインタに
     * キャストする。
     */
    int a = *(int*)score_a;
    int b = *(int*)score_b;
    return a - b;
}

/*
 * 降順にソート
 */
int compare_scores_desc(const void* score_a, const void* score_b)
{
    int a = *(int*)score_a;
    int b = *(int*)score_b;
    return b - a;
}

int compare_areas(const void* a, const void* b)
{
    /*
     * a は、voidポインタなので、rectangleポインタにキャストする。
     * アドレスを指しているので、* で rectangle の値を取り出す
     */
    /* Seiichi's method 
    rectangle rec_a = *(rectangle*)a;
    rectangle rec_b = *(rectangle*)b;
    int area_a = rec_a.width * rec_a.height;
    int area_b = rec_b.width * rec_b.height;
    */
    /* book's method */
    rectangle* rec_a = (rectangle*)a;
    rectangle* rec_b = (rectangle*)b;
    int area_a = rec_a->width * rec_a->height;
    int area_b = rec_b->width * rec_b->height;
    
    return area_a - area_b;
}

int compare_areas_desc(const void* a, const void* b)
{
    rectangle* rec_a = (rectangle*)a;
    rectangle* rec_b = (rectangle*)b;
    int area_a = rec_a->width * rec_a->height;
    int area_b = rec_b->width * rec_b->height;
    
    return area_b - area_a;
}    


int compare_names(const void* a, const void* b)
{
    char **str_a = (char**)a;
    char **str_b = (char**)b;
    return strcmp(*str_a, *str_b);
}

int compare_names_desc(const void* a, const void* b)
{
    char **str_a = (char**)a;
    char **str_b = (char**)b;
    return strcmp(*str_b, *str_a);
}

int main()
{
    int i = 0;

    /* ------------------------------------------------------------ */
    int scores[] = {543, 323, 32, 554, 11, 3, 112};

    int length_scores = sizeof(scores) / sizeof(int);

    /* qsort
     * @param:
     *   void *array,
     *   size_t length,
     *   size_t item_size,
     *   int (*compar)(const void *, const void *));
     */
    qsort(scores, length_scores, sizeof(int), compare_scores_desc);

    for (i=0; i < length_scores; i++) {
        printf("%i - %i\n", i, scores[i]);
    }

    /* ------------------------------------------------------------ */
    rectangle shikaku[] = {{20, 10}, {30, 30}, {100, 20}, {50, 60}};
    int length_shikaku = sizeof(shikaku) / sizeof(rectangle);
    qsort(shikaku, length_shikaku, sizeof(rectangle), compare_areas_desc);
    for (i=0; i < length_shikaku; i++) {
        printf("%i - {%i, %i}\n", i, shikaku[i].width, shikaku[i].height);
    }

    /* ------------------------------------------------------------ */
    char *names[] = {
        "James",
        "Amargam",
        "Thomas",
        "Jacson",
        "Robert",
        "Wize"
    };
    int length_names = sizeof(names) / sizeof(names[0]);
    qsort(names, length_names, sizeof(names[0]), compare_names_desc);
    

    for (i=0; i < length_names; i++) {
        printf("%i %s\n", i, names[i]);
    }

    printf("%i\n", strcmp("James", "Amargam") );
                                              
}

