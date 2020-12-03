#include <iostream>
#include <vector>
#include <iterator>
#include <random>
using namespace std;

template <typename RandomAccessIterator, typename Predicate>
void BozoSort(RandomAccessIterator begin, RandomAccessIterator end,
	Predicate p) {
	std::random_device rd;
	std::mt19937 generator(rd());
	while (!std::is_sorted(begin, end, p)) {
		std::shuffle(begin, end, generator);
	}
}

template <typename RandomAccessIterator>
void BozoSort(RandomAccessIterator begin, RandomAccessIterator end) {
	BozoSort(
		begin, end,
		std::less<
		typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

int main() {
	int n = 0;
	std::vector<int> array{};
	cin >> n;
	array.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
	BozoSort(std::begin(array), std::end(array));
	cout << endl << endl;
	for (int i = 0; i < n; i++) {
		cout << array[i] << endl;
	}

}