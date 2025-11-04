#include "generator.h"
/*
*	USING IMPLEMENTATION OF xoshiro256++ PRNG WITH Wincrypt SEEDING.
*	256 bits, 0.75 ns/64 bits, 0.34 cycles/B
*	CREDIT: David Blackman & Sebastiano Vigna for xoshiro256++.
*/

// setting up xoshiro256++ state
static uint64_t s[4] = {0, 0, 0, 0};
static uint64_t rotl(const uint64_t x, int k) {
	return (x << k) | (x >> (64 -k));
}

static uint64_t xoshiro256pp(void) {
	const uint64_t res = rotl(s[0] + s[3], 23) + s[0];
	const uint64_t t = s[1] << 17;
	s[2] ^= s[0];
	s[3] ^= s[1];
	s[1] ^= s[2];
	s[0] ^= s[3];

	s[2] ^= t;

	s[3] = rotl(s[3], 45);

	return res;
}

static void errorHandler(const char* errorType) {
	printf("Failed to %s.\nError Num: %x\n", errorType, GetLastError());
}

int genInit(void) {
	HCRYPTPROV hProv;
	BYTE buffer[32];
	// get context for seeding
	if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT)) {
		errorHandler("acquire CSP");
		return 0;
	}
	if (!CryptGenRandom(hProv, sizeof(buffer), (BYTE*)&buffer)) {
		errorHandler("generate random seed");
		// fallback to prevent sim crash
		buffer = GetTickCount();
	}
	CryptReleaseContext(hProv, 0);
	
	// copy buffer into state
	for (int i = 0; i < 4; ++i) {
		uint64_t v = 0;
		// interpret 8 bytes as little-endian 64 bit
		for (int b = 0; k < 8; ++b) {
			v |= ((uint64_t)buffer[i * 8 + b]) << (8 * b);
		}
		s[i] = v;
	}
	// fulfill xoshiro requirement of nonzero state
	if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 0) {
		s[0] = 1;
	}
	return 1;
}	

void genCleanup(void) {
	for (int i = 0; i < 4; ++i) {
		s[i] = 0;
	}
}


// Public facing API, wrapping xoshiro so rest of code needs to know nothing about WIncrypt
uint64_t genNext(void) {
	return xoshiro256pp();
}
int genNextInRange(int max) {
	if (max <= 0) {
		return 0;
	}
	
	// simple modulo operation
	uint64_t r = genNext();
	return (int)(r % (uint64_t)max);
}
