#include "Subscriber.h"

Subscriber::Subscriber()
{
}

Subscriber :: Subscriber(const char* nameUs, const char* surnameUs, const char* patronUs){
	
	setName(nameUs);
	setSurname(surnameUs);
	setPatronymic(patronUs);

}
Subscriber :: Subscriber(const char* nameUs, const char* surnameUs, const char* patronUs, const char* hPhone){

	setName(nameUs);
	setSurname(surnameUs);
	setPatronymic(patronUs);
	setHomePhone(hPhone);
}
Subscriber :: Subscriber(const char* nameUs, const char* surnameUs, const char* patronUs, const char* hPhone, const char* wPhone){

	setName(nameUs);
	setSurname(surnameUs);
	setPatronymic(patronUs);
	setHomePhone(hPhone);
	setWorkPhone(wPhone);
}
Subscriber :: Subscriber(const char* nameUs, const char* surnameUs, const char* patronUs, const char* hPhone, const char* wPhone, const char* mPhone){
	
	setName(nameUs);
	setSurname(surnameUs);
	setPatronymic(patronUs);
	setHomePhone(hPhone);
	setWorkPhone(wPhone);
	setMobilePhone(mPhone);
}
Subscriber :: Subscriber(const char* nameUs, const char* surnameUs, const char* patronUs, const char* hPhone, const char* wPhone, const char* mPhone, const char* aInfo){

	setName(nameUs);
	setSurname(surnameUs);
	setPatronymic(patronUs);
	setHomePhone(hPhone);
	setWorkPhone(wPhone);
	setMobilePhone(mPhone);
	setAdditInfo(aInfo);
}

Subscriber::~Subscriber()
{
	if (name != nullptr)
	{
		delete[] name;
	}
	if (surname != nullptr)
	{
		delete[] surname;
	}
	if (patronymic != nullptr)
	{
		delete[] patronymic;
	}
}

void Subscriber :: setName(const char* nameUs) {

	delete[] name;
	name = new char[strlen(nameUs) + 1];
	strcpy_s(name, strlen(nameUs) + 1, nameUs);
}
void Subscriber :: setSurname(const char* surnameUs){
	delete[] surname;
	surname = new char[strlen(surnameUs) + 1];
	strcpy_s(surname, strlen(surnameUs) + 1, surnameUs);
}
void Subscriber :: setPatronymic(const char*patromUs){
	delete[] patronymic;
	patronymic = new char[strlen(patromUs) + 1];
	strcpy_s(patronymic, strlen(patromUs) + 1, patromUs);
}
void Subscriber :: setHomePhone(const char* hPhone){
	strcpy_s(homePhone, strlen(hPhone) + 1, hPhone);
}
void Subscriber :: setWorkPhone(const char* wPhone){
	strcpy_s(workPhone, strlen(wPhone) + 1, wPhone);
}
void Subscriber :: setMobilePhone(const char* mPhone){
	strcpy_s(mobilePhone, strlen(mPhone) + 1, mPhone);
}
void Subscriber :: setAdditInfo(const char* aInfo){
	strcpy_s(additInfo, strlen(aInfo) + 1, aInfo);
}



