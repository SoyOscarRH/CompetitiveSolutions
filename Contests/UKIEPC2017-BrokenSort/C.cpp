#include <bits/stdc++.h>

using namespace std;


int main (void)
{
	ios_base::sync_with_stdio(0);
	std::ios::sync_with_stdio(0);
	cin.tie(0);

	map<string, int> values = {{"red", -1}, {"yellow", -1}, {"green", -1}, {"brown", -1}, {"blue", -1}, {"pink", -1}, {"black", -1}};
	map<string, int> table = {{"red", 1}, {"yellow", 2}, {"green", 3}, {"brown", 4}, {"blue", 5}, {"pink", 6}, {"black", 7}};
	vector<string> colors = {"red", "yellow", "green", "brown", "blue", "pink", "black"};
	int N = 0, maxC = 0, score = 0, flag = 0, tmp = 0;
	string aux, maxS;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> aux;
		if (aux != "red")
			flag = 1;
		values[aux]++;
	}

	for (int i = 0; i < 7; i++)
	{
		if (values[colors[i]] >= 0)
		{
			tmp++;
			maxC = max(maxC, table[colors[i]]);
			maxS = colors[i];
		}
	}

	if (values["red"] >= 0 && tmp == 2)
		flag = 2;

	if (values["red"] >= 0 && flag == 1)
	{
		score = (maxC * (values["red"] + 2)) + values["red"];
		for (int i = 0; i < 7; i++)
		{
			if (values[colors[i]] >= 0 && colors[i] != maxS)
				score += table[colors[i]];
		}
	}
	else
	{
		for (int i = 0; i < 7; i++)
		{
			if (values[colors[i]] >= 0)
				score += table[colors[i]];
		}
	}

	if (flag == 2)
		score = table[maxS] + values["red"] + 1;

	cout << score << endl;

}