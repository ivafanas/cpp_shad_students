#pragma once

#include <QWidget>

class QLabel;
class QLineEdit;


class SalesmanWidget : public QWidget
{
    Q_OBJECT

public:
    SalesmanWidget();

public slots:
    void on_start();
    void on_stop();
    void on_progress();

private:
    QLineEdit* cities_count_edit;
    QLineEdit* thread_count_edit;
    QLabel* model_status_label;
    QLabel* progress_status_label;
};

