#include "arithmetics.h"

using namespace std;

constexpr int P = 1e9+7;

int Add(int a, int b) {
	int ret = a%P;
	ret = (ret<0 ? P+ret : ret) + (b%P);
	return (ret>=0 ? ret%P : ret+P);
}

int Sub(int a, int b) {
	int ret = a%P;
	ret = (ret<0 ? P+ret : ret) - (b%P);
	return (ret>=0 ? ret%P : ret+P);
}

int Mul(int a, int b) {
	int ret = (1ll*(a%P) * (b%P)) % P;
	return (ret<0 ? P+ret : ret);
}

int modpow(int base, int exp, int modulus=P) {
  base %= modulus;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = (1ll*result * base) % modulus;
    base = (1ll*base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
int modinv(int a, int modulus=P) {
  return modpow(a,modulus-2);
}

int Div(int a, int b) {
	int ret = b%P;
	ret = (1ll*(a%P) * modinv(ret<0 ? P+ret : ret)) % P;
	return (ret<0 ? P+ret : ret);
}