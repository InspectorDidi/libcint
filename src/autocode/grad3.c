/*
 * File:
 * Author: Qiming Sun <osirpt.sun@gmail.com>
 * Description: code generated by  gen-code.cl
 */
#include "cint_bas.h"
#include "cart2sph.h"
#include "g2e.h"
#include "cint1e.h"
#include "cint2e.h"
#include "misc.h"
#include "fblas.h"
#include "c2f.h"
/* <NABLA i|OVLP |j> */
static void gout1e_cint1e_ipovlp_cart(double *g, const int *ng,
double *gout, const int nf, const int *idx,
const double ai, const double aj,
const int *shls, const int *atm, const int *bas, const double *env) {
const int INC1 = 1;
const double D1 = 1;
const int i_sh = shls[0];
const int j_sh = shls[1];
const int i_l = bas(ANG_OF, i_sh);
const int j_l = bas(ANG_OF, j_sh);
const int *idy = idx + nf;
const int *idz = idx + nf * 2;
const double *ri = env + atm(PTR_COORD, bas(ATOM_OF, i_sh));
const double *rj = env + atm(PTR_COORD, bas(ATOM_OF, j_sh));
int ix, iy, iz, n;
double *g0 = g;
double *g1 = g0  + ng[0] * ng[1] * 3;
double *g2 = g1  + ng[0] * ng[1] * 3;
double s[3];
G1E_D_I(g1, g0, i_l+0, j_l);
for (n = 0; n < nf; n++) {
ix = idx[n];
iy = idy[n];
iz = idz[n];
s[0] = g1[ix] * g0[iy] * g0[iz];
s[1] = g0[ix] * g1[iy] * g0[iz];
s[2] = g0[ix] * g0[iy] * g1[iz];
gout[0] += + (1*s[0]);
gout[1] += + (1*s[1]);
gout[2] += + (1*s[2]);
gout += 3;
}}
int cint1e_ipovlp_cart(double *opij, const int *shls,
const int *atm, const int natm,
const int *bas, const int nbas, const double *env) {
const int i_sh = shls[0];
const int j_sh = shls[1];
const int i_l = bas(ANG_OF, i_sh);
const int j_l = bas(ANG_OF, j_sh);
int ng[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
ng[1] = j_l + 0 + 1;
ng[0] = i_l + 1 + ng[1];
ng[GSHIFT] = 1;
ng[POS_E1] = 1;
ng[TENSOR] = 3;
return cint1e_drv(opij, ng, 1,
gout1e_cint1e_ipovlp_cart, &c2s_cart_1e,
shls, atm, natm, bas, nbas, env); }
C2F_(cint1e_ipovlp_cart)
/* <NABLA i|OVLP |P DOT P j> */
static void gout1e_cint1e_ipkin_cart(double *g, const int *ng,
double *gout, const int nf, const int *idx,
const double ai, const double aj,
const int *shls, const int *atm, const int *bas, const double *env) {
const int INC1 = 1;
const double D1 = 1;
const int i_sh = shls[0];
const int j_sh = shls[1];
const int i_l = bas(ANG_OF, i_sh);
const int j_l = bas(ANG_OF, j_sh);
const int *idy = idx + nf;
const int *idz = idx + nf * 2;
const double *ri = env + atm(PTR_COORD, bas(ATOM_OF, i_sh));
const double *rj = env + atm(PTR_COORD, bas(ATOM_OF, j_sh));
int ix, iy, iz, n;
double *g0 = g;
double *g1 = g0  + ng[0] * ng[1] * 3;
double *g2 = g1  + ng[0] * ng[1] * 3;
double *g3 = g2  + ng[0] * ng[1] * 3;
double *g4 = g3  + ng[0] * ng[1] * 3;
double *g5 = g4  + ng[0] * ng[1] * 3;
double *g6 = g5  + ng[0] * ng[1] * 3;
double *g7 = g6  + ng[0] * ng[1] * 3;
double *g8 = g7  + ng[0] * ng[1] * 3;
double s[27];
G1E_D_J(g1, g0, i_l+1, j_l+0);
G1E_D_J(g2, g0, i_l+1, j_l+1);
G1E_D_J(g3, g2, i_l+1, j_l+0);
G1E_D_I(g4, g0, i_l+0, j_l);
G1E_D_I(g5, g1, i_l+0, j_l);
G1E_D_I(g6, g2, i_l+0, j_l);
G1E_D_I(g7, g3, i_l+0, j_l);
for (n = 0; n < nf; n++) {
ix = idx[n];
iy = idy[n];
iz = idz[n];
s[0] = g7[ix] * g0[iy] * g0[iz];
s[1] = g6[ix] * g1[iy] * g0[iz];
s[2] = g6[ix] * g0[iy] * g1[iz];
s[3] = g5[ix] * g2[iy] * g0[iz];
s[4] = g4[ix] * g3[iy] * g0[iz];
s[5] = g4[ix] * g2[iy] * g1[iz];
s[6] = g5[ix] * g0[iy] * g2[iz];
s[7] = g4[ix] * g1[iy] * g2[iz];
s[8] = g4[ix] * g0[iy] * g3[iz];
s[9] = g3[ix] * g4[iy] * g0[iz];
s[10] = g2[ix] * g5[iy] * g0[iz];
s[11] = g2[ix] * g4[iy] * g1[iz];
s[12] = g1[ix] * g6[iy] * g0[iz];
s[13] = g0[ix] * g7[iy] * g0[iz];
s[14] = g0[ix] * g6[iy] * g1[iz];
s[15] = g1[ix] * g4[iy] * g2[iz];
s[16] = g0[ix] * g5[iy] * g2[iz];
s[17] = g0[ix] * g4[iy] * g3[iz];
s[18] = g3[ix] * g0[iy] * g4[iz];
s[19] = g2[ix] * g1[iy] * g4[iz];
s[20] = g2[ix] * g0[iy] * g5[iz];
s[21] = g1[ix] * g2[iy] * g4[iz];
s[22] = g0[ix] * g3[iy] * g4[iz];
s[23] = g0[ix] * g2[iy] * g5[iz];
s[24] = g1[ix] * g0[iy] * g6[iz];
s[25] = g0[ix] * g1[iy] * g6[iz];
s[26] = g0[ix] * g0[iy] * g7[iz];
gout[0] += + (-1*s[0]) + (-1*s[4]) + (-1*s[8]);
gout[1] += + (-1*s[9]) + (-1*s[13]) + (-1*s[17]);
gout[2] += + (-1*s[18]) + (-1*s[22]) + (-1*s[26]);
gout += 3;
}}
int cint1e_ipkin_cart(double *opij, const int *shls,
const int *atm, const int natm,
const int *bas, const int nbas, const double *env) {
const int i_sh = shls[0];
const int j_sh = shls[1];
const int i_l = bas(ANG_OF, i_sh);
const int j_l = bas(ANG_OF, j_sh);
int ng[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
ng[1] = j_l + 2 + 1;
ng[0] = i_l + 1 + ng[1];
ng[GSHIFT] = 3;
ng[POS_E1] = 1;
ng[TENSOR] = 3;
return cint1e_drv(opij, ng, 0.5,
gout1e_cint1e_ipkin_cart, &c2s_cart_1e,
shls, atm, natm, bas, nbas, env); }
C2F_(cint1e_ipkin_cart)
/* <NABLA i|NUC |j> */
static void gout1e_cint1e_ipnuc_cart(double *g, const int *ng,
double *gout, const int nf, const int *idx,
const double ai, const double aj,
const int *shls, const int *atm, const int *bas, const double *env) {
const int INC1 = 1;
const double D1 = 1;
const int i_sh = shls[0];
const int j_sh = shls[1];
const int i_l = bas(ANG_OF, i_sh);
const int j_l = bas(ANG_OF, j_sh);
const int *idy = idx + nf;
const int *idz = idx + nf * 2;
const double *ri = env + atm(PTR_COORD, bas(ATOM_OF, i_sh));
const double *rj = env + atm(PTR_COORD, bas(ATOM_OF, j_sh));
int ix, iy, iz, n;
double *g0 = g;
double *g1 = g0  + ng[0] * ng[1] * 3;
double *g2 = g1  + ng[0] * ng[1] * 3;
double s[3];
G1E_D_I(g1, g0, i_l+0, j_l);
for (n = 0; n < nf; n++) {
ix = idx[n];
iy = idy[n];
iz = idz[n];
s[0] = g1[ix] * g0[iy] * g0[iz];
s[1] = g0[ix] * g1[iy] * g0[iz];
s[2] = g0[ix] * g0[iy] * g1[iz];
gout[0] += + (1*s[0]);
gout[1] += + (1*s[1]);
gout[2] += + (1*s[2]);
gout += 3;
}}
int cint1e_ipnuc_cart(double *opij, const int *shls,
const int *atm, const int natm,
const int *bas, const int nbas, const double *env) {
const int i_sh = shls[0];
const int j_sh = shls[1];
const int i_l = bas(ANG_OF, i_sh);
const int j_l = bas(ANG_OF, j_sh);
int ng[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
ng[1] = j_l + 0 + 1;
ng[0] = i_l + 1 + ng[1];
ng[GSHIFT] = 1;
ng[POS_E1] = 1;
ng[TENSOR] = 3;
return cint1e_nuc_drv(opij, ng, 1,
gout1e_cint1e_ipnuc_cart, &c2s_cart_1e,
shls, atm, natm, bas, nbas, env); }
C2F_(cint1e_ipnuc_cart)
/* <NABLA i|RINV |j> */
static void gout1e_cint1e_iprinv_cart(double *g, const int *ng,
double *gout, const int nf, const int *idx,
const double ai, const double aj,
const int *shls, const int *atm, const int *bas, const double *env) {
const int INC1 = 1;
const double D1 = 1;
const int i_sh = shls[0];
const int j_sh = shls[1];
const int i_l = bas(ANG_OF, i_sh);
const int j_l = bas(ANG_OF, j_sh);
const int *idy = idx + nf;
const int *idz = idx + nf * 2;
const double *ri = env + atm(PTR_COORD, bas(ATOM_OF, i_sh));
const double *rj = env + atm(PTR_COORD, bas(ATOM_OF, j_sh));
int ix, iy, iz, n;
double *g0 = g;
double *g1 = g0  + ng[0] * ng[1] * 3;
double *g2 = g1  + ng[0] * ng[1] * 3;
double s[3];
G1E_D_I(g1, g0, i_l+0, j_l);
for (n = 0; n < nf; n++) {
ix = idx[n];
iy = idy[n];
iz = idz[n];
s[0] = g1[ix] * g0[iy] * g0[iz];
s[1] = g0[ix] * g1[iy] * g0[iz];
s[2] = g0[ix] * g0[iy] * g1[iz];
gout[0] += + (1*s[0]);
gout[1] += + (1*s[1]);
gout[2] += + (1*s[2]);
gout += 3;
}}
int cint1e_iprinv_cart(double *opij, const int *shls,
const int *atm, const int natm,
const int *bas, const int nbas, const double *env) {
const int i_sh = shls[0];
const int j_sh = shls[1];
const int i_l = bas(ANG_OF, i_sh);
const int j_l = bas(ANG_OF, j_sh);
int ng[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
ng[1] = j_l + 0 + 1;
ng[0] = i_l + 1 + ng[1];
ng[GSHIFT] = 1;
ng[POS_E1] = 1;
ng[TENSOR] = 3;
return cint1e_rinv_drv(opij, ng, 1,
gout1e_cint1e_iprinv_cart, &c2s_cart_1e,
shls, atm, natm, bas, nbas, env); }
C2F_(cint1e_iprinv_cart)
/* <i|RINV |j> */
static void gout1e_cint1e_rinv_cart(double *g, const int *ng,
double *gout, const int nf, const int *idx,
const double ai, const double aj,
const int *shls, const int *atm, const int *bas, const double *env) {
const int INC1 = 1;
const double D1 = 1;
const int i_sh = shls[0];
const int j_sh = shls[1];
const int i_l = bas(ANG_OF, i_sh);
const int j_l = bas(ANG_OF, j_sh);
const int *idy = idx + nf;
const int *idz = idx + nf * 2;
const double *ri = env + atm(PTR_COORD, bas(ATOM_OF, i_sh));
const double *rj = env + atm(PTR_COORD, bas(ATOM_OF, j_sh));
int ix, iy, iz, n;
double *g0 = g;
double *g1 = g0  + ng[0] * ng[1] * 3;
double s[1];
for (n = 0; n < nf; n++) {
ix = idx[n];
iy = idy[n];
iz = idz[n];
s[0] = g0[ix] * g0[iy] * g0[iz];
gout[0] += + (1*s[0]);
gout += 1;
}}
int cint1e_rinv_cart(double *opij, const int *shls,
const int *atm, const int natm,
const int *bas, const int nbas, const double *env) {
const int i_sh = shls[0];
const int j_sh = shls[1];
const int i_l = bas(ANG_OF, i_sh);
const int j_l = bas(ANG_OF, j_sh);
int ng[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
ng[1] = j_l + 0 + 1;
ng[0] = i_l + 0 + ng[1];
ng[GSHIFT] = 0;
ng[POS_E1] = 1;
ng[TENSOR] = 1;
return cint1e_rinv_drv(opij, ng, 1,
gout1e_cint1e_rinv_cart, &c2s_cart_1e,
shls, atm, natm, bas, nbas, env); }
C2F_(cint1e_rinv_cart)
/* <k NABLA i|R12 |j l> : i,jin electron 1; k,lin electron 2
 * = (NABLA i j|R12 |k l) */
static void gout2e_cint2e_ip1_cart(double *g, const int *ng,
double *gout, const int nf, const int *idx,
const double ai, const double aj, const double ak, const double al,
const int *shls, const int *atm, const int *bas, const double *env) {
const int INC1 = 1;
const double D1 = 1;
const int i_sh = shls[0];
const int j_sh = shls[1];
const int k_sh = shls[2];
const int l_sh = shls[3];
const int i_l = bas(ANG_OF, i_sh);
const int j_l = bas(ANG_OF, j_sh);
const int k_l = bas(ANG_OF, k_sh);
const int l_l = bas(ANG_OF, l_sh);
const int *idy = idx + nf;
const int *idz = idx + nf * 2;
const double *ri = env + atm(PTR_COORD, bas(ATOM_OF, i_sh));
const double *rj = env + atm(PTR_COORD, bas(ATOM_OF, j_sh));
const double *rk = env + atm(PTR_COORD, bas(ATOM_OF, k_sh));
const double *rl = env + atm(PTR_COORD, bas(ATOM_OF, l_sh));
int ix, iy, iz, i, n;
double *g0 = g;
double *g1 = g0 + g_size(ng) * 3;
double *g2 = g1 + g_size(ng) * 3;
double s[3];
G2E_D_I(g1, g0, i_l+0, j_l, k_l, l_l);
for (n = 0; n < nf; n++) {
ix = idx[n];
iy = idy[n];
iz = idz[n];
dset0(3, s);
for (i = 0; i < ng[RYS_ROOTS]; i++) {
s[0] += g1[ix+i] * g0[iy+i] * g0[iz+i];
s[1] += g0[ix+i] * g1[iy+i] * g0[iz+i];
s[2] += g0[ix+i] * g0[iy+i] * g1[iz+i];
}
gout[0] = + (1*s[0]);
gout[1] = + (1*s[1]);
gout[2] = + (1*s[2]);
gout += 3;
}}
int cint2e_ip1_cart(double *opkijl, const int *shls,
const int *atm, const int natm,
const int *bas, const int nbas, const double *env) {
const int i_sh = shls[0];
const int j_sh = shls[1];
const int k_sh = shls[2];
const int l_sh = shls[3];
const int i_l = bas(ANG_OF, i_sh);
const int j_l = bas(ANG_OF, j_sh);
const int k_l = bas(ANG_OF, k_sh);
const int l_l = bas(ANG_OF, l_sh);
int ng[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
ng[3] = j_l + 0 + 1;
ng[2] = l_l + 0 + 1;
ng[1] = k_l + 0 + ng[2];
ng[0] = i_l + 1 + ng[3];
ng[GSHIFT] = 1;
ng[POS_E1] = 1;
ng[POS_E2] = 1;
ng[TENSOR] = 3;
return cint2e_drv(opkijl, ng, 1,
gout2e_cint2e_ip1_cart, &c2s_cart_2e1, &c2s_cart_2e2,
shls, atm, natm, bas, nbas, env); }
C2F_(cint2e_ip1_cart)
