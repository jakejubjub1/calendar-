#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

class Location {

  public:
    Location();
    Location(string locname, double locx, double locy);
    string getName();
    double getX();
    double getY();
    void setName(string locname);
    void setX(double locx);
    void setY(double locy);
    double findDistance(Location l1, Location l2);

  private:
    string name;
    double x;
    double y;

};

Location::Location() {

  name = "";
  x = 0;
  y = 0;

}

Location::Location(string locname, double locx, double locy) {

  name = locname;
  x = locx;
  y = locy;

}

string Location::getName() {
  return name;
}

double Location::getX() {
  return x;
}

double Location::getY() {
  return y;
}

void Location::setName(string locname) {
  this->name = locname;
}

void Location::setX(double locx) {
  this->x = locx;
}

void Location::setY(double locy) {
  this->y = locy;
}

double findDistance(Location l1, Location l2) {

  double u, v, distance;
  u = l2.getX() - l1.getX();
  v = l2.getY() - l1.getY();

  distance = sqrt((u * u) + (v * v));
  return distance;

}

int main() {

  Location loc("Marston", 5, 5);
  Location loc2("Library West", 2, 8);

  cout << loc.getName() << " ";
  cout << "(x, y): (" << loc.getX() << ", " << loc.getY() << ")" << endl;

  cout << loc2.getName() << " ";
  cout << "(x, y): (" << loc2.getX() << ", " << loc2.getY() << ")" << endl;

  double distance = 0;
  distance = findDistance(loc, loc2);

  cout << "The distance between " << loc.getName() << " and " << loc2.getName() << " is: " << distance << endl;

  return 0;
}



