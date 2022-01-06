#pragma once

#include <QGuiApplication>

class QCustomGuiApplication : public QGuiApplication
{
    Q_OBJECT

public:
#ifdef Q_QDOC
    QCustomGuiApplication(int &argc, char **argv);
#else
    QCustomGuiApplication(int &argc, char **argv, int = ApplicationFlags);
#endif

    bool notify(QObject *, QEvent *) override;
};

