#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <limits>
using namespace std;

typedef long long int lli;

enum CellType {EMPTY = 0, WALL = 1, STAIRS_UP = 2, STAIRS_DOWN = 3};

struct Cell {
    size_t x, y, z;         // Coordonnées de la cellule
    int type;               // Type de cellule, un de CellType
    lli cost;               // Coût pour rejoindre cette cellule
    bool explored;          // True si la cellule a déjà été explorée

    // Comparaison de cellules (utilisée pour Dijkstra)
    bool operator()(const Cell * left, const Cell * right) {
        return left->cost > right->cost;
    }
};

// Représente le coût des cellules inatteignables
constexpr lli MAX_COST = numeric_limits<lli>::max();

// Données du problème
size_t n, m, l, c;
vector<vector<vector<Cell>>> cells;
vector<lli> floor_costs;

// Enumère les cellules voisines atteignables
vector<Cell*> neighbours(const Cell * start) {
    vector<Cell*> next{};
    size_t x = start->x, y = start->y, z = start->z;
    if(x > 0 && cells[z][y][x-1].type != CellType::WALL) {
        next.push_back(&cells[z][y][x-1]);
    }
    if(x < m-1 && cells[z][y][x+1].type != CellType::WALL) {
        next.push_back(&cells[z][y][x+1]);
    }
    if(y > 0 && cells[z][y-1][x].type != CellType::WALL) {
        next.push_back(&cells[z][y-1][x]);
    }
    if(y < m-1 && cells[z][y+1][x].type != CellType::WALL) {
        next.push_back(&cells[z][y+1][x]);
    }
    if(z < n-1 && cells[z][y][x].type == CellType::STAIRS_UP) {
        next.push_back(&cells[z+1][y][x]);
    }
    if(z > 0 && cells[z][y][x].type == CellType::STAIRS_DOWN) {
        next.push_back(&cells[z-1][y][x]);
    }
    return next;
}

int main() {
    cin >> n >> m ;
    floor_costs.resize(n);
    for(int i=0; i<n; ++i) {
        cin >> floor_costs[i];
    }
    cin >> l >> c;

    // La tour est composée de n étages numérotés de 0 à n-1
    cells.resize(n);
    // Chaque étage est une grille de m*m cellules
    for(size_t z=0; z<n; ++z) {
        cells[z].resize(m);
        for(size_t y=0; y<m; ++y) {
            cells[z][y].assign(m, {0, y, z, CellType::EMPTY, MAX_COST, false});
            for(size_t x=0; x<m; ++x) {
                cin >> cells[z][y][x].type;
                cells[z][y][x].x = x;
            }
        }
    }

    // Dijkstra
    priority_queue<Cell*, vector<Cell*>, Cell> q;
    q.push(&cells[0][l][c]);
    cells[0][l][c].cost = 0;
    while(!q.empty()) {
        Cell *cur = q.top(); q.pop();
        if(cur->explored) {
            continue;
        }
        cur->explored = true;
        for(Cell *next : neighbours(cur)) {
            if(next->cost > cur->cost + floor_costs[cur->z]) {
                next->cost = cur->cost + floor_costs[cur->z];
                q.push(next);
            }
        }
    }

    // Recherche au dernier étage de l'escalier montant de coût minimal
    lli min_cost = MAX_COST;
    for(size_t y=0; y<m; ++y) {
        for(size_t x=0; x<m; ++x) {
            Cell& cell = cells[n-1][y][x];
            if(cell.type == CellType::STAIRS_UP) {
                min_cost = min(min_cost, cell.cost);
            }
        }
    }
    if(min_cost == MAX_COST) {
        cout << -1 << endl;
    } else {
        cout << min_cost + floor_costs[n-1] << endl;
    }
    return 0;
}
