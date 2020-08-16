#ifndef RUSHI_DBG_H
#define RUSHI_DBG_H

#include <iostream>

#ifdef DEBUG

#define DBG(msg) std::cout << "[Line:" << __LINE__ <<"] " << #msg << " = " << msg << "\n";
#define DBG_M(msg) std::cout << "[Line:" << __LINE__ << "] " << msg << "\n";
#define DBG_V(msg, ...) std::cout << "[Line:" << __LINE__ << "] " << "[" << #msg << ", " << #__VA_ARGS__ << "] = "; dbg_1(msg, __VA_ARGS__);

#else
	
#define DBG(msg) 
#define DBG_M(msg) 
#define DBG_V(msg)

#endif

void dbg_1() {std::cout << "\n"; };

template <typename T, typename... Types>
void dbg_1(T var1, Types... var2) {
	std::cout << var1 << " ";
	dbg_1(var2...);
}

#endif
