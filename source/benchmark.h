#ifndef GUARD_BENCHMARK_H
#define GUARD_BEMCHMARK_H

#include <chrono>
#include <vector>
#include <iostream>
#include <iomanip>
#include <ios>
#include <climits>
#include <math.h>


template<class Ty>
void benchmark(Ty testfunc(), unsigned num = 3, std::ostream &os = std::cout) {
	std::vector<long double> time_val(num);
	
	for (auto i = 0; i < num; i++) {
		std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
		testfunc();
		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
		time_val[i] = (end - begin).count();
	}

	long double sum = 0;
	for (auto i = 0; i < num; i++) {
		sum += time_val[i];
	}

	long double average_time_ms = sum /(num * 1000000);

	std::streamsize stream_size_tp = os.precision();
	os << "Average time: "
		<< std::setprecision(log10(LLONG_MAX) + 1)
		<< average_time_ms
		<< std::setprecision(stream_size_tp)
		<< "ms." << std::endl;
}

#endif
