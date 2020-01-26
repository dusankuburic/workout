#include<list>
#include<string>
#include<iostream>

using namespace std;


template<typename T>
void displayAsContents(const T& container) {

	for (auto element = container.cbegin();
		element != container.cend();
		++element) {
		cout << *element << endl;
	}
	cout << endl;
}



struct ContactItem {

	string name;
	string phone;
	string displayAs;

	ContactItem(const string& conName, const string& conNum) {
		name = conName;
		phone = conNum;
		displayAs = (name + ": " + phone);
	}

	//used by list::remove() given contact list item
	bool operator==(const ContactItem& itemToCompare) const {
		return(itemToCompare.name == this->name);
	}

	//used by list::sort() without parameters
	bool operator<(const ContactItem& itemToCompare) const {
		return (this->name < itemToCompare.name);
	}

	//used in displayAsContents via cout
	operator const char*() const {
		return displayAs.c_str();
	}
};

bool SortOnphoneNumber(const ContactItem& item1, const ContactItem& item2) {
	return(item1.phone < item2.phone);
}


int main() {

	list<ContactItem> contacts;

	contacts.push_back(ContactItem("Jack Welsch", "+35345345345"));
	contacts.push_back(ContactItem("Dusan Kuburic", "+35345345345"));
	contacts.push_back(ContactItem("Jovan Benak", "+35345345345"));
	contacts.push_back(ContactItem("Igor Kretov", "+35345345345"));
	contacts.push_back(ContactItem("Lazar Benak", "+35345345345"));

	cout << "List in initial order: " << endl;
	displayAsContents(contacts);

	contacts.sort();
	cout << "Sorting in alphabetical order via operator<:" << endl;
	displayAsContents(contacts);

	contacts.sort(SortOnphoneNumber);
	cout << "Sorting in order of phone numbers via predicate: " << endl;
	displayAsContents(contacts);

	cout << "Erasing Jovan from the list: " << endl;
	contacts.remove(ContactItem("Jovan Benak", ""));
	displayAsContents(contacts);

	return 0;
}