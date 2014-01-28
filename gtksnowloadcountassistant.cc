#include <iostream>
#include <assert.h>
#include <fstream>
#include "gtksnowloadcountassistant.h"

gtkSnowLoadCountAssistant::gtkSnowLoadCountAssistant()
  :
  isLoadedReport(false),
  _page1Box(Gtk::ORIENTATION_VERTICAL, 12),
  b0(Gtk::ORIENTATION_HORIZONTAL, 12),
  b1(Gtk::ORIENTATION_HORIZONTAL, 12),
  b2(Gtk::ORIENTATION_HORIZONTAL, 12),
  b3(Gtk::ORIENTATION_HORIZONTAL, 12),
  b4(Gtk::ORIENTATION_HORIZONTAL, 12),
  b5(Gtk::ORIENTATION_HORIZONTAL, 12),
  b6(Gtk::ORIENTATION_HORIZONTAL, 12),
  _openReportButton("Open report"),
  _shiftStartTimeLabel("Shift Start Time:"),
  _shiftEndTimeLabel("Shift End Time:"),
  _shiftStartDateLabel("Shift Start Date:"),
  _guardNameLabel("Guard Name:"),
  _guardLicenseNumberLabel("Guard License #:"),
  _guardShiftCommentsLabel("Shift Comments:"),
  _page2Box(Gtk::ORIENTATION_VERTICAL, 12),
  _page2frame("Counting At Location:"),
  b7(Gtk::ORIENTATION_VERTICAL, 12),
  _conroyRadio("Conroy"),
  _michaelRadio("Micheal"),
  _strandherdRadio("Strandherd"),
  _innesRadio("Innes"),
  _clydeRadio("Clyde"),
  _page3Box(Gtk::ORIENTATION_VERTICAL, 12),
  _page3frame("Counting Totals For:"),
  b8(Gtk::ORIENTATION_VERTICAL, 12),
  _passesRadio("Passes"),
  _ticketsRadio("Tickets"),
  _page4Box(Gtk::ORIENTATION_VERTICAL, 12),
  _page4frame("Truck Type Count"),
  b9(Gtk::ORIENTATION_VERTICAL, 12),
  b10(Gtk::ORIENTATION_HORIZONTAL, 12),
  b11(Gtk::ORIENTATION_HORIZONTAL, 12),
  b12(Gtk::ORIENTATION_HORIZONTAL, 12),
  b13(Gtk::ORIENTATION_HORIZONTAL, 12),
  b14(Gtk::ORIENTATION_HORIZONTAL, 12),
  _singleaxlebutton("singleaxle"),
  _tandemaxlebutton("tandemaxle"),
  _tripleaxlebutton("tripleaxle"),
  _combotruckbutton("combotruck"),
  _semitrailerbutton("semitrailer"),
  _singleLabel("0"),
  _tandemLabel("0"),
  _tripleLabel("0"),
  _comboLabel("0"),
  _semiLabel("0")
{
  set_title("snowloadcountassistant");
  set_border_width(12);
  set_default_size(400, 300);

  b0.pack_start(_openReportButton);
  b0.pack_start(_filenameEntry);
  _page1Box.pack_start(b0);

  b1.pack_start(_shiftStartTimeLabel);
  b1.pack_start(_shiftStartTimeEntry);
  _page1Box.pack_start(b1);

  b2.pack_start(_shiftEndTimeLabel);
  b2.pack_start(_shiftEndTimeEntry);
  _page1Box.pack_start(b2);

  b3.pack_start(_shiftStartDateLabel);
  b3.pack_start(_shiftStartDateEntry);
  _page1Box.pack_start(b3);

  b4.pack_start(_guardNameLabel);
  b4.pack_start(_guardNameEntry);
  _page1Box.pack_start(b4);

  b5.pack_start(_guardLicenseNumberLabel);
  b5.pack_start(_guardLicenceNumberEntry);
  _page1Box.pack_start(b5);

  b6.pack_start(_guardShiftCommentsLabel);
  b6.pack_start(_guardShiftCommentsEntry);
  _page1Box.pack_start(b6);

  append_page(_page1Box);
  set_page_title(*get_nth_page(0), "Guard Shift");
  set_page_complete(_page1Box, true);
  set_page_type(_page1Box, Gtk::ASSISTANT_PAGE_CONFIRM);

  Gtk::RadioButton::Group group = _conroyRadio.get_group();
  _michaelRadio.set_group(group);
  _strandherdRadio.set_group(group);
  _innesRadio.set_group(group);
  _clydeRadio.set_group(group);

  _page2Box.pack_start(_page2frame);
  b7.pack_start(_conroyRadio);
  b7.pack_start(_michaelRadio);
  b7.pack_start(_strandherdRadio);
  b7.pack_start(_innesRadio);
  b7.pack_start(_clydeRadio);
  _page2frame.add(b7);
  append_page(_page2Box);
  set_page_title(*get_nth_page(1), "Site Info");
  set_page_complete(_page2Box, true);
  set_page_type(_page2Box, Gtk::ASSISTANT_PAGE_CONFIRM);

  Gtk::RadioButton::Group group2 = _passesRadio.get_group();
  _ticketsRadio.set_group(group2);
  _page3Box.pack_start(_page3frame);
  b8.pack_start(_passesRadio);
  b8.pack_start(_ticketsRadio);
  _page3frame.add(b8);
  append_page(_page3Box);
  set_page_title(*get_nth_page(2), "Site Info(cont)");
  set_page_complete(_page3Box, true);
  set_page_type(_page3Box, Gtk::ASSISTANT_PAGE_CONFIRM);

  _page4Box.pack_start(_page4frame);
  b10.pack_start(_singleaxlebutton);
  b10.pack_start(_singleLabel);
  b9.pack_start(b10);
  b11.pack_start(_tandemaxlebutton);
  b11.pack_start(_tandemLabel);
  b9.pack_start(b11);
  b12.pack_start(_tripleaxlebutton);
  b12.pack_start(_tripleLabel);
  b9.pack_start(b12);
  b13.pack_start(_combotruckbutton);
  b13.pack_start(_comboLabel);
  b9.pack_start(b13);
  b14.pack_start(_semitrailerbutton);
  b14.pack_start(_semiLabel);
  b9.pack_start(b14);
  _page4frame.add(b9);
  append_page(_page4Box);
  set_page_title(*get_nth_page(3), "Truck Type Count");
  set_page_complete(_page4Box, true);
  set_page_type(_page4Box, Gtk::ASSISTANT_PAGE_CONFIRM);
  
  _openReportButton.signal_clicked().connect(sigc::mem_fun(*this, &gtkSnowLoadCountAssistant::on_openreport_clicked));
  _singleaxlebutton.signal_clicked().connect(sigc::mem_fun(*this, &gtkSnowLoadCountAssistant::on_singleaxle_clicked));
  _tandemaxlebutton.signal_clicked().connect(sigc::mem_fun(*this, &gtkSnowLoadCountAssistant::on_tandemaxle_clicked));
  _tripleaxlebutton.signal_clicked().connect(sigc::mem_fun(*this, &gtkSnowLoadCountAssistant::on_tripleaxle_clicked));
  _combotruckbutton.signal_clicked().connect(sigc::mem_fun(*this, &gtkSnowLoadCountAssistant::on_combotruck_clicked));
  _semitrailerbutton.signal_clicked().connect(sigc::mem_fun(*this, &gtkSnowLoadCountAssistant::on_semitrailer_clicked));

  signal_apply().connect( sigc::mem_fun(*this, &gtkSnowLoadCountAssistant::on_assistant_apply) );
  signal_cancel().connect( sigc::mem_fun(*this, &gtkSnowLoadCountAssistant::on_assistant_cancel) );
  signal_close().connect( sigc::mem_fun(*this, &gtkSnowLoadCountAssistant::on_assistant_close) );
  signal_prepare().connect( sigc::mem_fun(*this, &gtkSnowLoadCountAssistant::on_assistant_prepare) );
  show_all_children();
}

