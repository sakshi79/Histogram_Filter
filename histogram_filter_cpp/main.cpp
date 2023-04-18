#include <iostream>
#include <vector>
#include <string>
#include "move.h"
#include "sense.h"
using namespace std;

int main(){
    vector<float> p (5, 0.2);
    vector<string> world(5);
    vector<string> measurements(2);
    vector<int> motions(2, 1);
    world = {"green", "red", "red", "green", "green"};
    measurements = {"red", "green"};
    float pHit=0.6, pMiss=0.2, pExact=0.8, pOvershoot=0.1, pUndershoot=0.1;

    for(int i = 0; i < measurements.size(); i++){
        p = sense(p, measurements[i], world, pHit, pMiss);
        p = move(p, motions[i], pExact, pOvershoot, pUndershoot);
    }

    for(int i = 0; i < p.size(); i++){
        cout<< p[i] << " ";
    }

    return 0;
}