#ifndef KINEMATICS_H
#define KINEMATICS_H

#include <stdint.h>
#include <stddef.h>

typedef enum { JOINT_FIXED, JOINT_ROTATIONAL, JOINT_TRANSLATIONAL } joint_type_t;

typedef struct { float a, b, c, d; } quat_f_t;
typedef struct { float x, y, z; }    vect3_t;

/* ── Primitives ─────────────────────────────────────────────────────────── */

typedef struct { float m[4][4]; }          mat4_t;
typedef struct { quat_f_t r; vect3_t t; }  transform_t;
typedef struct { quat_f_t real; quat_f_t dual; } dual_quat_t;

/* ── mat4 flavor ─────────────────────────────────────────────────────────── */

typedef struct link_mat4_t  link_mat4_t;
typedef struct joint_mat4_t joint_mat4_t;

struct joint_mat4_t {
    joint_type_t  type;
    link_mat4_t  *parent;
    link_mat4_t  *child;
    float         q;
    vect3_t       axis;
    mat4_t        offset;   /* fixed: parent frame → joint frame */
    mat4_t        dof;      /* variable: f(q, axis)              */
    mat4_t        result;   /* offset * dof                      */
};

struct link_mat4_t {
    const char    *name;
    joint_mat4_t  *joints;
    size_t         num_joints;
};

/* ── transform (quat + vec3) flavor ─────────────────────────────────────── */

typedef struct link_transform_t  link_transform_t;
typedef struct joint_transform_t joint_transform_t;

struct joint_transform_t {
    joint_type_t      type;
    link_transform_t *parent;
    link_transform_t *child;
    float             q;
    vect3_t           axis;
    transform_t       offset;
    transform_t       dof;
    transform_t       result;
};

struct link_transform_t {
    const char        *name;
    joint_transform_t *joints;
    size_t             num_joints;
};

/* ── dual quaternion flavor ──────────────────────────────────────────────── */

typedef struct link_dual_quat_t  link_dual_quat_t;
typedef struct joint_dual_quat_t joint_dual_quat_t;

struct joint_dual_quat_t {
    joint_type_t      type;
    link_dual_quat_t *parent;
    link_dual_quat_t *child;
    float             q;
    vect3_t           axis;
    dual_quat_t       offset;
    dual_quat_t       dof;
    dual_quat_t       result;
};

struct link_dual_quat_t {
    const char         *name;
    joint_dual_quat_t  *joints;
    size_t              num_joints;
};

#endif
