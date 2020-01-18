#ifndef RUSHI_DBG_H
#define RUSHI_DBG_H

#include <fstream> 

std::ofstream dbgos("debug.txt", std::ios_base::app);


#define DBG(msg) dbgos << "[Line:" << __LINE__ <<"] " << #msg << " = " << msg << "\n";

#define DBG_M(msg) dbgos << "[Line:" << __LINE__ << "] " << msg << "\n";

#define DBG_V(msg, ...) dbgos << "[Line:" << __LINE__ << "] " << "[" << #msg << ", " << #__VA_ARGS__ << "] = "; dbg_1(msg, __VA_ARGS__);

void dbg_1() {dbgos << "\n"; };

template <typename T, typename... Types>
void dbg_1(T var1, Types... var2) {
	dbgos << var1 << " ";
	dbg_1(var2...);
}

#endif

