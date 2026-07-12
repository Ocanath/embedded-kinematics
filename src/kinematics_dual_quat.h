#ifndef KINEMATICS_DUAL_QUAT_H
#define KINEMATICS_DUAL_QUAT_H

#include <stdint.h>
#include <stddef.h>

typedef enum { JOINT_FIXED, JOINT_ROTATIONAL, JOINT_TRANSLATIONAL } joint_type_t;

typedef struct { float a, b, c, d; } quat_f_t;
typedef struct { float x, y, z; }    vect3_t;

/* ── Primitives ─────────────────────────────────────────────────────────── */

typedef struct { quat_f_t real; quat_f_t dual; } dual_quat_t;

/* ── dual quaternion flavor ──────────────────────────────────────────────── */

typedef struct link_dual_quat_t  link_dual_quat_t;
typedef struct joint_dual_quat_t joint_dual_quat_t;

struct joint_dual_quat_t 
{
	const char 	* name;
    joint_type_t      type;
    link_dual_quat_t *parent;
    link_dual_quat_t *child;
    float             q;
    vect3_t           axis;
    dual_quat_t       offset;
    dual_quat_t       dof;
    dual_quat_t       result;
};

struct link_dual_quat_t 
{
    const char         *name;
    joint_dual_quat_t  *joints;
    size_t              num_joints;
};

#endif