gtkSnowLoadCountAssistant::~gtkSnowLoadCountAssistant()
{
}

void gtkSnowLoadCountAssistant::on_assistant_apply()
{
  cout << "current snlwiz page:" << get_current_page() << std::endl;
  switch (get_current_page())
    {
    case 0:
      d.setShiftStartTime(_shiftStartTimeEntry.get_text());
      d.setShiftEndTime(_shiftEndTimeEntry.get_text());
      d.setShiftStartDate(_shiftStartDateEntry.get_text());
      d.setGuardName(_guardNameEntry.get_text());
      d.setLicenseNumber(_guardLicenceNumberEntry.get_text());
      d.setShiftComment(_guardShiftCommentsEntry.get_text());
      break;
    case 1:
      d.setCountLocation(getCountLocation());
      break;
    case 2:
      d.setCountForItemType(getCountForItemType());
      break;
    case 3:
      break;
      default:
	break;
    }
}

std::string gtkSnowLoadCountAssistant::getCountLocation()
{
  std::string selectedRadio;  
  if(_conroyRadio.get_active())
    selectedRadio = _conroyRadio.get_label();

  if(_michaelRadio.get_active())
    selectedRadio = _michaelRadio.get_label();

  if(_strandherdRadio.get_active())
    selectedRadio = _strandherdRadio.get_label();

  if(_innesRadio.get_active())
    selectedRadio = _innesRadio.get_label();

  if(_clydeRadio.get_active())
    selectedRadio = _clydeRadio.get_label();

  return std::string(selectedRadio);
}

std::string gtkSnowLoadCountAssistant::getCountForItemType()
{
  std::string selectedRadio;  
  if(_passesRadio.get_active())
    selectedRadio = _passesRadio.get_label();

  if(_ticketsRadio.get_active())
    selectedRadio = _ticketsRadio.get_label();

  return std::string(selectedRadio);
}

void gtkSnowLoadCountAssistant::on_assistant_cancel()
{
  hide();
}

void gtkSnowLoadCountAssistant::on_assistant_close()
{
  if(isLoadedReport == false)
    {
      cout << "saving new report" << std::endl;
      saveReport();
    }
  else
    {
      cout << "this is a report that was opened for viewing only. not saving." << std::endl;
    }

  hide();
}

