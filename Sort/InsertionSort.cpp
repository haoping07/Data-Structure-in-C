#include <iostream>
#include <vector>
using namespace std;

/*
 Insertion Sort
 T: O(n^2)
 S: O(1)

*/

void InsertionSort(vector<int> &cards)
{
    int j = 0;

    // Scan the unsorted elements from head
    for (int i = 1; i < cards.size(); i++)
    {
        j = i - 1;

        // Record the new card
        int newCard = cards[i];

        // If the new card value is smaller then the previous card
        while (j >= 0 && newCard <= cards[j])
        {
            // Swap them
            cards[j + 1] = cards[j];
            j--;
        }

        // or insert to the position
        cards[j + 1] = newCard;
    }
}

int main()
{
    vector<int> cards{9, 1, 8, 2, 7, 6, 5, 4, 2, 3, 5, 8, 3, 9, 3, 1};
    int size = cards.size();

    InsertionSort(cards);

    for (int i = 0; i < size; i++)
    {
        cout << cards[i] << " ";
    }
    return 0;
}
