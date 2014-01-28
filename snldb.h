#ifndef SNLDB_H
#define SNLDB_H

#include <iostream>
#include <map>
#include <list>
#include <string>
#include <iomanip>
#include <ctime>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace std;
using namespace boost::posix_time;

#define SHIFTSTARTTIME "shiftstarttime"
#define SHIFTENDTIME "shiftendtime"
#define SHIFTSTARTDATE "shiftstartdate"
#define GUARDNAME "guardname"
#define LICENSENUMBER "licensenumber"
#define SHIFTCOMMENT "shiftcomment"
#define COUNTLOCATION "countlocation"
#define COUNTFORITEMTYPE "countforitemtype"
#define SINGLEAXLE "singleaxle"
#define TANDEMAXLE "tandem2axle"
#define TRIPLEAXLE "tripleaxle"
#define COMBOTRUCK "combotruck"
#define SEMITRAILER "semitrailer"

class SNLDB
{

public:
  SNLDB();
  ~SNLDB();

  void testSetAndGetDataFields();

  std::string getShiftStartTime();
  std::string getShiftEndTime();
  std::string getShiftStartDate();
  std::string getGuardName();
  std::string getLicenseNumber();
  std::string getShiftComment();
  std::string getCountLocation();
  std::string getCountForItemType();

  void setShiftStartTime(std::string s);
  void setShiftEndTime(std::string s);
  void setShiftStartDate(std::string s);
  void setGuardName(std::string s);
  void setLicenseNumber(std::string s);
  void setShiftComment(std::string s);
  void setCountLocation(std::string s);
  void setCountForItemType(std::string s);

  int getSingleAxleTotal();
  int getTandemAxleTotal();
  int getTripleAxleTotal();
  int getComboTruckTotal();
  int getSemiTrailerTotal();
  void singleAxleArrived();
  void tandemAxleArrived();
  void tripleAxleArrived();
  void comboTruckArrived();
  void semiTrailerArrived();
  void save(std::string filename_);
  void clear();
  void load(std::string filename_);
  
private:
  typedef std::map<std::string, std::string> TStrStrMap;
  typedef std::pair<std::string, std::string> TStrStrPair;

  TStrStrMap snlMap;
  
  typedef std::list<ptime> TtmList;
  TtmList singleL; //single axle date/time-stamps
  TtmList tandemL; //tandem axle date/time-stamps
  TtmList tripleL; //triple axle date/time-stamps
  TtmList comboL; //combo truck date/time-stamps
  TtmList semiL; //semi-trailer date/time-stamps
};

#endif // SNLDB_H
