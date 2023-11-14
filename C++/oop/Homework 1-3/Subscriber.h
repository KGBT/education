#pragma once
#include <iostream>
class Subscriber
{
private:
	char* name = new char [2] {"-"};
	char* surname = new char [2] {"-"};
	char* patronymic = new char [2] {"-"}; //отчество
	char homePhone[15] = { "-" };
	char workPhone[15] = { "-" };
	char mobilePhone[15] = { "-" };
	char additInfo[200] = { "-" };

public:
	Subscriber();
	Subscriber(const char*, const char*, const char*);
	Subscriber(const char*, const char*, const char*, const char*);
	Subscriber(const char*, const char*, const char*, const char*, const char*);
	Subscriber(const char*, const char*, const char*, const char*, const char*, const char*);
	Subscriber(const char*, const char*, const char*, const char*, const char*, const char*, const char*);

	~Subscriber();

	void setName(const char*);
	void setSurname(const char*);
	void setPatronymic(const char*);
	void setHomePhone(const char*);
	void setWorkPhone(const char*);
	void setMobilePhone(const char*);
	void setAdditInfo(const char*);
	// в классе реализованные геттеры будут являться inline
	char* getName() {
		return name;
	}
	char* getSurname() {
		return surname;
	}
	char* getPatronymic() {
		return patronymic;
	}
	char* getHomePhome() {
		return homePhone;
	}
	char* getWorkPhone() {
		return workPhone;
	}
	char* getMobilePhone() {
		return mobilePhone;
	}
	char* getAdditInfo() {
		return additInfo;
	}

};

