class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int n=deck.size();
        vector<int>ans(n);
        queue<int>q;
        for(int i=0;i<deck.size();i++) q.push(i);
        for(auto card:deck){
            ans[q.front()]=card;
            q.pop();
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};