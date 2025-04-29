#include <string>
#include <vector>
#include <tuple>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    auto [castingTime, heal, bonus] = tie(bandage[0], bandage[1], bandage[2]);
    int MaxHealth = health;
    int combo = 0, attackIdx = 0;
    
    for (int time = 1; time <= attacks.back()[0]; ++time) {
        if (attacks[attackIdx][0] == time) {
            health -= attacks[attackIdx++][1];
            if (health <= 0) return -1;
            combo = 0;
        }
        else {
            health = min(health + heal, MaxHealth);
            combo++;
        }
        
        if (combo == castingTime) {
            health = min(health + bonus, MaxHealth);
            combo = 0;
        }
    }
    
    return health;
}