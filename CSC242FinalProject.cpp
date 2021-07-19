#include <iostream>
#include <string>
#include <array>

using namespace std;

int exitSequence(int e)
{

	if (e == 0)
	{
		cout << "Goodbye!" << endl;
		return -1;
	}
}

float selectWithdraw(int withBalance, int u)
{
	float w;
	cout << "Please enter amount to withdraw: " << endl;
	cin >> w;

	if (w > withBalance)
	{
		cout << "Insufficient Funds" << endl << "Your balance as of today is: " << withBalance << endl;
	}
	else
	{
		float newBalW;
		newBalW = withBalance - w;
		cout << "Your new balance is: " << newBalW << endl;
		return newBalW;
	}
}

float selectBalance(float balance, int& u)
{

	if (balance < 100)
	{
		cout << "\n" << "Low Balance" << endl;
		return 0;
	}
	cout << "\n" << "Your balance as of today is: " << balance << endl;
	return 0;
}

float selectDeposit(float balance)
{
	float d;

	for (int i = 0; i < 2; i++)
	{
		cout << "Please enter amount to deposit: " << endl;
		cin >> d;
		if (d < 0)
		{
			cout << "invalid amount" << endl;

		}
		else
		{
			float newBalD = d + balance;
			cout << "Your new balance is: " << newBalD << endl;
			return newBalD;
		}
	}
	return balance;

}

int loginSuccess(int& u)
{
	int a;
	float newBal;
	const int NUM_OF_USER = 10;
	float arrBal[NUM_OF_USER]{ 1000, 1000, 1000, 1000, 1000, 1000,1000, 1000, 1000, 1000 };
	bool invalidEntry = true;

	while (invalidEntry)
	{
		cout << "\n" << "Welcome " << u << "! Please Make a Selection: " << endl;
		cout << "2. Balance " << endl;
		cout << "3. Deposit " << endl;
		cout << "4. Withdraw " << endl;
		cout << "5. Log Off " << endl;
		cin >> a;

		switch (a)
		{
		case 2: selectBalance(arrBal[u], u);
			break;
		case 3: arrBal[u] = selectDeposit(arrBal[u]);
			break;
		case 4: arrBal[u] = selectWithdraw(arrBal[u], u);
			break;
		case 5: cout << "Goodbye!" << endl;
			return -1;
		}


	}
}

int signIn()
{
	int a;

	bool invalidEntry = true;

	while (invalidEntry)
	{
		const int USER_COUNT = 10;
		int arr[USER_COUNT]{ 0,1,2,3,4,5,6,7,8,9 };


		cout << "\n" << "Enter the number associated with your account: ";
		cin >> a;
		for (int i = 0; i < USER_COUNT; i++)
		{
			int r;
			int b;
			b = arr[i];
			if (a == b)
			{
				r = loginSuccess(b);
				if (r < 0)
				{
					return -1;
				}
			}
		}


		cout << "\n" << "Invalid entry" << endl;

	}
}




int main()
{
	int user;

	bool invalidEntry = true;

	while (invalidEntry)
	{
		int a;
		cout << "\n" << "Welcome to ATM powered by CSC 242" << endl;

		cout << "1. Sign In" << endl;
		cout << "2. Balance" << endl;
		cout << "3. Deposit" << endl;
		cout << "4. Withdraw" << endl;
		cout << "5. Exit" << endl;
		cout << "Press option 1 to Sign In ";
		cin >> a;

		if (a == 1)
		{
			int r;
			r = signIn();
			if (r < 0)
			{

			}
		}
		else if (a == 5)
		{
			exit(0);
		}

	}

	return 0;

}

