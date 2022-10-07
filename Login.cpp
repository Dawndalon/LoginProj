#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool IsLoggedIn()
{

	string username, password, un, pv; 
	cout << "Enter Username: "; 
	cin >> username;
	cout << "Enter Password: "; 
	cin >> password;

	ifstream read("data\\" + username + ".txt");
	getline(read, un);
	getline(read, pv);

	if (un == username && pv == password){
		return true; 
	}
	else{
		return false;
	}
}


int main(){
	int passLength;
	int choice; 
	cout << "Welcome:)" << endl << "Menu: "<< endl; 
	cout << "1: Register for new account" << endl;
	cout << "2: Already have an account? Log in" << endl; 
	cin >> choice;

	if (choice == 1){

		string username, password;
		cout << "Create your username: ";
		cin >> username;
		cout << "\nCreate your password ( Has to be at least 8 characters long) : ";
		cin >> password;
		passLength = password.length();
		
		while (passLength < 8){
		cout << "Password is too short. Try again: ";
		cin >> password; 
		passLength = password.length();
		}
        cout << endl;
        
		ofstream file;
		file.open("data\\" + username + ".txt");
		file << username << endl << password; 
		file.close();
		main();
	}
	else if (choice == 2){
		bool status = IsLoggedIn();

		if (!status){

			cout << "False Login!" << endl;
			system("PAUSE");
			return 0;
		}
		else{
			cout << "Successfully Logged In!" << endl;
			system("PAUSE");
			return 1;
		}

	}


}
