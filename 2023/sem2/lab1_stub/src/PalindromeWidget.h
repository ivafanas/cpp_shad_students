#pragma once

#include <QWidget>

class QLabel;
class QLineEdit;


class PalindromeWidget : public QWidget
{
    Q_OBJECT

public:
    PalindromeWidget();

public slots:
    void on_start();
    void on_stop();
    void on_progress();
    void on_dump();

private:
    QLineEdit* str_len_edit_;
    QLineEdit* num_thr_edit_;
    QLabel* task_status_label_;
    QLabel* progress_status_label_;
};

