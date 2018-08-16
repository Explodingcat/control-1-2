#include <algorithm>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#define X first
#define Y second
#define LI long long
#define MP make_pair
#define PB push_back
#define SZ size()
#define SQ(a) ((a)*(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

using namespace std;

typedef int V;          // tipo de costes
typedef pair<V,int> P;  // par de (coste,nodo)
typedef set<P> S;       // conjunto de pares

int N;                  // numero de nodos
vector<P> A[10001];     // listas adyacencia (coste,nodo)

V dijkstra(int s, int t) {
  S m;                          // cola de prioridad
  vector<V> z(N, 1000000000);   // distancias iniciales
  z[s] = 0;                     // distancia a s es 0
  m.insert(MP(0, s));           // insertar (0,s) en m
  while (m.SZ > 0) {
    P p = *m.begin();   // p=(coste,nodo) con menor coste
    m.erase(m.begin()); // elimina este par de m
    if (p.Y == t) return p.X; // cuando nodo es t, acaba
    // para cada nodo adjacente al nodo p.Y
    for (int i = 0; i < (int)A[p.Y].SZ; i++) {
      // q = (coste hasta nodo adjacente, nodo adjacente)
      P q(p.X + A[p.Y][i].X, A[p.Y][i].Y);
      // si q.X es la menor distancia hasta q.Y
      if (q.X < z[q.Y]) {
	m.erase(MP(z[q.Y], q.Y)); // borrar anterior
	m.insert(q);              // insertar q
	z[q.Y] = q.X;             // actualizar distancia
      }
    }
  }
  return -1;
}

