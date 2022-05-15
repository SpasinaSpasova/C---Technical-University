// Facebook.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
class Profile {
	char firstName[50];
	char lastName[50];
	int countOfFriends;
	Profile* friendsArr[200];
	char isVisible[20];
	char ofOrOnLine[10];
public:
	Profile();
	Profile(char const* fname, char const* lname);
	void changeAcces();
	void printProfile();
	int Add(Profile* friendtoAdd);
	Profile Search(char const* fname, char const* lname);
};
Profile::Profile() {
	countOfFriends = 0;
}
Profile::Profile(char const* fname, char const* lname) {
	countOfFriends = 0;
	strcpy_s(firstName, fname);
	strcpy_s(lastName, lname);
	strcpy_s(isVisible, "Visible");
	strcpy_s(ofOrOnLine, "Online");
}
void Profile::changeAcces() {
	if (!strcmp(isVisible, "Visible")) {
		strcpy_s(isVisible, "Not Visible");
	}
	else {
		strcpy_s(isVisible, "Visible");
	}
}
void Profile::printProfile() {
	if (isVisible) {
		printf("%s %s friends: %d %s %s\n", firstName, lastName, countOfFriends, isVisible, ofOrOnLine);
	}
	else {
		printf("%s %s friends: %d %s %s\n", firstName, lastName, countOfFriends, isVisible, ofOrOnLine);
	}

	if (countOfFriends==0)
	{
		printf("%s %s has no friends!\n",firstName,lastName);
	}
	else {
		for (int i = 0; i < countOfFriends; i++)
		{
			printf("%s %s\n",friendsArr[i]->firstName ,friendsArr[i]->lastName );

			if (!strcmp(friendsArr[i]->isVisible,"Visible"))
			{
				Profile tmp = *friendsArr[i];
				for (int j = 0; j <tmp.countOfFriends ; j++)
				{
					printf("	-%s %s\n", tmp.friendsArr[j]->firstName, tmp.friendsArr[j]->lastName);
				}
			}
			
		}
	}
}
int Profile::Add(Profile* friendtoAdd) {
	if (countOfFriends >= 200) {
		return 0;
	}
	else {
		friendsArr[countOfFriends] = friendtoAdd;
		countOfFriends++;
		return 1;
	}
}
Profile Profile::Search(char const* fname, char const* lname) {
	for (int i = 0; i < countOfFriends; i++)
	{
		if (!strcmp(friendsArr[i]->firstName, fname)
			&& !strcmp(friendsArr[i]->lastName, lname)) {
			return *friendsArr[i];
		}
	}
	
}


int main()
{
	Profile myprofile("Spasina", "Spasova");
	//myprofile.printProfile();

	//myprofile.changeAcces();
	//myprofile.printProfile();
	
	Profile fr("Vesa", "Spasova");
	myprofile.Add(&fr);

	/*Profile scndprf("Milka", "Nikolova");
	fr.Add(&scndprf);*/
	Profile srch= myprofile.Search("Vesa", "Spasova");
	srch.printProfile();
	//myprofile.printProfile();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
