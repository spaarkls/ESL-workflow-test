#ifndef VECTOR3D
#define VECTOR3D

typedef struct vector3D_t {
    double x, y, z;

} vector3D_t;


vector3D_t *vector3D_init(void);
void vector3D_destroy(vector3D_t *vector);
void vector3D_sum(const vector3D_t *vector1, const vector3D_t *vector2, vector3D_t *res);
void vector3D_sub(const vector3D_t *vector1, const vector3D_t *vector2, vector3D_t *res);
double vector3D_dot(const vector3D_t *vector1, const vector3D_t *vector2);
void vector3D_cross(const vector3D_t *vector1, const vector3D_t *vector2, vector3D_t *res);

#endif