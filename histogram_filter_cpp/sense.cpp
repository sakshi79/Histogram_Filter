#include <vector>
#include <string>
#include <numeric>
using namespace std;

vector<float> sense(vector<float> p, string Z, vector<string> world, 
                     float pHit, float pMiss) {
    /* 
     * Updates probability based on a sensor reading.
     */

    vector<float> q (p.size());
    bool hit;
    float s = 0; // sum of the q vector's elements

    // Calculate new probabilities
    for (int i = 0; i < p.size(); i++) {
        hit = (Z == world[i]);
        q[i] = p[i] * (hit * pHit + (1-hit) * pMiss);
        s += q[i]; 
    }

    // Divide probabilities by the total sum
    for (int i = 0; i < q.size(); i++) {
        q[i] = q[i] / s;
    }

    return q;
}