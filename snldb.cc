#include <boost/format.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/archive/text_oarchive.hpp> 
#include <boost/archive/text_iarchive.hpp> 
#include <map>
#include <list>
#include <string>
#include <iomanip>
#include <ctime>
#include <fstream> 
#include <sstream>
#include <iostream>
#include "snldb.h"

using namespace boost::posix_time;
using namespace std;

SNLDB::SNLDB()
{
}

SNLDB::~SNLDB()
{
}

void SNLDB::testSetAndGetDataFields()
{
  setShiftStartTime("b");
  setShiftEndTime("c");
  setShiftStartDate("d");
  setGuardName("e");
  setLicenseNumber("f");
  setShiftComment("g");
  setCountLocation("h");
  setCountForItemType("i");
  singleAxleArrived();
  tandemAxleArrived();
  tandemAxleArrived();
  tripleAxleArrived();
  tripleAxleArrived();
  tripleAxleArrived();
  comboTruckArrived();
  comboTruckArrived();
  comboTruckArrived();
  comboTruckArrived();
  semiTrailerArrived();
  semiTrailerArrived();
  semiTrailerArrived();
  semiTrailerArrived();
  semiTrailerArrived();
  std::cout << getShiftStartTime() << std::endl;
  std::cout << getShiftEndTime() << std::endl;
  std::cout << getShiftStartDate() << std::endl;
  std::cout << getGuardName() << std::endl;
  std::cout << getLicenseNumber() << std::endl;
  std::cout << getShiftComment() << std::endl;
  std::cout << getCountLocation() << std::endl;
  std::cout << getCountForItemType() << std::endl;
  std::cout  << "single total:" << getSingleAxleTotal() << std::endl;
  std::cout  << "tandem total:" << getTandemAxleTotal() << std::endl;
  std::cout  << "triple total:" << getTripleAxleTotal() << std::endl;
  std::cout  << "combo total:"  << getComboTruckTotal() << std::endl;
  std::cout  << "semi total:" << getSemiTrailerTotal() << std::endl;
}
      
void SNLDB::setShiftStartTime(std::string s)
{
  snlMap[SHIFTSTARTTIME] = s;
  std::cout  << "Shift Start Time:" << snlMap[SHIFTSTARTTIME] << std::endl;
}  

std::string SNLDB::getShiftStartTime()
{
  return std::string(snlMap[SHIFTSTARTTIME]);
}  

 void SNLDB::setShiftEndTime(std::string s)
{
  snlMap[SHIFTENDTIME] = s;
  std::cout  << "Shift End Time:" << snlMap[SHIFTENDTIME] << std::endl;
}

std::string SNLDB::getShiftEndTime()
{
  return std::string(snlMap[SHIFTENDTIME]);
}

 void SNLDB::setShiftStartDate(std::string s)
{
  snlMap[SHIFTSTARTDATE] = s;
  std::cout  << "Shift Start Date:" << snlMap[SHIFTSTARTDATE] << std::endl;
}

std::string SNLDB::getShiftStartDate()
{
  return std::string(snlMap[SHIFTSTARTDATE]);
}

 void SNLDB::setGuardName(std::string s)
{
  snlMap[GUARDNAME] = s;
  std::cout  << "Guard Name:" << snlMap[GUARDNAME] << std::endl;
}

std::string SNLDB::getGuardName()
{
  return std::string(snlMap[GUARDNAME]);
}

 void SNLDB::setLicenseNumber(std::string s)
{
  snlMap[LICENSENUMBER] = s;
  std::cout  << "Guard License#:" << snlMap[LICENSENUMBER] << std::endl;
}

std::string SNLDB::getLicenseNumber()
{
  return std::string(snlMap[LICENSENUMBER]);
}

 void SNLDB::setShiftComment(std::string s)
{
  snlMap[SHIFTCOMMENT] = s;
  std::cout  << "Shift Comment:" << snlMap[SHIFTCOMMENT] << std::endl;
}

std::string SNLDB::getShiftComment()
{
  return std::string(snlMap[SHIFTCOMMENT]);
}

 void SNLDB::setCountLocation(std::string s)
{
  snlMap[COUNTLOCATION] = s;
  std::cout  << "Location:" << snlMap[COUNTLOCATION] << std::endl;
}

std::string SNLDB::getCountLocation()
{
  return std::string(snlMap[COUNTLOCATION]);
}

 void SNLDB::setCountForItemType(std::string s)
{
  snlMap[COUNTFORITEMTYPE] = s;
  std::cout  << "Counting totals for:" << snlMap[COUNTFORITEMTYPE] << std::endl;
}

std::string SNLDB::getCountForItemType()
{
  return std::string(snlMap[COUNTFORITEMTYPE]);
}

int SNLDB::getSingleAxleTotal()
{
  return singleL.size();
}

int SNLDB::getTandemAxleTotal()
{
  return tandemL.size();
}

int SNLDB::getTripleAxleTotal()
{
  return tripleL.size();
}

