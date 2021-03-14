#include <iostream>

using namespace std;

int main()
{
	cout << "Hello, Ivan! Enter '1' to check your email from Yahor" << endl;
	char run;
	cin >> run;
	while (run != '1') {
		cout << "Your life is all about to read emails from Yahor. ENTER 1 or DIE!" << endl;
		cin >> run;
	}
	cout << "How are you?" << endl;
	string first_name;
	cout << "Ivan, enter the name of the recipient" << endl;
	cin >> first_name;
	cout << "I'm fine, " << first_name << ". I miss you. Thank you for helpping such booby with his mistakes <3" << "\n";
	string friend_name;
	cout << "Please, enter the name of a friend you want to know if " << first_name << " saw lately" << endl;
	cin >> friend_name;
	cout << "Please, enter 'm' if the friend is male and 'f' if the friend is female" << endl;
	char friend_sex; 
	cin >> friend_sex;
	while (friend_sex != 'm' and 'f') {
		cout << "You enter wrong symbol. Please, enter 'm' if the friend is male and 'f' if the friend is female" << endl;
		cin >> friend_sex;
	}
	if (friend_sex == 'm')
		cout << "If you see " << friend_name << " please ask him to call me" << endl;
	if (friend_sex == 'f')
		cout << "If you see " << friend_name << " please ask her to call me" << endl;
	int friend_age;
	cout << "Please, enter friend's age." << endl;
	cin >> friend_age;
	if (friend_age < 12)
		cout << "Next year you will be " << friend_age + 1 << endl;
	if (friend_age == 17)
		cout << "Next year you will be able to vote." << endl;
	if (friend_age > 70)
		cout << "Hope you are enojoing retirement!" << endl;
	cout << "Your's sincerely\n" << endl << "Ivan";
}