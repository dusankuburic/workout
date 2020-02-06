#include<set>
#include<iostream>
#include<string>

using namespace std;


template<typename T>
void DisplayContents(const T& container) {

	for (auto iElement = container.cbegin();
		iElement != container.cend();
		++iElement) {
		cout << *iElement << endl;
	}
	cout << endl;
}


struct ContactItem {

	string name;
	string phoneNum;
	string displayAs;

	ContactItem(const string& nameInit, const string& phone) {

		name = nameInit;
		phoneNum = phone;
		displayAs = (name + ": " + phoneNum);
	}


	bool operator==(const ContactItem& itemToCompare) const {
		return (itemToCompare.name == this->name);
	}

	bool operator<(const ContactItem& itemToCompare) const {
		return (this->name < itemToCompare.name);
	}

	operator const char*() const {
		return displayAs.c_str();
	}
};


int main() {

	set<ContactItem> setContacts;
	setContacts.insert(ContactItem("Jack Welsch", "+7454654648"));
	setContacts.insert(ContactItem("Jovan Benak", "+7454654648"));
	setContacts.insert(ContactItem("Dusan Kuburic", "+7454654648"));
	setContacts.insert(ContactItem("Igor Kretov", "+7454654648")); 
	setContacts.insert(ContactItem("Ana Dimitrijevic", "+7454654648"));
	setContacts.insert(ContactItem("Uros Kovacevic", "+7454654648"));
	DisplayContents(setContacts);

	cout << "Enter a name you wish to delete: ";
	string inputName;
	getline(cin, inputName);

	auto contactFound = setContacts.find(ContactItem(inputName, ""));

	if (contactFound != setContacts.end()) {

		setContacts.erase(contactFound);
		cout << "Displaying contents after erasing " << inputName << endl;
		DisplayContents(setContacts);
	}
	else {
		cout << "Contact not found" << endl;
	}


	return 0;
}