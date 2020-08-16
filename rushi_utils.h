#ifndef RUSHI_UTILS_H
#define RUSHI_UTILS_H

#include <iostream>
#include <functional>
#include <vector>
#include <assert.h>

typedef vector<int>       vec_i;
typedef vector<long long> vec_ll;
typedef vector<float>     vec_f;
typedef vector<double>    vec_d;
typedef vector<char>      vec_c;
typedef vector<string>    vec_s;

#define FOR(i, b, e)  for(int i=(b); i < (e); ++i)
#define REP(i, n)     for(int i = 0; i < (n); ++i)
#define ll long long
#define sort_all(c) sort(c.begin(), c.end());
#define PB push_back
#define F first
#define S second

// Modular Arithmatic
const long long MOD = 10e8+7;
vec_ll fact;
vec_ll ifact;
const int sz = 5001;
fact.resize(sz);
ifact.resize(sz);
  
fact[0] = fact[1] = 1;
for(int i = 2; i < sz; ++i)
  fact[i] = (i * fact[i-1]) % MOD;
    
vec_ll imod(sz);
imod[0] = imod[1] = 1;
for(int i = 2; i < sz; ++i)
  imod[i] = (MOD - ((MOD/i) * imod[MOD%i]) % MOD) % MOD;
    
ifact[0] = ifact[1] = 1;
for(int i = 2; i < sz; ++i)
  ifact[i] = (imod[i] * ifact[i-1]) % MOD;
	
ll NCR(const ll n1, const ll r)
{
  ll ans = fact[n1];
  ans = (ans * ifact[r]) % MOD;
  ans = (ans * ifact[n1-r]) % MOD;
  return ans;
}

template <typename T>
class Matrix {
	int n, m;
	vector<T> mat;

	public: 
	
	Matrix(const int N, const int M): n(N), m(M), mat(N*M) { }

	int getRows() { return n; }

	int getCols() { return m; }

	T& operator()(const int r, const int c) {
		assert(r >= 0); assert(r < n); assert( c >= 0); assert(c < m);
		return mat[r*m+c];
	}

	T operator()(const int r, const int c) const {
		assert(r >= 0); assert(r < n); assert( c >= 0); assert(c < m);
		return mat[r*m+c];
	}
};

template <typename T>
ostream& operator << (ostream& os, Matrix<T>& mat) {
	const int nr = mat.getRows();
	const int nc = mat.getCols();
	REP(i, nr) {
		REP(j, nc-1)
			os << mat(i, j) << " ";
		os << mat(i, nc-1) << "\n";
	}

	return os;
}

template <typename T>
istream& operator >> (istream& is, Matrix<T>& mat) {
	const int nr = mat.getRows();
	const int nc = mat.getCols();
	REP(i, nr)
		REP(j, nc)
			is >> mat(i, j);

	return is;
}

template<typename T>
ostream& operator << (ostream& os, vector<T>& v) {
	const int sz = v.size();
	REP(i, sz-1)
		os << v[i] << " ";
	os << v[sz-1] << "\n";
	return os;
}

template<typename T>
istream& operator >> (istream& is, vector<T>& v) {
	const int sz = v.size();
	REP(i, sz)
		is >> v[i];
	return is;
}


void read_lines(vec_s& vs) {
	cin.ignore();
	const int sz = vs.size();
	REP(i, sz)
		getline(cin, vs[i]);
}

template<class C>
int bsearch(C& c, std::function<int(int)> fn, int beg=0, int end=-1) {
	const int sz = c.size();
	if(-1 == end) end = sz;
	assert(beg >= 0); assert(beg < end); assert(end <= sz);

	if(fn(beg) > 0 || fn(end-1) < 0) return -1;
	int ind = beg-1, ret = -1, ret1= -1;
	for(int step = (end-beg+1)/2; step > 0 && ret != 0; step/= 2)
		while( ((ind+step) < end) && (ret1 = fn(ind+step)) <= 0) { ind+=step; ret = ret1; }
	if(ret != 0) ind = -1;
	return ind;
}

template<class C, typename T>
int bsearch(C& c, T& t, int beg = 0, int end = -1) {
	std::function<int(int)> lambda = [&c, &t](int i)->int {
			if(c[i] < t) return -1;
			if(c[i] > t) return 1;
			return 0;
		};

	return bsearch(c, lambda, beg, end);
}

#endif

