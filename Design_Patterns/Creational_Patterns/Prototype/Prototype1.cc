#include <iostream>
#include <unordered_map>
// #include <map>
#include <string>

using namespace std;

typedef enum {
  CAR,
  BIKE,
  PERSON
} RECORD_TYPE;

namespace std {
  template<>
  struct hash<RECORD_TYPE> {
    typedef RECORD_TYPE argument_type;
    typedef size_t result_type;

    result_type operator()(argument_type const &s) const {
      return hash<int>()(static_cast<int>(s));
    }
  };
}

class Record {
public:
  Record() {}

  virtual ~Record() {}

  virtual Record * clone() = 0;

  virtual void print() = 0;
};

class CarRecord : public Record {
public:
  CarRecord(const string &carName, int ID)
    : m_carName(carName),
      m_ID(ID) {}

  CarRecord(const CarRecord &other)
    : Record(other) {		// call the base default copy constructor
    m_carName = other.m_carName;
    m_ID = other.m_ID;
  }

  ~CarRecord() {}

  Record * clone() {
    return new CarRecord(*this);
  }

  void print() {
    cout << "Car Record" << endl
	 << "Name   : " << m_carName << endl
	 << "Number : " << m_ID << endl;
  }

private:
  string m_carName;
  int m_ID;
};

class BikeRecord : public Record {
public:
  BikeRecord(const string &bikeName, int ID)
    : m_bikeName(bikeName),
      m_ID(ID) {}

  BikeRecord(const BikeRecord &other)
    : Record(other) {
    m_bikeName = other.m_bikeName;
    m_ID = other.m_ID;
  }

  ~BikeRecord() {}

  Record * clone() {
    return new BikeRecord(*this);
  }

  void print() {
    cout << "Bike Record" << endl
	 << "Name  : " << m_bikeName << endl
	 << "Number: " << m_ID << endl;
  }

private:
  string m_bikeName;
  int m_ID;
};

class PersonRecord : public Record {
public:
  PersonRecord(const string &personName, int age)
    : m_personName(personName),
      m_age(age) {}

  PersonRecord(const PersonRecord &other)
    : Record(other) {
    m_personName = other.m_personName;
    m_age = other.m_age;
  }

  ~PersonRecord() {}

  Record * clone() {
    return new PersonRecord(*this);
  }

  void print() {
    cout << "Person Record" << endl
	 << "Name : " << m_personName << endl
	 << "Age  : " << m_age << endl;
  }

private:
  string m_personName;
  int m_age;
};

class RecordFactory {
public:
  RecordFactory() {
    m_recordReference[CAR] = new CarRecord("Ferrari", 5050);
    m_recordReference[BIKE] = new BikeRecord("Yamaha", 2525);
    m_recordReference[PERSON] = new PersonRecord("Tom", 25);
  }

  ~RecordFactory() {
    delete m_recordReference[CAR];
    delete m_recordReference[BIKE];
    delete m_recordReference[PERSON];
  }

  Record * createRecord(RECORD_TYPE type) {
    return m_recordReference[type]->clone();
  }

private:
  unordered_map<RECORD_TYPE, Record *> m_recordReference;
  // map<RECORD_TYPE, Record *> m_recordReference;
};

int main() {
  RecordFactory *pRecordFactory = new RecordFactory;

  Record *pRecord;
  pRecord = pRecordFactory->createRecord(CAR);
  pRecord->print();
  delete pRecord;

  pRecord = pRecordFactory->createRecord(BIKE);
  pRecord->print();
  delete pRecord;

  pRecord = pRecordFactory->createRecord(PERSON);
  pRecord->print();
  delete pRecord;

  delete pRecordFactory;

  return EXIT_SUCCESS;
}