int SNLDB::getComboTruckTotal()
{
  return comboL.size();
}

int SNLDB::getSemiTrailerTotal()
{
  return semiL.size();
}

void SNLDB::singleAxleArrived()
{
  ptime t(second_clock::local_time());
  singleL.push_back(t);
}

void SNLDB::tandemAxleArrived()
{
  ptime t(second_clock::local_time());
  tandemL.push_back(t);
}

void SNLDB::tripleAxleArrived()
{
  ptime t(second_clock::local_time());
  tripleL.push_back(t);
}

void SNLDB::comboTruckArrived()
{
  ptime t(second_clock::local_time());
  comboL.push_back(t);
}

void SNLDB::semiTrailerArrived()
{
  ptime t(second_clock::local_time());
  semiL.push_back(t);
}

void SNLDB::save(std::string filename_) 
{ 
  std::ofstream file(filename_); 
  boost::archive::text_oarchive oa(file);
  std::string s;
  s = getShiftStartTime();
  oa & s; 
  s = getShiftEndTime();
  oa & s; 
  s = getShiftStartDate();
  oa & s; 
  s = getGuardName();
  oa & s; 
  s = getLicenseNumber();
  oa & s; 
  s = getShiftComment();
  oa & s; 
  s = getCountLocation();
  oa & s; 
  s = getCountForItemType();
  oa & s; 

  s = std::to_string(getSingleAxleTotal());
  oa & s; 
  std::list<ptime>::iterator iterSingle;
  for (iterSingle = singleL.begin(); iterSingle != singleL.end(); ++iterSingle) {
    ptime myt = *iterSingle;
    s = to_iso_string(myt);
    oa & s;
  }

  s = std::to_string(getTandemAxleTotal());
  oa & s;
  std::list<ptime>::iterator iterTandem;
  for (iterTandem = tandemL.begin(); iterTandem != tandemL.end(); ++iterTandem) {
    ptime myt = *iterTandem;
    s = to_iso_string(myt);
     oa & s;
  }

  s = std::to_string(getTripleAxleTotal());
  oa & s; 
  std::list<ptime>::iterator iterTriple;
  for (iterTriple = tripleL.begin(); iterTriple != tripleL.end(); ++iterTriple) {
    ptime myt = *iterTriple;
    s = to_iso_string(myt);
     oa & s;
  }

  s = std::to_string(getComboTruckTotal());
  oa & s;
  std::list<ptime>::iterator iterCombo;
  for (iterCombo = comboL.begin(); iterCombo != comboL.end(); ++iterCombo) {
    ptime myt = *iterCombo;
    s = to_iso_string(myt);
     oa & s;
  }

  s = std::to_string(getSemiTrailerTotal());
  oa & s; 
  std::list<ptime>::iterator iterSemi;
  for (iterSemi = semiL.begin(); iterSemi != semiL.end(); ++iterSemi) {
    ptime myt = *iterSemi;
    s = to_iso_string(myt);
     oa & s;
  }
} 

void SNLDB::clear()
{
  snlMap.clear();
  singleL.clear();
  tandemL.clear();
  tripleL.clear();
  comboL.clear();
  semiL.clear();
}

void SNLDB::load(std::string filename_) 
{ 
  clear();
  std::ifstream file(filename_); 
  boost::archive::text_iarchive ia(file); 
  std::string s;
  int c;
  ptime inPtime;
  ia >> s;
  setShiftStartTime(s);
  ia >> s;
  setShiftEndTime(s);
  ia >> s;
  setShiftStartDate(s);
  ia >> s;
  setGuardName(s);
  ia >> s;
  setLicenseNumber(s);
  ia >> s;
  setShiftComment(s);
  ia >> s;
  setCountLocation(s);
  ia >> s;
  setCountForItemType(s);

  ia >> s;
  c = std::stoi(s);
  //singleL.clear();
  for(int c2=0; c2 < c; c2++)
    {
      ia >> s;
      inPtime = from_iso_string(s);
      singleL.push_back(inPtime);
    }

  ia >> s;
  c = std::stoi(s);
  //tandemL.clear();
  for(int c2=0; c2 < c; c2++)
    {
      ia >> s;
      inPtime = from_iso_string(s);
      tandemL.push_back(inPtime);
    }

  ia >> s;
  c = std::stoi(s);
  //tripleL.clear();
  for(int c2=0; c2 < c; c2++)
    {
      ia >> s;
      inPtime = from_iso_string(s);
      tripleL.push_back(inPtime);
    }

  ia >> s;
  c = std::stoi(s);
  //comboL.clear();
  for(int c2=0; c2 < c; c2++)
    {
      ia >> s;
      inPtime = from_iso_string(s);
      comboL.push_back(inPtime);
    }

  ia >> s;
  c = std::stoi(s);
  //semiL.clear();
  for(int c2=0; c2 < c; c2++)
    {
      ia >> s;
      inPtime = from_iso_string(s);
      semiL.push_back(inPtime);
    }
}
