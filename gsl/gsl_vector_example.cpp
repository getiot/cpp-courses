#include <stdio.h>
#include <gsl/gsl_vector.h>  /* For Vectors */
#include <gsl/gsl_rng.h>     /* For Random numbers */

int main(void)
{
    int i, n;
    /* Setup the Random number generator*/
    const gsl_rng_type * T;
    gsl_rng * r;
    gsl_rng_env_setup();
    T = gsl_rng_default;
    r = gsl_rng_alloc (T);

    printf("Number of elements in the vector:: ");
    scanf("%d",&n);
    
    /* Allocate the vector of the specified size*/
    gsl_vector * v = gsl_vector_alloc (n);
    
    /* Set the elements to a uniform random number in [0,1]*/
    for (i = 0; i < n; i++) {
        gsl_vector_set (v, i, gsl_rng_uniform (r));
    }
    
    /* Print the vector*/
    for (i = 0; i < n; i++) {
        printf ("v_%d = %g\n", i, gsl_vector_get (v, i));
    }
    
    gsl_vector_free (v);
    return 0;
}