#pragma once

#include <QWidget>

class QCheckBox;
class QLineEdit;


class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget();

public slots:
    void on_relaunch();

private:
    QCheckBox* enable_throttling_checkbox;
    QLineEdit* thread_count_edit;
};

