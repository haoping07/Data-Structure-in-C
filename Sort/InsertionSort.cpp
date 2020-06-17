#include <iostream>
#include <vector>
using namespace std;

class InsertionSort
{
private:
    vector<int> cards;
    int size;

public:
    InsertionSort(vector<int> &cards, int size) : cards(cards), size(size)
    {
        int j = 0;
        for (int i = 1; i < size; i++)
        {
            j = i - 1;
            int newCard = cards[i];
            while (j >= 0 && newCard <= cards[j])
            {
                cards[j + 1] = cards[j];
                j--;
            }
            cards[j + 1] = newCard;
        }
    }
};

int main()
{
    vector<int> cards{9, 1, 8, 2, 7, 6, 5, 4, 2, 3, 5, 8, 3, 9, 3, 1};
    int size = cards.size();

    InsertionSort(cards, size);

    for (int i = 0; i < size; i++)
    {
        cout << cards[i] << " ";
    }
    return 0;
}