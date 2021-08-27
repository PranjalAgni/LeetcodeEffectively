using namespace std;

// Time: O(steps^height) | Space: O(height)
int staircaseTraversal(int height, int maxSteps) {
    if (height == 0 || height == 1) return 1;
    int ans = 0;
    for (int step = 1; step <= maxSteps; step++) {
        if (step <= height) {
            ans += staircaseTraversal(height - step, maxSteps);
        }
    }
    return ans;
}