#include <iostream>
//melhoria com relaçāo a pesquisa binária
//verifica o valor no índice do meio
//os limites da matriz devem ser classificados
//grande O de n seria o pior caso
//a fórmula usada é início + n - início / o elemento


using namespace std;
int interpolationSearch(int array[], int start, int end, int key) {
    int dist, valRange, indexRange, approximation;
    float portion;
    while(start <= end && key >= array[start] && key <= array[end]) {
        dist = key - array[start];
        valRange = array[end] - array[start];
        portion = dist / valRange;
        indexRange = end - start;
        aproximation = start + (portion * indexRange);
        if(array[aproximation] == key)
            return aproximation;
        if(array[aproximation] < key)
            start = aproximation +1;
        else
            end = aproximation - 1;
    }
    return -1;
}
int main() {
    int n, searchKey, loc;
    cout << "Enter number of items: ";
    cin >> n;
    int arr[n];
    cout << "Enter items: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter search key to search in the list: ";
    cin >> searchKey;
    if ((loc = interpolationSearch(arr, 0, n - 1, searchKey)) >= 0)
        cout << "Item found at location: " << loc << endl;
    else
        cout << "Item is not found in the list." << endl;
}