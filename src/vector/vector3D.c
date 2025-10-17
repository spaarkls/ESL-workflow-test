#include "vector3D.h"
#include <stdlib.h>
#include <stdio.h>

static void vector3D_mult_number(vector3D_t *res, vector3D_t *vec1, double num) {
    if (!vec1 || !res) { return; }
    res->x = vec1->x * num;
    res->y = vec1->y * num;
    res->z = vec1->z * num;
}

static double determinant(double a1, double a2, double b1, double b2) {
    return a1 * b2 - b1 * a2;
}

vector3D_t *vector3D_init(void) {
    vector3D_t *res = (vector3D_t *)malloc(sizeof(vector3D_t));
    if (!res) {
        perror("init:");
        exit(1);
    }
    res->x = 0; res->y = 0; res->z = 0;
    return res;
}

void vector3D_destroy(vector3D_t *vector) {
    if (vector) {
        free(vector);
    }
}

void vector3D_sum(const vector3D_t *vector1, const vector3D_t *vector2, vector3D_t *res) {
    if (!vector1 || !vector2 || !res) {
        return;
    }
    res->x = vector1->x + vector2->x;
    res->y = vector1->y + vector2->y;
    res->z = vector1->z + vector2->z;
}

void vector3D_sub(const vector3D_t *vector1, const vector3D_t *vector2, vector3D_t *res) {
    if (!vector1 || !vector2 || !res) {
        return;
    }
    res->x = vector1->x - vector2->x;
    res->y = vector1->y - vector2->y;
    res->z = vector1->z - vector2->z;
}

double vector3D_dot(const vector3D_t *vector1, const vector3D_t *vector2) {
    if (!vector1 || !vector2) { 
        return 0.0; 
    }
    return vector1->x * vector2->x + vector1->y * vector2->y + vector1->z * vector2->z;
}

void vector3D_cross(const vector3D_t *vector1, const vector3D_t *vector2, vector3D_t *res) {
    if (!vector1 || !vector2 || !res) {
        return;
    }
    vector3D_t i;
    vector3D_t j;
    vector3D_t k;

    i.x = 1; i.y = 0; i.z = 0;
    j.x = 0; j.y = 1; j.z = 0;
    k.x = 0; k.y = 0; k.z = 1;

    double det1 = determinant(vector1->y, vector1->z, vector2->y, vector2->z);
    double det2 = determinant(vector1->x, vector1->z, vector2->x, vector2->z);
    double det3 = determinant(vector1->x, vector1->y, vector2->x, vector2->y);

    vector3D_mult_number(&i, &i, det1);
    vector3D_mult_number(&j, &j, det2);
    vector3D_mult_number(&k, &k, det3);
    vector3D_sub(&i, &j, res);
    vector3D_sum(res, &k, res);
}

