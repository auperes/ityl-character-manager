#include "q_custom_gui_application.h"

#include <iostream>

#ifdef Q_QDOC
QCustomGuiApplication::QCustomGuiApplication(int& argc, char** argv)
    :QGuiApplication(argc, argv)
{

}
#else
QCustomGuiApplication::QCustomGuiApplication(int& argc, char** argv, int flags)
    : QGuiApplication(argc, argv, flags)
{

}
#endif



bool QCustomGuiApplication::notify(QObject* object, QEvent* event)
{
    try
    {
        return QGuiApplication::notify(object, event);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() <<std::endl;
        return false;
    }
}
