#include <iostream>
#include <queue>
#include <bitset>
using namespace std;
bitset<3200> tab;
int getNum(int k) {
	int num = 0;
	for (int j = 2; j < 3200 && j < k; j++) {
		if (tab[j] == 0 && k % j == 0) {
			while (k % j == 0)
				k /= j;
			num++;
			if (k == 1) break;
		}
	}
	if (k == 1)
		return num;
	else if (num == 0)
		return 0;
	else
		return num + 1;
}
class MyLess {
public:
	bool operator() (pair<int, int> a, pair<int, int> b) {
		int num1 = a.first, num2 = a.first;
		if (num1 < num2)
			return true;
		else if (num1 == num2)
			return a < b;
		else
			return false;
	}
};
class MyGreater {
public:
	bool operator() (pair<int, int> a, pair<int, int> b) {
		int num1 = a.first, num2 = a.first;
		if (num1 > num2)
			return true;
		else if (num1 == num2)
			return a > b;
		else
			return false;
	}
};
int main() {
    
	for (int i = 0; i < 3200; i++)
		tab[i] = 0;
	tab[0] = tab[1] = 1;
	for (int i = 2; i < 3200; i++) {
		if (!tab[i])
			for (int j = i + i; j < 3200; j += i)
				tab[j] = 1;
	}
	int num = 0;
	priority_queue<int, vector<pair<int, int> >, MyLess> pq1;
	priority_queue<int, vector<pair<int, int> >, MyGreater> pq2;
	cin >> num;
	while (num--) {
		int tmp = 0;
		for (int t = 0; t < 10; t++) {
			cin >> tmp;
			pq1.push(make_pair(getNum(tmp), tmp));
			pq2.push(make_pair(getNum(tmp), tmp));
		}
		cout << pq1.top().second << " " << pq2.top().second << endl;
		pq1.pop();
		pq2.pop();
	}
	return 0;
}