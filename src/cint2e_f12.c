/*
 * Copyright (C) 2013-  Qiming Sun <osirpt.sun@gmail.com>
 */

#include <stdlib.h>
#include "cint_bas.h"
#include "g2e.h"
#include "optimizer.h"
#include "cint2e.h"

int CINTinit_int2e_stg_EnvVars(CINTEnvVars *envs, int *ng, int *shls,
                           int *atm, int natm, int *bas, int nbas, double *env);
int CINTinit_int2e_yp_EnvVars(CINTEnvVars *envs, int *ng, int *shls,
                           int *atm, int natm, int *bas, int nbas, double *env);
int CINT2e_spheric_drv(double *out, int *dims, CINTEnvVars *envs, CINTOpt *opt,
                       double *cache);
void CINTgout2e(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty);

void CINTall_2e_stg_optimizer(CINTOpt **opt, int *ng,
                              int *atm, int natm, int *bas, int nbas, double *env);

int int2e_stg_sph(double *out, int *dims, int *shls, int *atm, int natm,
                  int *bas, int nbas, double *env, CINTOpt *opt, double *cache)
{
        int ng[] = {0, 0, 0, 0, 0, 1, 1, 1};
        CINTEnvVars envs;
        CINTinit_int2e_stg_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
        envs.f_gout = &CINTgout2e;
        return CINT2e_spheric_drv(out, dims, &envs, opt, cache);
}
void int2e_stg_optimizer(CINTOpt **opt, int *atm, int natm,
                         int *bas, int nbas, double *env)
{
        int ng[] = {0, 0, 0, 0, 0, 1, 1, 1};
        CINTall_2e_stg_optimizer(opt, ng, atm, natm, bas, nbas, env);
}

int int2e_yp_sph(double *out, int *dims, int *shls, int *atm, int natm,
                 int *bas, int nbas, double *env, CINTOpt *opt, double *cache)
{
        int ng[] = {0, 0, 0, 0, 0, 1, 1, 1};
        CINTEnvVars envs;
        CINTinit_int2e_yp_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
        envs.f_gout = &CINTgout2e;
        return CINT2e_spheric_drv(out, dims, &envs, opt, cache);
}
void int2e_yp_optimizer(CINTOpt **opt, int *atm, int natm,
                        int *bas, int nbas, double *env)
{
        int ng[] = {0, 0, 0, 0, 0, 1, 1, 1};
        CINTall_2e_stg_optimizer(opt, ng, atm, natm, bas, nbas, env);
}

#define ALL_CINT(NAME) \
int c##NAME##_sph(double *out, int *shls, int *atm, int natm, \
            int *bas, int nbas, double *env, CINTOpt *opt) { \
        return NAME##_sph(out, NULL, shls, atm, natm, bas, nbas, env, opt, NULL); \
} \
void c##NAME##_sph_optimizer(CINTOpt **opt, int *atm, int natm, \
                         int *bas, int nbas, double *env) { \
        NAME##_optimizer(opt, atm, natm, bas, nbas, env); \
}

ALL_CINT(int2e_yp)
ALL_CINT(int2e_stg)



/*
 * ((NABLA i) j| F12 |k l)
 */
void CINTgout2e_int2e_ip1(double *gout,
                          double *g, int *idx, CINTEnvVars *envs, int gout_empty);

void int2e_yp_ip1_optimizer(CINTOpt **opt, int *atm, int natm,
                             int *bas, int nbas, double *env) {
        int ng[] = {1, 0, 0, 0, 1, 1, 1, 3};
        CINTall_2e_stg_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
int int2e_yp_ip1_sph(double *out, int *dims, int *shls, int *atm, int natm,
                      int *bas, int nbas, double *env, CINTOpt *opt, double *cache) {
        int ng[] = {1, 0, 0, 0, 1, 1, 1, 3};
        CINTEnvVars envs;
        CINTinit_int2e_yp_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
        envs.f_gout = &CINTgout2e_int2e_ip1;
        return CINT2e_spheric_drv(out, dims, &envs, opt, cache);
}
ALL_CINT(int2e_yp_ip1)

void int2e_stg_ip1_optimizer(CINTOpt **opt, int *atm, int natm,
                             int *bas, int nbas, double *env) {
        int ng[] = {1, 0, 0, 0, 1, 1, 1, 3};
        CINTall_2e_stg_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
int int2e_stg_ip1_sph(double *out, int *dims, int *shls, int *atm, int natm,
                      int *bas, int nbas, double *env, CINTOpt *opt, double *cache) {
        int ng[] = {1, 0, 0, 0, 1, 1, 1, 3};
        CINTEnvVars envs;
        CINTinit_int2e_stg_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
        envs.f_gout = &CINTgout2e_int2e_ip1;
        return CINT2e_spheric_drv(out, dims, &envs, opt, cache);
}
ALL_CINT(int2e_stg_ip1)
