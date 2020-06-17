#include <iostream>
#include <vector>
using namespace std;

/*
 Selection Sort
 T: O(n^2)
 O: O(1)
 
*/

void SelectionSort(vector<int> &cards)
{
    int size = cards.size();

    for (int i = 0; i < size; i++)
    {
        int min = i;

        // Scan the unsorted elements
        for (int j = i + 1; j < size; j++)
        {
            // Find the current smallest element
            if (cards[j] < cards[min])

                // Record the smallest element
                min = j;
        }

        // Swap them
        if (min != i)
        {
            int temp = cards[min];
            cards[min] = cards[i];
            cards[i] = temp;
        }
    }
}

int main()
{
    vector<int> cards{9, 1, 8, 2, 7, 3, 7, 3, 6, 4, 5, 3, 5, 8, 8, 7, 7, 8, 8, 8, 4, 5, 5};
    SelectionSort(cards);

    for (int i = 0; i < cards.size(); i++)
    {
        cout << cards[i] << " ";
    }
    return 0;
}