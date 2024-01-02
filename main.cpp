#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	cout << "******************************" << endl;
	cout << "* Welcome to the Guess Game! *" << endl;
	cout << "******************************" << endl
			 << endl;

	srand(time(NULL));
	const int SECRET_NUMBER = rand() % 100;
	const int GUESS_ATTEMPTS_LIMIT = 5;
	int guess, guess_attempts = 1;
	double points = 1000.0;

	while (true)
	{
		cout << "Number of attempts: " << guess_attempts << " of " << GUESS_ATTEMPTS_LIMIT << endl;
		cout << "Guess a number (between 0 and 100): ";
		cin >> guess;
		cout << endl;

		bool correct_guess = guess == SECRET_NUMBER;
		bool guess_higher = guess > SECRET_NUMBER;
		bool reached_attempts_limit = guess_attempts == GUESS_ATTEMPTS_LIMIT;
		double lost_points = abs(guess - SECRET_NUMBER) / (double)2;
		points -= lost_points;

		if (correct_guess)
		{
			cout << "Congratulations! You guessed correctly the secret number in "
					 << guess_attempts << (guess_attempts == 1 ? " attempt!" : " attempts!") << endl;
			cout.precision(2);
			cout << fixed;
			cout << "Total points: " << points << endl;
			break;
		}
		else if (guess_higher)
		{
			cout << "Your guess is higher than the secret number!" << endl;
		}
		else
		{
			cout << "Your guess is lower than the secret number!" << endl;
		}

		if (reached_attempts_limit)
		{
			cout << "You lost the game! The secret number was " << SECRET_NUMBER << endl;
			cout.precision(2);
			cout << fixed;
			cout << "Total points: " << points << endl;
			break;
		}

		guess_attempts++;
	}

	return 0;
}
