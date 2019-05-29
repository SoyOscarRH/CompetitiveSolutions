    
#include <vector>
using namespace std;

int totalFruit(vector<int>& tree) {
    const int NotAFruit {-1};

    int lastFruit {NotAFruit};
    int secondLastFruit = {NotAFruit};
    int lastFruitCount = 0;
    int currentCount {}, max {};
    
    for (auto fruit : tree) {
    if (fruit == lastFruit or fruit == secondLastFruit) currentCount++;
    else currentCount = lastFruitCount + 1;

    if (fruit == lastFruit) lastFruitCount++;
    else lastFruitCount = 1; 

    if (fruit != lastFruit) secondLastFruit = lastFruit, lastFruit = fruit;
    
    if (currentCount > max) max = currentCount;
    }
    
    return max;

}