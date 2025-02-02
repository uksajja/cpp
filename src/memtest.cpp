#include <stdio.h>
#include <stdlib.h>


double **m2ddouble(int nrl, int nrh, int ncl, int nch) {
    int i;
    double **m;

    m = (double **)malloc((unsigned)(nrh - nrl + 1) * sizeof(double *));
    if (!m) {
        return NULL;
    }
    m -= nrl;

    for (i = nrl; i <= nrh; i++) {
        m[i] = (double *)malloc((unsigned)(nch - ncl + 1) * sizeof(double));
        if (!m[i]) {
            return NULL;
        }
        m[i] -= ncl;
    }

    return m;
}
void free_m2ddouble(double **m, int nrl, int nrh, int ncl, int nch) {
    int i;

    for (i = nrh; i >= nrl; i--) {
        free((char *)(m[i] + ncl));
    }
    free((char *)(m + nrl));

    return;
}

void print2DMat(double **m, int nrl, int nrh, int ncl, int nch) {
    int i, j;

    for (i = nrl; i <= nrh; i++) {
        for (j = ncl; j <= nch; j++) {
            printf("%f ", &(m[i][j]));
        }
        printf("\n");
    }

    for (i = nrl; i <= nrh; i++) {
      for (j = ncl; j <= nch; j++) {
        printf("%f ", m[i][j]);
      }
      printf("\n");
    }

    return;
}

void memtest2D() {
    double **m;
    int nrl = 1, nrh = 3, ncl = 1, nch = 5;

    m = m2ddouble(nrl, nrh, ncl, nch);
    if (!m) {
        return;
    }
    int count = 1;
    for (int i = nrl; i <= nrh; i++) {
        for (int j = ncl; j <= nch; j++) {
            m[i][j] = count++;
        }
    }

    print2DMat(m, nrl, nrh, ncl, nch);

    free_m2ddouble(m, nrl, nrh, ncl, nch);

    return;
}
