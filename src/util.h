#pragma once


#define IN_RANGE(X, A, B) ((A) <= (X) && (X)<= (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define SWAP(T, A, B) do {T Temporary = A; A = B; B = Temporary;} while (0)