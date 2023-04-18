#include <vector>
#include <string>
using namespace std;

vector<float> move(vector<float> p, int U, float pExact, float pOvershoot, float pUndershoot){
    vector<float> q (p.size(), 0);
    float s = 0;
    for(int i = 0; i < p.size(); i++){
        if (i-U < 0) {
            s = pExact * p[(i-U) + p.size()];
        }
        else {
            s = pExact * p[(i-U) % p.size()];
        }
        if (i-U-1 < 0) {
            s = s + pOvershoot * p[(i-U-1) + p.size()];
        }
        else {
            s = s + pOvershoot * p[(i-U-1) % p.size()];
        }
        if (i-U+1 < 0) {
            s = s + pUndershoot * p[(i-U+1) + p.size()];
        }
        else {
            s = s + pUndershoot * p[(i-U+1) % p.size()];
        }
        q[i] = s;
    }
    return q;
}