#ifndef KINEMATICS_H
#define KINEMATICS_H

#include <stdint.h>
#include <stddef.h>

typedef enum { JOINT_FIXED, JOINT_ROTATIONAL, JOINT_TRANSLATIONAL } joint_type_t;

typedef struct { float a, b, c, d; } quat_f_t;
typedef struct { float x, y, z; }    vect3_t;

/* ── Primitives ─────────────────────────────────────────────────────────── */

typedef struct { float m[4][4]; }          mat4_t;

/* ── mat4 flavor ─────────────────────────────────────────────────────────── */

typedef struct link_mat4_t  link_mat4_t;
typedef struct joint_mat4_t joint_mat4_t;

struct joint_mat4_t 
{
    joint_type_t  type;
    link_mat4_t  *parent;
    link_mat4_t  *child;
    float         q;
    vect3_t       axis;
    mat4_t        offset;   /* fixed: parent frame → joint frame */
    mat4_t        dof;      /* variable: f(q, axis)              */
    mat4_t        result;   /* offset * dof                      */
};

struct link_mat4_t 
{
    const char    *name;
    joint_mat4_t  ** joints;
    size_t         num_joints;
};


#endif
