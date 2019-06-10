#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define NUMBER_OF_SAME_TYPE_CHARS 3

// Actual flyweight objects class (delcaration)
class FlyweightCaracter;

// FlyweightCharacterAbstractBuilder is a class holding the properties which are shared by many objects. So instead of keeping these properties in those objects we keep them externally, making objects flyweight. See more details in the comments of main function.

class FlyweightCharacterAbstractBuilder {
public:
  FlyweightCharacterAbstractBuilder() = delete;
  ~FlyweightCharacterAbstractBuilder() = delete;
  static void setFontsAndNames();
  static FlyweightCaracter createFlyweightCharacter(unsigned short fontSizeIndex, unsigned short fontNameIndex, unsigned short positionInStream);

  static vector<float> fontSizes; // lets imagine that sizes may be of floating point type
  static vector<string> fontNames; // font name may be of variable length (lets take 6 bytes is average)
};

vector<float> FlyweightCharacterAbstractBuilder::fontSizes(3);
vector<string> FlyweightCharacterAbstractBuilder::fontNames(3);

void FlyweightCharacterAbstractBuilder::setFontsAndNames() {
  fontSizes[0] = 1.0;
  fontSizes[1] = 1.5;
  fontSizes[2] = 2.0;

  fontNames[0] = "first_font";
  fontNames[1] = "second_font";
  fontNames[2] = "third_font";
}

class FlyweightCaracter {
public:
  FlyweightCaracter(unsigned short fontSizeIndex, unsigned short fontNameIndex, unsigned short positionInStream)
    : fontSizeIndex(fontSizeIndex),
      fontNameIndex(fontNameIndex),
      positionInStream(positionInStream) {}

  ~FlyweightCaracter() {}

  void print() {
    cout << "Font Size: " << FlyweightCharacterAbstractBuilder::fontSizes[fontSizeIndex]
	 << ", font Name: " << FlyweightCharacterAbstractBuilder::fontNames[fontNameIndex]
	 << ", character stream position: " << positionInStream << endl;
  }

private:
  unsigned short fontSizeIndex;	// index instead of actual font size
  unsigned short fontNameIndex;	// index instead of font name
  unsigned short positionInStream;
};

FlyweightCaracter FlyweightCharacterAbstractBuilder::createFlyweightCharacter(unsigned short fontSizeIndex, unsigned short fontNameIndex, unsigned short positionInStream) {
  FlyweightCaracter fc(fontSizeIndex, fontNameIndex, positionInStream);
  return fc;
}

int main() {
  vector<FlyweightCaracter> chars;

  FlyweightCharacterAbstractBuilder::setFontsAndNames();
  unsigned short limit(NUMBER_OF_SAME_TYPE_CHARS);

  for (unsigned short i(0); i < limit; ++i) {
    chars.push_back(FlyweightCharacterAbstractBuilder::createFlyweightCharacter(0, 0, i));
    chars.push_back(FlyweightCharacterAbstractBuilder::createFlyweightCharacter(1, 1, i + 1 * limit));
    chars.push_back(FlyweightCharacterAbstractBuilder::createFlyweightCharacter(2, 2, i + 2 * limit));
  }

  // Each char stores links to its fontName and fontSize so what we get is:

  // each object instead of allocating 6 bytes (convention above) for string and 4 bytes for float allocates 2 bytes for fontNameIndex and fontSizeIndex.

  // That means for each char we save 6 + 4 - 2 - 2 = 6 bytes.
  // Now imagine we have NUMBER_OF_SAME_TYPE_CHARS = 1000 i.e. with our code we will have 3 groups of chars with 1000 chars in each group which will save us
  // 3 * 1000 * 6 - (3 * 6 + 3 * 4) = 17970 saved bytes.

  // 3 * 6 + 3 * 4 is a number of bytes allocated by FlyweightCharacterAbstractBuilder.

  // So the idea of the pattern is to move properties shared by many objects to some external container. The objects in that case don't sotre the data themselves, they sotre only links to the data which saves memory and make the objects lighter. The data size of properties stored externally may be significant which will save REALLY huge ammount of memory and will make each object super light in comparison to its counterpart. That's where the name of the pattern comes from: flyweight (i.e. very light).

  for (unsigned short i(0); i < chars.size(); ++i)
    chars[i].print();

  cin.get();

  return EXIT_SUCCESS;
}
