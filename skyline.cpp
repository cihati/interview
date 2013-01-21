#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <functional>
#include <cassert>
using namespace std;

// http://acm.uva.es/p/v1/105.html
// http://cseweb.ucsd.edu/classes/sp04/cse101/skyline.pdf

typedef pair<int,int> pii;
struct Building {
  int s, f, h;
  Building(int s, int f, int h) : s(s), f(f), h(h) {}
};
int n;

int main() {
  FILE *inp = fopen("skyline.inp", "r");
  fscanf(inp, "%d", &n);
  vector<pii> events;
  vector<Building> buildings;
  for (int i = 0; i < n; ++i) {
    int s, f, h;
    fscanf(inp, "%d%d%d", &s, &f, &h);
    events.push_back(pii(s, i));
    events.push_back(pii(f, i));
    buildings.push_back(Building(s,f,h));
  }
  sort(events.begin(), events.end());
  vector<pii> criticals;
  set<pii, greater<pii> > active_buildings;
  for (int i = 0; i < 2 * n; ++i) {
    pii event = events[i];
    int id = event.second;
    int pos = event.first;
    if (pos == buildings[id].s) {
      active_buildings.insert(pii(buildings[id].h, id));
    } else {
      active_buildings.erase(pii(buildings[id].h, id));
    }
    pii critical = *active_buildings.begin();
    int height = critical.first;
    if (criticals.size() == 0 || criticals.back().second != height)
      criticals.push_back(pii(pos, height));
  }
  for (int i = 0; i < criticals.size(); ++i) {
    printf("%d %d\n", criticals[i].first, criticals[i].second);
  }
  return 0;
}