void gtkSnowLoadCountAssistant::on_assistant_prepare(Gtk::Widget* /* widget */)
{
  set_title(Glib::ustring::compose("gtksnowloadcount (Page %1 of %2)", get_current_page() + 1, get_n_pages()));
}

void gtkSnowLoadCountAssistant::on_openreport_clicked()
{
  openReport(_filenameEntry.get_text());
}

void gtkSnowLoadCountAssistant::on_singleaxle_clicked()
{
  d.singleAxleArrived();
  int t = d.getSingleAxleTotal();
  std::string s = std::to_string(t);
  _singleLabel.set_text(s);
}

void gtkSnowLoadCountAssistant::on_tandemaxle_clicked()
{
  d.tandemAxleArrived();
  int t = d.getTandemAxleTotal();
  std::string s = std::to_string(t);
  _tandemLabel.set_text(s);
}

void gtkSnowLoadCountAssistant::on_tripleaxle_clicked()
{
  d.tripleAxleArrived();
  int t = d.getTripleAxleTotal();
  std::string s = std::to_string(t);
  _tripleLabel.set_text(s);
}

void gtkSnowLoadCountAssistant::on_combotruck_clicked()
{
  d.comboTruckArrived();
  int t = d.getComboTruckTotal();
  std::string s = std::to_string(t);
  _comboLabel.set_text(s);
}

void gtkSnowLoadCountAssistant::on_semitrailer_clicked()
{
  d.semiTrailerArrived();
  int t = d.getSemiTrailerTotal();
  std::string s = std::to_string(t);
  _semiLabel.set_text(s);
}


void gtkSnowLoadCountAssistant::saveReport()
{
  std::string s;
  ptime t(second_clock::local_time());
  s = to_iso_string(t);
  s = "snowloadcount" + s + ".txt";
  d.save(s);
}

void gtkSnowLoadCountAssistant::openReport(std::string filename_)
{
  d.load(filename_);
  isLoadedReport = true;
  loadedReportFilename = filename_;
  loadReportDataIntoGui();
}

void gtkSnowLoadCountAssistant::loadReportDataIntoGui()
{
  _shiftStartTimeEntry.set_text(d.getShiftStartTime());
  _shiftEndTimeEntry.set_text(d.getShiftEndTime());
  _shiftStartDateEntry.set_text(d.getShiftStartDate());
  _guardNameEntry.set_text(d.getGuardName());
  _guardLicenceNumberEntry.set_text(d.getLicenseNumber());
  _guardShiftCommentsEntry.set_text(d.getShiftComment());
  setActiveCountLocation(d.getCountLocation());
  setActiveCountForItemType(d.getCountForItemType());
  _singleLabel.set_text(std::to_string(d.getSingleAxleTotal()));
  _tandemLabel.set_text(std::to_string(d.getTandemAxleTotal()));
  _tripleLabel.set_text(std::to_string(d.getTripleAxleTotal()));
  _comboLabel.set_text( std::to_string(d.getComboTruckTotal()));
  _semiLabel.set_text(  std::to_string(d.getSemiTrailerTotal()));

  // disable all the fields after filling them/changing them while in loaded report mode.
  _shiftStartTimeEntry.set_sensitive(false);
  _shiftEndTimeEntry.set_sensitive(false);
  _shiftStartDateEntry.set_sensitive(false);
  _guardNameEntry.set_sensitive(false);
  _guardLicenceNumberEntry.set_sensitive(false);
  _guardShiftCommentsEntry.set_sensitive(false);
  
  _conroyRadio.set_sensitive(false);
  _michaelRadio.set_sensitive(false);
  _strandherdRadio.set_sensitive(false);
  _innesRadio.set_sensitive(false);
  _clydeRadio.set_sensitive(false);
  
  _passesRadio.set_sensitive(false);
  _ticketsRadio.set_sensitive(false);

  _singleaxlebutton.set_sensitive(false);
  _tandemaxlebutton.set_sensitive(false);
  _tripleaxlebutton.set_sensitive(false);
  _combotruckbutton.set_sensitive(false);
  _semitrailerbutton.set_sensitive(false);
}

void gtkSnowLoadCountAssistant::setActiveCountLocation(std::string countLocation_)
{
  if( countLocation_ == "Conroy")
    {
      _conroyRadio.set_active(true);
    }

  if ( countLocation_ == "Micheal")
    {
      _michaelRadio.set_active(true);
    }

  if ( countLocation_ == "Strandherd")
    {
      _strandherdRadio.set_active(true);
    }

  if ( countLocation_ == "Innes")
    {
      _innesRadio.set_active(true);
    }

  if (countLocation_ == "Clyde")
    {
      _clydeRadio.set_active(true);
    }
}

void gtkSnowLoadCountAssistant::setActiveCountForItemType(std::string countForItemType_)
{
  if(countForItemType_ == "Passes")
    {
      _passesRadio.set_active(true);
    }
  
  if(countForItemType_ == "Tickets")
    {
      _ticketsRadio.set_active(true);
    }
}
