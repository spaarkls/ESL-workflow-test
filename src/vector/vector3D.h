#ifndef VECTOR3D_H
#define VECTOR3D_H

#define VECTOR3D_OK 1
#define VECTOR3D_ERROR 0


typedef struct vector3D_t vector3D_t;

vector3D_t *vector3D_init(void);
vector3D_t *vector3D_init_with_value(double x, double y, double z);
void vector3D_destroy(vector3D_t *vector);
int vector3D_sum(const vector3D_t *vector1, const vector3D_t *vector2, vector3D_t *res);
int vector3D_sub(const vector3D_t *vector1, const vector3D_t *vector2, vector3D_t *res);
double vector3D_dot(const vector3D_t *vector1, const vector3D_t *vector2);
int vector3D_cross(const vector3D_t *vector1, const vector3D_t *vector2, vector3D_t *res);
double vector3D_get_x(const vector3D_t *vector);
double vector3D_get_y(const vector3D_t *vector);
double vector3D_get_z(const vector3D_t *vector);

int vector3D_set_x(vector3D_t *vector, double x);
int vector3D_set_y(vector3D_t *vector, double y);
int vector3D_set_z(vector3D_t *vector, double z);
int vector3D_set_xyz(vector3D_t *vector, double x, double y, double z);

#endif