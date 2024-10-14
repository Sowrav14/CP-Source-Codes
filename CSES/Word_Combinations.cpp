#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 5000 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int dp[N];
string s;
int n;


// structure of trie node...
struct Node {
    Node *links[26]; 
    int cntEndWith = 0;
    
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL); 
    }
    Node* get(char ch) {
        return links[ch-'a']; 
    }
    void put(char ch, Node* node) {
        links[ch-'a'] = node; 
    }
    void increaseEnd() {
        cntEndWith++;  
    }
    int getEnd() {
        return cntEndWith; 
    }
};


class Trie {
private: Node *root; 
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node(); 
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        for(int i = 0;i<word.length();i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node()); 
            }
            node = node->get(word[i]); 
        } 
        node->increaseEnd(); 
    }
    
    void countdp(int i){
        Node* node = root;
        for(int j=i;j<n;j++) {
            if(node->containsKey(s[j])) {
                node = node->get(s[j]);
                if(node->getEnd()) dp[i] = (dp[i]%M + dp[j+1]%M)%M;
            } else {
                return; 
            }  
        }
        return; 
    }

} trie;


void solve(){

    cin >> s;
    n = s.size();
    int k; cin >> k;
    for(int i=0;i<k;i++){
        string t; cin >> t;
        trie.insert(t);
    }

    dp[n] = 1;
    for(int i=n-1;i>=0;i--){
        trie.countdp(i);
    }
    cout << dp[0] << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}