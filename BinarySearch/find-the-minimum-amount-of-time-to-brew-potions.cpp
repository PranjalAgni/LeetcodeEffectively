class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int N = skill.size();
        int M = mana.size();

        return skill[0] * mana[0];
    }
};