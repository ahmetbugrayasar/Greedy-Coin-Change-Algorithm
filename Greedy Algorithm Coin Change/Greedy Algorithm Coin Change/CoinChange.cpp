#include <stdio.h>
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
//This is a c++ file to calculate the amount of coins it can be transformed into.
//It uses Greedy Algorithm.
bool isZero(int i) //This is to check if we have any zeroes in our vectors
{
	return i == 0;
}
int MinCoinExchange(vector<int>& coins, int amount) {
	sort(coins.begin(), coins.end(), greater<int>()); //Sorting our piggy banks
	int n = coins.size(); // Giving n the value of size of our piggy banks

	//printf("%d",n); //This is to test if we got the sizes right

	vector <int> reqcoin(amount + 1);//A vector to dynamically pull required coins.
	for (int i = 0;i < n;i++)
	{
		while (amount >= coins[i])
		{
			amount -= coins[i];
			reqcoin.push_back(coins[i]);
		}
	}
	//using our bool function above, we see if there are any zeroes in our required coins bank. 
	vector<int>::iterator newIter = std::remove_if(reqcoin.begin(), reqcoin.end(), isZero);
	reqcoin.resize(newIter - reqcoin.begin());
	return reqcoin.size();
} //end-MinCoinExchange
int main()
{
	vector<int> coins = { 5, 1, 25, 10,100 };
	int amount;
	int noCoins;
	cout << "Enter the amount: " << endl;
	cin >> amount;
	noCoins= MinCoinExchange(coins, amount);
	cout<<"Minimum amount of coins required is: "<<noCoins<<endl;
}