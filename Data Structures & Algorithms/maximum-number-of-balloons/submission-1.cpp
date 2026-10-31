class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>M;

        for(auto c:text){
            M[c]++;
        }

        return min({M['b'],M['a'],M['l']/2,M['o']/2,M['n']});
          
          }       
    
};