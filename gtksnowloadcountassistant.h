#ifndef SNOWLOADCOUNTASSISTANT_H
#define SNOWLOADCOUNTASSISTANT_H

#include <gtkmm.h>
#include <gtkmm/box.h>
#include "snldb.h"

class gtkSnowLoadCountAssistant : public Gtk::Assistant
{
public:
  gtkSnowLoadCountAssistant();
  virtual ~gtkSnowLoadCountAssistant();

private:
  // Signal handlers:
  void on_assistant_apply();
  void on_assistant_cancel();
  void on_assistant_close();
  void on_assistant_prepare(Gtk::Widget* widget);

  void on_openreport_clicked();
  void on_singleaxle_clicked();
  void on_tandemaxle_clicked();
  void on_tripleaxle_clicked();
  void on_combotruck_clicked();
  void on_semitrailer_clicked();

  // Member functions:
  void print_status();
  std::string getCountLocation();
  std::string getCountForItemType();
  void saveReport();
  void openReport(std::string filename_);
  void loadReportDataIntoGui();
  void setActiveCountLocation(std::string countLocation_);
  void setActiveCountForItemType(std::string countForItemType_);

  // new page 1
  Gtk::Box _page1Box;
  Gtk::Button _openReportButton;
  Gtk::Entry _filenameEntry;
  Gtk::Box b0, b1, b2, b3, b4, b5, b6;
  Gtk::Label _shiftStartTimeLabel;
  Gtk::Entry _shiftStartTimeEntry;
  Gtk::Label _shiftEndTimeLabel;
  Gtk::Entry _shiftEndTimeEntry;
  Gtk::Label _shiftStartDateLabel;
  Gtk::Entry _shiftStartDateEntry;
  Gtk::Label _guardNameLabel;
  Gtk::Entry _guardNameEntry;
  Gtk::Label _guardLicenseNumberLabel;
  Gtk::Entry _guardLicenceNumberEntry;
  Gtk::Label _guardShiftCommentsLabel;
  Gtk::Entry _guardShiftCommentsEntry;

  // new page 2
  Gtk::Box _page2Box;
  Gtk::Frame _page2frame;
  Gtk::Box b7;
  Gtk::RadioButton _conroyRadio, _michaelRadio, _strandherdRadio, _innesRadio, _clydeRadio;

  // new page 3
  Gtk::Box _page3Box;
  Gtk::Frame _page3frame;
  Gtk::Box b8;
  Gtk::RadioButton _passesRadio, _ticketsRadio;

  // new page 4
  Gtk::Box _page4Box;
  Gtk::Frame _page4frame;
  Gtk::Box b9, b10, b11, b12, b13, b14;
  Gtk::Button _singleaxlebutton;
  Gtk::Button _tandemaxlebutton;
  Gtk::Button _tripleaxlebutton;
  Gtk::Button _combotruckbutton;
  Gtk::Button _semitrailerbutton;
  Gtk::Label _singleLabel;
  Gtk::Label _tandemLabel;
  Gtk::Label _tripleLabel;
  Gtk::Label _comboLabel;
  Gtk::Label _semiLabel;

  SNLDB d;
  bool isLoadedReport;
  std::string loadedReportFilename;
};

#endif /* SNOWLOADCOUNTASSISTANT_H */
