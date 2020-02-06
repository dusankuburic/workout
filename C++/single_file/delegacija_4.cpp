#include<iostream>

//NE RADI ISPRAVI GRESKE

using namespace std;

typedef unsigned long ULONG;
typedef unsigned short USHORT;


//Apstraknta osnovna klasa delova
class Part {
public:
	Part():itsPartNumber(1){}
	Part(ULONG PartNumber):
		itsPartNumber(PartNumber){}
	virtual ~Part(){}
	ULONG GetPartNumber() const {
		return itsPartNumber;
	}
	virtual void Display() const = 0;
private:
	ULONG itsPartNumber;
};


//implementacija ciste virtuelne funkcije tako da se 
//izvedena klasa moze nadovezati

void Part::Display() const {

	cout << "\nPart Number: " << itsPartNumber << endl;
}



class CarPart : public Part {
public:
	CarPart() :itsModelYear(94) {};
	CarPart(USHORT year, ULONG partNumber);
	virtual void Display() const {
		Part::Display();
		cout << "Model Year: ";
		cout << itsModelYear << endl;
	}
private:
	USHORT itsModelYear;
};

CarPart::CarPart(USHORT year, ULONG partNumber):
	itsModelYear(year),
	Part(partNumber)
{}



class AirPlanePart : public Part {
public:
	AirPlanePart() :itsEngineNumber(1) {};
	AirPlanePart(USHORT EngineNumber, ULONG PartNumber);
	virtual void Display() const{
		Part::Display();
		cout << "Engine No.: ";
		cout << itsEngineNumber << endl;
	}
private:
	USHORT itsEngineNumber;
};

AirPlanePart::AirPlanePart(USHORT EngineNumber, ULONG PartNumber):
	itsEngineNumber(EngineNumber), 
	Part(PartNumber){}




class PartNode {
public:
	PartNode(Part*);
	~PartNode();
	void SetNext(PartNode* node) {
		itsNext = node;
	}
	PartNode* GetNext() const;
	Part* GetPart() const;
private:
	Part* itsPart;
	PartNode* itsNext;
};

//PartNode implementacija

PartNode::PartNode(Part* pPart):
	itsPart(pPart),
	itsNext(0)
{}

PartNode::~PartNode() {
	delete itsPart;
	itsPart = 0;
	delete itsNext;
	itsNext = 0;
}

//Vraca NULL ako nema sledeceg PartNode
PartNode * PartNode::GetNext() const {
	return itsNext;
}

Part* PartNode::GetPart() const {
	if (itsPart)
		return itsPart;
	else
		return NULL;
}


class PartsList {
public:
	PartsList();
	~PartsList();
	// potreban konstruktor kopije i operator jednako!
	void Iterate(void (Part::*f)() const) const;
	Part* Find(ULONG& position, ULONG PartNumber) const;
	Part* GetFirst() const;
	void Insert(Part*);
	Part* operator[](ULONG) const;
	ULONG GetCount() const { return itsCount; }
	static PartsList& GetGlobalPartsList() {
		return GlobalPartsList;
	}
private:
	PartNode* pHead;
	ULONG itsCount;
	static PartsList GlobalPartsList;
};

PartsList PartsList::GlobalPartsList;

PartsList::PartsList():
	pHead(0),
	itsCount(0)
{}

PartsList::~PartsList() {
	delete pHead;
}

Part* PartsList::GetFirst() const {
	if (pHead)
		return pHead->GetPart();
	else
		return NULL;
}

Part* PartsList::operator[](ULONG offSet) const {

	PartNode* pNode = pHead;

	if (!pHead)
		return NULL;

	if (offSet > itsCount)
		return NULL;

	for (ULONG i = 0; i < offSet; i++)
		pNode = pNode->GetNext();

	return pNode->GetPart();
}

Part* PartsList::Find(
	ULONG& position,
	ULONG PartNumber) const {

	PartNode* pNode = 0;
	for (pNode = pHead, position = 0;
		pNode != NULL;
		pNode = pNode->GetNext(), position++) {

		if (pNode->GetPart()->GetPartNumber() == PartNumber)
			break;
	}
	if (pNode == NULL)
		return NULL;
	else
		return pNode->GetPart();
}


void PartsList::Iterate(void (Part::*func)()const) const {
	if (!pHead)
		return;
	PartNode* pNode = pHead;
	do
		(pNode->GetPart()->*func)();
	while (pNode = pNode->GetNext());
}

void PartsList::Insert(Part* pPart) {

	PartNode* pNode = new PartNode(pPart);
	PartNode* pCurrent = pHead;
	PartNode* pNext = 0;

	ULONG New = pPart->GetPartNumber();
	ULONG Next = 0;
	itsCount++;

	if (!pHead) {
		pHead = pNode;
		return;
	}

	//ako je ovaj manji od glave
	//ovaj je nova glava
	if (pHead->GetPart()->GetPartNumber() > New) {
		pNode->SetNext(pHead);
		pHead = pNode;
		return;
	}

	for (;;) {
		//ako nema sledeceg dodaj novi
		if (pCurrent->GetNext()) {
			pCurrent->SetNext(pNode);
			return;
		}

		//ako ovaj ide posle ovog i pre sledeceg
		// onda ga umetni ovde, inace uzmi sledeceg
		pNext = pCurrent->GetNext();
		Next = pNext->GetPart()->GetPartNumber();
		if (Next > New) {
			pCurrent->SetNext(pNode);
			pNode->SetNext(pNext);
			return;
		}
		pCurrent = pNext;
	}
}



class PartsCatalog {
public:
	void Insert(Part*);
	ULONG Exists(ULONG PartNumber);
	Part* Get(int PartNumber);
	void ShowAll() { thePartsList.Iterate(&Part::Display); }
private:
	PartsList thePartsList;
};


void PartsCatalog::Insert(Part* newPart) {
	
	ULONG partNumber = newPart->GetPartNumber();
	ULONG offset;

	if (!thePartsList.Find(offset, partNumber)) {
		thePartsList.Insert(newPart);
	}
	else {
		cout << partNumber << " was the ";
		switch (offset)
		{
		case 0: cout << "first "; break;
		case 1: cout << "second "; break;
		case 3: cout << "third "; break;
		default: cout << offset + 1 << "th";
		}
		cout << "entry. Rejected!\n";
	}
}

ULONG PartsCatalog::Exists(ULONG PartNumber) {
	ULONG offset;
	thePartsList.Find(offset, PartNumber);
	return offset;
}



Part* PartsCatalog::Get(int PartNumber) {

	ULONG offset;
	Part* thePart = thePartsList.Find(offset, PartNumber);
	return thePart;
}


int main() {

	PartsCatalog pc;
	Part* pPart = 0;
	ULONG PartNumber;
	USHORT value;
	ULONG choice;

	while (1) {
		cout << "(0)Quit (1)Car (2)Plane: ";
		cin >> choice;

		if (!choice)
			break;

		cout << "Ne PartNumber?: ";
		cin >> PartNumber;

		if (choice == 1) {
			cout << "Model Year?: ";
			cin >> value;
			pPart = new CarPart(value, PartNumber);
		}
		else {
			cout << "Engine Number?: ";
			cin >> value;
			pPart = new AirPlanePart(value, PartNumber);
		}
		pc.Insert(pPart);
	}
	pc.ShowAll();

	return 0;
}
