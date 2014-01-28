#include "gtksnowloadcountassistant.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[])
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "com.adequatech.snowloadcount");
  gtkSnowLoadCountAssistant window;
  return app->run(window);
}
