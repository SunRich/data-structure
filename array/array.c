//
// Created by sunrich on 2018/12/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct array {
    int size;
    int used;
    int *arr;
};

void dump(struct array *array) {
    for (int i = 0; i < array->used; ++i) {
        printf("内存地址：%p,[%02d]: %08d\n", array->arr, i, array->arr[i]);
    }
}

void alloc(struct array *array) {
    array->arr = (int *) malloc(array->size * sizeof(int));
}

int insert(struct array *array, int value) {
    // 查看是否越界
    if (array->used >= array->size) {
        return -1;
    }
    // 查找插入位置
    int i;
    for (i = 0; i < array->used; ++i) {
        if (value < array->arr[i]) {
            break;
        }

    }
    // 移出空位
    if (i < array->used) {
        memmove(&array->arr[i + 1], &array->arr[i], (array->used - i) * sizeof(int));
    }
    array->arr[i] = value;
    array->used++;
    return i;
}


int delete(struct array *array, int index) {
    // 检查删除数据是否合法
    if (index < 0 || array->used < index) {
        return -1;
    }
    memmove(&array->arr[index], &array->arr[index + 1], (array->used - index) * sizeof(int));
    array->used--;
    return index;
}

void main() {
    int idx;

    struct array ten_int = {10, 0, NULL};
    alloc(&ten_int);
    insert(&ten_int, 1);
    insert(&ten_int,555555);
    dump(&ten_int);
    printf("内存地址%d:", ten_int.arr[0]);
}