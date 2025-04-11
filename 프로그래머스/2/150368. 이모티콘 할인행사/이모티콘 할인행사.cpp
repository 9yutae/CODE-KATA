#include <string>
#include <vector>

using namespace std;
vector<vector<int>> user;
vector<int> emoticon;
int MaxSubscribers = 0;
int MaxSalesAmount = 0;
int N;

void calculate(const vector<int>& discountRates) {
    int subscribers = 0;
    int salesAmount = 0;
    
    for (const auto& flag : user) {
        int individualSales = 0;
        for (int i=0; i < N; i++) {
            if (discountRates[i] >= flag[0]) {
                individualSales += (emoticon[i] * (100 - discountRates[i]) / 100);
            }
        }
        
        if (individualSales >= flag[1]) subscribers++;
        else salesAmount += individualSales;
    }
    
    if (MaxSubscribers < subscribers) {
            MaxSubscribers = subscribers;
            MaxSalesAmount = salesAmount;
    }
    else if (MaxSubscribers == subscribers) {
        MaxSalesAmount = max(MaxSalesAmount, salesAmount);
    }
}

void backtrack(int depth, vector<int>& discountRates) {
    if (depth == N) {
        calculate(discountRates);
        return;
    }  
    
    for (int discountRate=10; discountRate<50; discountRate+=10) {
        discountRates[depth] = discountRate;
        backtrack(depth + 1, discountRates);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    user = users;
    emoticon = emoticons;
    N = emoticons.size();
    vector<int> discountRates(N, 0);
    
    backtrack(0, discountRates);
    
    return { MaxSubscribers , MaxSalesAmount };
}