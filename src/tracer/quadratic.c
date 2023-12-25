#include "tracer.h"

// If `a` is close to 0, there are no solutions as the quadratic equation.
void	solve_quadratic(t_quadratic *q)
{
	double discriminant;

	q->solved = false;
	if (fabs(q->a) < 1e-3)
		return ;
	discriminant = q->half_b * q->half_b - q->a * q->c;
	if (discriminant < 0)
		return ;
	q->solved = true;
	q->t1 = (-q->half_b - sqrt(discriminant)) / q->a;
	q->t2 = (-q->half_b + sqrt(discriminant)) / q->a;
}
