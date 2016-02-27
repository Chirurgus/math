#ifndef GUARD_MISC_FUNCS_H
#define GUARD_MISC_FUNCS_H

template<class Ty>
Ty factorial(const Ty &n) {
	if (n <= 1)
		return 1;
	else
		return n * factorial(n - 1);
}

#endif