int main() {
  N = 1000;             // solucion 0-1-2-4-3-5, coste 11
  //linea 5
  A[0].PB(MP(1, 1)); // Plaza maipu
  A[1].PB(MP(1, 2)); // arista (0, 2) con coste 5
  A[1].PB(MP(1, 0)); // arista (0, 2) con coste 5
  A[2].PB(MP(1, 3)); // arista (1, 2) con coste 2
  A[2].PB(MP(1, 1)); // arista (0, 2) con coste 5
  A[3].PB(MP(1, 4)); // arista (1, 3) con coste 7
  A[3].PB(MP(1, 2)); // arista (1, 3) con coste 7
  A[4].PB(MP(1, 5)); // arista (2, 4) con coste 2
  A[4].PB(MP(1, 3)); // arista (2, 4) con coste 2
  A[5].PB(MP(1, 6)); // arista (3, 5) con coste 3
  A[5].PB(MP(1, 4)); // arista (3, 5) con coste 3
  A[6].PB(MP(1, 7)); // arista (4, 3) con coste 2
  A[6].PB(MP(1, 5)); // arista (4, 3) con coste 2
  A[7].PB(MP(1, 8)); // arista (4, 5) con coste 8
  A[7].PB(MP(1, 6)); // arista (4, 5) con coste 8
  A[8].PB(MP(1, 9)); // san pablo
  A[8].PB(MP(1, 7)); // san pablo
  A[9].PB(MP(1, 10)); // arista (0, 2) con coste 5
  A[9].PB(MP(1, 8)); // arista (0, 2) con coste 5
  A[10].PB(MP(1, 11)); // arista (1, 2) con coste 2
  A[10].PB(MP(1, 19)); // arista (1, 2) con coste 2
  A[11].PB(MP(1, 12)); // arista (1, 3) con coste 7
  A[11].PB(MP(1, 10)); // arista (1, 3) con coste 7
  A[12].PB(MP(1, 13)); // arista (2, 4) con coste 2
  A[12].PB(MP(1, 11)); // arista (2, 4) con coste 2
  A[13].PB(MP(1, 14)); // arista (3, 5) con coste 3
  A[13].PB(MP(1, 12)); // arista (3, 5) con coste 3
  A[14].PB(MP(1, 15)); // arista (4, 3) con coste 2
  A[14].PB(MP(1, 13)); // arista (4, 3) con coste 2
  A[15].PB(MP(1, 16)); // arista (4, 5) con coste 8
  A[15].PB(MP(1, 14)); // arista (4, 5) con coste 8
  A[16].PB(MP(1, 17)); // arista (0, 1) con coste 2
  A[16].PB(MP(1, 15)); // arista (0, 1) con coste 2
  A[17].PB(MP(1, 18)); // arista (0, 2) con coste 5
  A[17].PB(MP(1, 16)); // arista (0, 2) con coste 5
  A[18].PB(MP(1, 19)); // baquedano
  A[18].PB(MP(1, 17)); // baquedano
  A[19].PB(MP(1, 20)); // arista (1, 3) con coste 7
  A[19].PB(MP(1, 18)); // arista (1, 3) con coste 7
  A[20].PB(MP(1, 21)); // arista (2, 4) con coste 2
  A[20].PB(MP(1, 19)); // arista (2, 4) con coste 2
  A[21].PB(MP(1, 22)); // arista (3, 5) con coste 3
  A[21].PB(MP(1, 20)); // arista (3, 5) con coste 3
  A[22].PB(MP(1, 23)); // arista (4, 3) con coste 2
  A[22].PB(MP(1, 21)); // arista (4, 3) con coste 2
  A[23].PB(MP(1, 24)); // arista (4, 5) con coste 8
  A[23].PB(MP(1, 22)); // arista (4, 5) con coste 8
  A[24].PB(MP(1, 25)); // arista (0, 1) con coste 2
  A[24].PB(MP(1, 23)); // arista (0, 1) con coste 2
  A[25].PB(MP(1, 26)); // arista (0, 2) con coste 5
  A[25].PB(MP(1, 24)); // arista (0, 2) con coste 5
  A[26].PB(MP(1, 27)); // arista (1, 2) con coste 2
  A[26].PB(MP(1, 25)); // arista (1, 2) con coste 2
  A[27].PB(MP(1, 28)); // arista (1, 3) con coste 7
  A[27].PB(MP(1, 26)); // arista (1, 3) con coste 7
  A[28].PB(MP(1, 29)); // arista (2, 4) con coste 2
  A[28].PB(MP(1, 27)); // arista (2, 4) con coste 2
  A[29].PB(MP(1, 30)); // arista (3, 5) con coste 3
  A[29].PB(MP(1, 28)); // arista (3, 5) con coste 3
//linea 1
  A[8].PB(MP(1, 30)); // San pablo combinacion
  A[8].PB(MP(1, 29)); // San pablo combinacion
  A[30].PB(MP(1, 31)); // Neptuno
  A[30].PB(MP(1, 8)); // Neptuno
  A[31].PB(MP(1, 32)); // Pajaritos
  A[31].PB(MP(1, 30)); // Pajaritos
  A[32].PB(MP(1, 33)); // Las rejas
  A[32].PB(MP(1, 31)); // Las rejas
  A[33].PB(MP(1, 34)); // Ecuador
  A[33].PB(MP(1, 32)); // Ecuador
  A[34].PB(MP(1, 35)); // San alberto Hurtado
  A[34].PB(MP(1, 33)); //  San alberto Hurtado
  A[35].PB(MP(1, 36)); // arista (3, 5) con coste 3
  A[35].PB(MP(1, 34)); // arista (3, 5) con coste 3
  A[36].PB(MP(1, 37)); // arista (3, 5) con coste 3
  A[36].PB(MP(1, 35)); // arista (3, 5) con coste 3
  A[37].PB(MP(1, 38)); // arista (3, 5) con coste 3
  A[37].PB(MP(1, 36)); // arista (3, 5) con coste 3
  A[38].PB(MP(1, 39)); // arista (3, 5) con coste 3
  A[38].PB(MP(1, 37)); // arista (3, 5) con coste 3
  A[39].PB(MP(1, 40)); // arista (3, 5) con coste 3
  A[39].PB(MP(1, 38)); // arista (3, 5) con coste 3
  A[40].PB(MP(1, 41)); // arista (3, 5) con coste 3
  A[40].PB(MP(1, 39)); // arista (3, 5) con coste 3
  A[41].PB(MP(1, 42)); // arista (3, 5) con coste 3
  A[42].PB(MP(1, 43)); // arista (3, 5) con coste 3
  A[43].PB(MP(1, 44)); // arista (3, 5) con coste 3
  A[43].PB(MP(1, 42)); // arista (3, 5) con coste 3
  A[18].PB(MP(1, 45)); // baquedano
  A[18].PB(MP(1, 43)); // baquedano
  A[45].PB(MP(1, 46)); // arista (3, 5) con coste 3
  A[45].PB(MP(1, 44)); // arista (3, 5) con coste 3
  A[46].PB(MP(1, 47)); // arista (3, 5) con coste 3
  A[46].PB(MP(1, 45)); // arista (3, 5) con coste 3
  A[47].PB(MP(1, 48)); // arista (3, 5) con coste 3
  A[47].PB(MP(1, 46)); // arista (3, 5) con coste 3
  A[48].PB(MP(1, 49)); // arista (3, 5) con coste 3
  A[48].PB(MP(1, 47)); // arista (3, 5) con coste 3
  A[49].PB(MP(1, 50)); // arista (3, 5) con coste 3
  A[49].PB(MP(1, 48)); // arista (3, 5) con coste 3
  A[50].PB(MP(1, 51)); // arista (3, 5) con coste 3
  A[50].PB(MP(1, 49)); // arista (3, 5) con coste 3
  A[51].PB(MP(1, 52)); // arista (3, 5) con coste 3
  A[51].PB(MP(1, 50)); // arista (3, 5) con coste 3
  A[52].PB(MP(1, 53)); // arista (3, 5) con coste 3
  A[52].PB(MP(1, 51)); // arista (3, 5) con coste 3
  A[53].PB(MP(1, 54)); // arista (3, 5) con coste 3
  A[53].PB(MP(1, 52)); // arista (3, 5) con coste 3
  A[54].PB(MP(1, 55)); // arista (3, 5) con coste 3
  A[54].PB(MP(1, 53)); // arista (3, 5) con coste 3
  A[55].PB(MP(1, 56)); // arista (3, 5) con coste 3
  A[55].PB(MP(1, 54)); // arista (3, 5) con coste 3
  cout << dijkstra(34, 0) << endl;
}
