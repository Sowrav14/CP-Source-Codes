#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Card {
    int a, b, id;
};

bool compareCards(const Card &x, const Card &y) {
    return x.a > y.a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int total_cards = 2 * n + 1;
    vector<Card> cards(total_cards);

    for (int i = 0; i < total_cards; i++) {
        cin >> cards[i].a >> cards[i].b;
        cards[i].id = i + 1;
    }

    sort(cards.begin(), cards.end(), compareCards);


    vector<int> result;
    result.push_back(cards[0].id);

    for (int i = 1; i < total_cards; i += 2) {
        if (i + 1 < total_cards) {
            if (cards[i].b > cards[i + 1].b) {
                result.push_back(cards[i].id);
            } else {
                result.push_back(cards[i + 1].id);
            }
        } else {
            result.push_back(cards[i].id);
        }
    }

    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}