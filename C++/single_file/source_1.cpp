#include<iostream>

using namespace std;

typedef unsigned long ULONG;
typedef unsigned short USHORT;


class Part {
public:
	Part():itsPartNumber(1){}
	Part(ULONG PartNumber):itsPartNumber(PartNumber){}
	virtual ~Part() {};
	ULONG GetPartNumber() const { return itsPartNumber; }
	virtual void Display() const = 0;
private:
	ULONG itsPartNumber;
};


void Part::Display() const {
	cout << "\nPart Number: " << itsPartNumber << endl;
}



class CarPart : public Part {
public:
	CarPart():itsModelYear(94){}
	CarPart(USHORT year, ULONG partNumber);
	virtual void Display() const {
		Part::Display(); cout << "Model Year: ";
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
	AirPlanePart():itsEngineNumber(1){}
	AirPlanePart(USHORT EngineNumer, ULONG PartNumber);
	virtual void Display() const {
		Part::Display(); cout << "Engine No.: ";
		cout << itsEngineNumber << endl;
	}
private:
	USHORT itsEngineNumber;
};

AirPlanePart::AirPlanePart(USHORT EngineNumber, ULONG PartNumber):
	itsEngineNumber(EngineNumber),
	Part(PartNumber)
{}




class PartNode {
public:
	PartNode(Part*);
	~PartNode();
	void SetNext(PartNode* node) { itsNext = node; }
	PartNode* GetNext() const;
	Part* GetPart() const;
private:
	Part* itsPart;
	PartNode* itsNext;
};

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

PartNode * PartNode::GetNext() const {
	return itsNext;
}

Part * PartNode::GetPart() const {

	if (itsPart)
		return itsPart;
	else
		return NULL;
}


class PartsList {
public:
	PartsList();
	~PartsList();
	Part* Find(ULONG& position, ULONG PartNumber) const;
	ULONG GetCount() const { return itsCount; }
	Part* GetFirst() const;
	static PartsList& GetGlobalPartsList() {
		return GlobalPartsList;
	}
	void Insert(Part*);
	void Iterate(void (Part::*f)() const) const;
	Part* operator[](ULONG) const;
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


Part* PartsList::Find(ULONG& position, ULONG PartNumber) const {

	PartNode* pNode = 0;
	for (pNode = pHead, position = 0;
		pNode != NULL;
		pNode = pNode->GetNext(), position++) {

		if (pNode->GetPart()->GetPartNumber() == PartNumber)
			break;

		if (pNode == NULL)
			return NULL;
		else
			return pNode->GetPart();
	}
}

void PartsList::Iterate(void (Part::*func)() const) const {
	
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

	if (pHead->GetPart()->GetPartNumber() > New) {
		pNode->SetNext(pHead);
		pHead = pNode;
		return;
	}


	for (;;) {
		if (!pCurrent->GetNext()) {
			pCurrent->SetNext(pNode);
			return;
		}

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


int main() {

	PartsList pl = PartsList::GetGlobalPartsList();
	Part* pPart = 0;
	ULONG PartNumber;
	USHORT value;
	ULONG choice;

	while (1) {

		cout << "(0)Quit (1)Car (2)Plane: ";
		cin >> choice;

		if (!choice)
			break;

		cout << "New PartNumber?: ";
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
		pl.Insert(pPart);
	}
	void(Part::*pFunc)() const = &Part::Display;
	pl.Iterate(pFunc);


	return 0;
}