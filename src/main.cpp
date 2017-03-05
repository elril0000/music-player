#include <iostream>
#include <QApplication>

#include "mainwin.hpp"
#include "config.hpp"

int main(int argc, char *argv[])
{
	std::cout << NAME << " v" << VERSION << std::endl;
	QApplication app(argc, argv);

	MainWin w;
	w.show();

	return app.exec();
}

